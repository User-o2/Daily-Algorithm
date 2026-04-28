/*
https://www.luogu.com.cn/problem/P16237
补题-蓝桥杯2026 C++B组 G题

困难题：dp+离散化+前缀和
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

const int N = 200010;
int a[N],b[N],d[N]; //Ai,Bi,差值
int pre[N]; //维护d[i]==0的累加个数
map<int,vector<int>> pos; //离散化 k->k_pos{idx,...}
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	//所有的索引都是1-based
	for(int i = 1;i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	
	for(int i = 1; i <= n; i ++)
	{
		d[i] = b[i] - a[i]; //计算差距
		if(d[i] == 0) //本来就在理想温度
			pre[i] = pre[i-1] + 1; //维护d[i]==0的数量
		else //d[i]!=0
		{
			pre[i] = pre[i-1];
			//d[i]作为k，进行离散化的维护
			pos[d[i]].push_back(i); //k ->k_pos{...}
		}
	}
	
	int max_cnt = 0; //全局最大净收益
	
	//遍历每一个k，寻找最佳区间对应的最大收益
	for(auto ele : pos)
	{
		int k = ele.first;
		vector<int> k_pos = ele.second; //k对应的索引下标
		
		int cur_max_cnt = 1; //注意：当前k下的最大净收益应该为1（局部）
		int cur_dp = 1; //dp初始化
		
		//dp算法：最大字段和(遍历d[i]!=0的索引)
		for(int i = 1; i < k_pos.size(); i ++)
		{
			int l = k_pos[i-1], r = k_pos[i];
			
			//计算增补上k之后的损失。注意这里是l延伸到r，新增加的是[l+1,r]
			int loss = pre[r] - pre[l+1 - 1]; //[l+1,r]之间d[i]==0的个数
			
			//离散化为二元的关系
			cur_dp = max(1, cur_dp+1-loss);
			cur_max_cnt = max(cur_max_cnt,cur_dp);
		}
		max_cnt = max(max_cnt,cur_max_cnt);
	}
	//答案就是：原本是理想温度的+最大净收益
	//之前为什么减去损失呢：就是因为在这里计算的时候可以直接使用pre[n]进行最终的计算
	//因为[l,r]区间之外，仍然可能存在原本就处于理想温度的情况
	cout << pre[n] + max_cnt << "\n";
	return 0;
}