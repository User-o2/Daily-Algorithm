/*
https://www.luogu.com.cn/problem/P16237
补题-蓝桥杯2026 C++B组 G题
Gemini3.1Pro
dp+离散化+前缀和
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<ll> b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> b[i];

    vector<ll> d(n + 1);
    vector<int> pre(n + 1, 0);
    map<ll, vector<int>> k_pos;

    for (int i = 1; i <= n; ++i) 
	{
		//差值数组D_i
        d[i] = b[i] - a[i];
        
        // 预处理前缀和：pre[i] 维护 D_i == 0 的**数量**，用于快速计算损失
        if(d[i] == 0)
        	pre[i] = pre[i-1] + 1;
        else // 将非 0 差值视为补偿值 k，将其索引位置进行离散化归类
    	{
    		pre[i] = pre[i-1];
			k_pos[d[i]].push_back(i); //k->vector<int>{idx_k,...}
		}
    }

    // 全局最大净收益。如果所有操作的收益均为负，则不进行任何操作（净收益为 0）
    ll max_net_gain = 0; 

    // 遍历所有可能的温度补偿值 k 及其在原数组中对应的所有索引位置
    for (const auto& pair : k_pos) {
    	ll k = pair.first;
    	vector<int> pos = pair.second;
    	
        ll current_dp = 1; // 对应题解的 last，表示以当前位置 pos[i] 结尾的最大净收益
        ll max_k_gain = 1; // 记录当前特定补偿值 k 下能跑出的最大净收益

        // 对当前 k 的索引数组，进行 dp 算法的稀疏化状态转移
        for (int i = 1; i < pos.size(); ++i) {
            int p = pos[i];     // 当前 D_i = k 的原始索引
            int q = pos[i - 1]; // 前一个 D_i = k 的原始索引

            // 计算如果把操作区间从 q 延伸到 p，中间会破坏多少个原本完美的传感器
            int loss = pre[p] - pre[q];

            // 状态转移（核心逻辑）：
            // 选项 1 (1LL)：抛弃前面的区间，从当前位置 p 重新开始划定，此时净收益为自身带来的 1
            // 选项 2 (current_dp + 1 - loss)：将当前位置连入之前的区间，继承历史净收益，加上当前的 1，再扣除跨越区间引发的代价 loss
            current_dp = max(1LL, current_dp + 1 - loss);

            // 维护当前 k 的局部最优解
            max_k_gain = max(max_k_gain, current_dp);
        }
        
        // 用当前 k 的最优解去更新全局最优解
        max_net_gain = max(max_net_gain, max_k_gain);
    }

    // 最终答案 = 不做任何操作时的基础完美数量 + 最佳区域操作带来的最大净增加量
    cout << pre[n] + max_net_gain << "\n";
}

int main() {
    // 解绑输入输出流，加速大规模 I/O 读写，防止在 2e5 数据规模下 TLE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    // cin >> t; // 应对多组测试用例的常规预留
    while (t--) {
        solve();
    }
    return 0;
}