//全排列
#include<iostream>
using namespace std;

const int N = 10;
int nums[5] = {1,2,3,4,5};
int path[N];
bool sta[N];
int n = 5;

void dfs(int u) //填坑，0~n-1
{
	if(u == n)
	{
		for(int i = 0; i < n; i ++)
			cout << path[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i = 0; i < n; i ++) //递归搜索树，尝试每一个可能的分支
	{
		if(sta[i] == false)
		{
			sta[i] = true;
			path[u] = nums[i];
			dfs(u+1);
			sta[i] = false;
			path[u] = 0;
		}
	}
}

int main()
{
	dfs(0);
	return 0;
}