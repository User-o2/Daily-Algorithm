/*
https://www.luogu.com.cn/problem/P16236
补题-蓝桥杯2026 C++B组 E题

[优化版DFS搜索]过30%测试数据：
- 将O(N^2)的LQ对计算优化为动态维护的O(N)，DFS传参维护
- 优化DFS中的string参数传值的拷贝开销

学习：
- 线性dp优化暴力二维循环
- string vs char s[N]
- dfs()优雅传参计算
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
string s;
long long res;

//之后总结一下经验
void dfs(int u, int cnt_L, long long cnt_LQ) //u表示要填的坑索引，cnt_L表示目前L的数量，cnt_LQ表示LQ对
{
	if(u == n) //遍历完毕
	{
		res = max(res, cnt_LQ);
		return;
	}
	//这里u不只是遍历'?'，而是将s扫一遍
	
	//线性dp的思想
	if(s[u] == 'L')
		dfs(u+1, cnt_L+1, cnt_LQ);
	else if(s[u] == 'Q')
		dfs(u+1, cnt_L, cnt_LQ+cnt_L);
	else //s[u]=='?'，填坑
	{
		//1.填L
		dfs(u+1, cnt_L+1, cnt_LQ);
		
		//2.填Q
		dfs(u+1, cnt_L, cnt_LQ+cnt_L);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> s;
	dfs(0, 0, 0);
	cout << res << "\n";
	return 0;
}