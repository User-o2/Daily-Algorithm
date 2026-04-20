/*
https://www.luogu.com.cn/problem/P16239
补题-蓝桥杯2026 C++B组 H题

算法标签：数学推导、优先队列
通过60%样例
*/
#include<iostream>
#include<queue>
#include<utility>
using namespace std;

const int N = 100010, mod = 998244353;
int a[N],b[N],k[N];
int n,m;
priority_queue<
	pair<double,int>, 
	vector<pair<double,int>>,
	greater<pair<double,int>>
	> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//所有的索引都是1-based 
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i] >> b[i];
		
		//堆初始化，使用小顶堆，每次找 a[i]/b[i]+k[i] 最小的值进行分配
		pq.push({(double)a[i]/b[i], i}); //初始ki=0
		//注意这里必须得使用double强制转换一下，不然int/int会截断为int
	}
	
	//模拟m次分配：时间复杂度瓶颈O(m·logn)
	for(int i = 0; i < m ; i ++)
	{
		auto p = pq.top(); pq.pop();
		pq.push({p.first+1,p.second});
		k[p.second] += 1;
	}
	
	//计算结果
	long long res = 1;
	for(int i = 0; i < n; i ++)
		res = res*(a[i]+(long long)k[i]*b[i]) % mod;
	cout << res << "\n";
	return 0;
}