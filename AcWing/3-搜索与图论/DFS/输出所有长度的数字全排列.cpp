#include<iostream>
#include<vector>
using namespace std;

const int N = 15;
int n;
vector<vector<int>> bkt[N];
vector<int> path; //记录每一个合法的路径
bool sta[N];

void dfs(int u) //开始填第u个坑
{
	if(u > 1) //长度至少为1了
		bkt[u-1].push_back(path);
	if(u == n+1)
		return;
	
	//对于这个坑，尝试所有可能的数字
	for(int i = 1; i <= n; i ++)
	{
		if(sta[i] == false)
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
	dfs(1); //基于1的索引
	
	for(int i = 1; i <= n; i ++)
	{
		for(auto ele : bkt[i]) //bkt[i]是vec<vec>，ele是vector<int>，也就是每一条路径
		{
			for(int x : ele)
				cout << x << " ";
			cout << "\n";
		}
	}
	return 0;
}