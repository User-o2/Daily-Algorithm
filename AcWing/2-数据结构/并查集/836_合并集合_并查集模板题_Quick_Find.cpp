/*
https://www.acwing.com/problem/content/description/838/
并查集模板题

[Quick-Find算法]（又称染色法，暴力求解）
*/
#include<iostream>
#include<string>
using namespace std;

const int N = 100010;
int n,m;
int id[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)	
		id[i] = i;
	while(m --)
	{
		string opt;
		int a,b;
		cin >> opt >> a >> b;
		if(opt == "M")
		{
			int ida = id[a], idb = id[b];
			//将a和b合并，这里默认将a染为b
			if(ida != idb)
			{
				for(int i = 1; i <= n; i ++)
				{
					if(id[i] == ida)
						id[i] = idb;
				}
			}
		}
		else
		{
			if(id[a] == id[b])
				cout << "Yes" << "\n";
			else
				cout << "No" << "\n";
		}
	}
	return 0;
}