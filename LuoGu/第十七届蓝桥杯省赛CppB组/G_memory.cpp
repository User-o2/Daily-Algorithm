
/*
再写一遍-蓝桥杯2026 C++B组 G题
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

const int N = 200010;
int a[N],b[N],d[N];
int pre[N];
map<int,vector<int>> pos;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//1-based
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	
	for(int i = 1; i <= n; i ++)
	{
		d[i] = b[i] - a[i]; //计算差值，也就是补偿值k
		
		if(d[i] == 0) //本来就是理想温度
			pre[i] = pre[i-1] + 1;
		else //d[i]!=0，作为k进行维护
		{
			pre[i] = pre[i-1];
			//d[i]作为k，进行离散化的维护
			pos[d[i]].push_back(i); //k -> vector{pos_1, pos_2, ...}
		}
	}
	
	int max_cnt = 0; //全局最大净收益
	//遍历每一个k，寻找每一个k对应的最佳区间的最大净收益
	for(auto ele : pos)
	{
		int k = ele.first;
		vector<int> pos_k = ele.second;
		
		//原本是一维遍历O(N)，使用前缀和+离散化进行优化1,-1,0
		//1:补偿值为k，加上k之后，收益+1
		//-1:补偿值为0，也就是本来是理想温度，加上k之后造成破坏，收益-1
		//0:补偿值为其他数值，没有影响，收益不变
		//前缀和：快速计算损失（补偿值为0的数）；
		//离散化：提取出补偿值为k的数
		int cur_max_cnt = 1; //当前k下的局部净收益：最小净收益是1。因为一定可以找一个区间长度为1进行补偿（注意pos_k的d[i]均不为0，和map的性质有关）
		
		//dp算法
		int cur_dp = 1; //dp初始化
		for(int i = 1; i < pos_k.size(); i ++)
		{
			int r_pre = pos_k[i-1]; //之前区间的右端点
			int r = pos_k[i]; //扩展到新的右端点
			int loss = pre[r] - pre[r_pre+1 -1]; //[r_pre+1, r]
			//状态转移
			cur_dp = max(1, cur_dp+1-loss);
			cur_max_cnt = max(cur_max_cnt, cur_dp);
		}
		max_cnt = max(max_cnt,cur_max_cnt);
	}
	cout <<  pre[n] + max_cnt << endl;
	return 0;
}