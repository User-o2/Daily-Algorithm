/*
https://www.acwing.com/problem/content/844/
dfs全排列
*/
#include<iostream>
using namespace std;

const int N = 15;
int n,path[N]; //存储某一分支（一种全排列顺序）
bool sta[N]; //是否已经被使用

void dfs(int u) //u表示要填的坑位
{
	if(u == n+1) //要填坑位n+1了，结束
	{
		for(int i = 1; i <= n; i ++) //输出坑位1-n
			cout << path[i] << " ";
		cout << "\n";
		return;
	}
	
	//对于本坑位，尝试所有潜在的数字
	for(int i = 1; i <= n; i ++) //尝试数字1~n
	{
		if(sta[i] == false)
		{
			sta[i] = true;
			path[u] = i; //在坑位u填上数字i
			dfs(u+1); //去填下一个坑位
			//恢复现场
			path[u] = 0;
			sta[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	dfs(1); //从坑位1开始填，需要填1~n
	return 0;
}