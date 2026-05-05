/*
题目：
输出所有长度的数字排列，并要求最终的输出必须是长度递增优先
（先集中输出长度为 1 的，再输出长度为 2 的排列顺序）
*/
#include<iostream>
#include<vector>
using namespace std;

const int N = 15;
int n;
vector<int> path;
bool sta[N];
vector<vector<int>> bucket[N]; //可以理解为一维数组，里面存放的是vector<vector<int>>
/*
也就是每一个元素都是{{},{},...{}}
bucket[i]存储的是所有长度为i的数字排列

vector<vector<int>> 和 int a[][] 是两种不同的理解方式
如何理解vector<vector<int>> bucket[N]数据类型呢：
bucket[i]中存储的是：所有长度为i的排列vector<vector<int>>，可以理解为vector<路径>
*/

void dfs(int u) //u表示要填的坑位
{
	if(u > 1) //长度>1了，先存下来长度为u-1的数字排列
		bucket[u-1].push_back(path);
	if(u == n+1) //长度达到最大(n)，终止（注意，一定要先存储再终止）
		return;
	
	//开始填本坑位，遍历所有可能的数字：n个平行的分支
	for(int i = 1; i <= n; i ++)
	{
		if(!sta[i])
		{
			sta[i] = true;
			path.push_back(i);
			dfs(u+1);
			sta[i] = false;
			path.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	dfs(1); //1-based，从1号坑位开始填
	
	//按照长度输出
	for(int len = 1; len <= n; len ++)
	{
		for(auto& vec : bucket[len]) //注意这里降了两维：bucket[len]是vector<vector<int>>，所以vec是vector<int>
		{
			for(int num : vec)
				cout << num << " ";
			cout << "\n";
		}
	}
	return 0;
}