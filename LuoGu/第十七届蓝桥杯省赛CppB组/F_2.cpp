/*
https://www.luogu.com.cn/problem/P16237
补题-蓝桥杯2026 C++B组 F题

[并查集解法]
图论基础+贪心
*/

#include<iostream>
using namespace std;

const int N = 100010;
int p[N]; //并查集的核心数据结构：p[i]表示i的父节点，i指向p[i]
int n,m;

int find(int x) //寻找x的祖宗节点+路径压缩
{
	if(x != p[x])
		p[x] = find(p[x]); //路径压缩
		
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//初始化并查集
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) //based-1
		p[i] = i;
	
	while(m --)
	{
		int a,b;
		cin >> a >> b;
		//将a和b合并
		p[find(a)] = find(b);
	}
	
	//计算连通块的数量
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
		if(p[i] == i)
			cnt ++;
	cout << cnt-1 << " " << (2*(cnt-1)+n-1) / n; //上取整
	return 0;
}