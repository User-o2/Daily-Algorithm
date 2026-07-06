/*
https://www.luogu.com.cn/problem/P2670
P2607
*/
#include<iostream>
#include<string>
using namespace std;

const int N = 110;
string mp[N];
int dx[] = {0,1,1,1,0,-1,-1,-1}, dy[] = {-1,-1,0,1,1,1,0,-1};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		cin >> mp[i];
	
	for(int i = 0; i < n; i ++)
	{
		string s = mp[i];
		for(int j = 0; j < m; j ++)
		{
			if(s[j] == '*')
				cout << '*';
			else
			{
				int cnt = 0;
				for(int k = 0; k < 8; k ++)
				{
					int nex_x = dx[k]+i, nex_y = dy[k]+j;
					if(nex_x>=0 && nex_x<n && nex_y>=0 && nex_y<m)
					{
						if(mp[nex_x][nex_y] == '*')
							cnt ++;
					}
				}
				cout << cnt;
			}
		}
		cout << "\n";
	}
	return 0;
}