/*
https://www.luogu.com.cn/problem/P16237
补题-蓝桥杯2026 C++B组 F题

[DFS解法]
图论基础+贪心
*/
#include<iostream>
#include<vector>
using namespace std;

const int N = 100010;
int n,m;
vector<int> e[N];
int cnt; //联通块的个数
bool sta[N]; //是否被访问

void dfs(int u)
{
	for(auto ele : e[u]) //e[u]是一个vector
	{
		if(sta[ele] == false)
		{
			sta[ele] = true;
			dfs(ele);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	while(m --)
	{
		int a,b;
		cin >> a >> b;
		
		//双向存边
		e[a].push_back(b); //注意节点的编号是基于1的索引
		e[b].push_back(a);
	}
	
	//DFS遍历求解cnt的时间复杂度是O(n+2m)
	for(int i = 1; i <= n; i ++)
	{
		if(sta[i] == false)
		{
			cnt ++;
			sta[i] = true;
			dfs(i); //开始标记节点i所在的联通块
		}
	}
	//贪心（均摊）
	cout << cnt-1 << " " << (2*(cnt-1) + n-1)/n << "\n";
}