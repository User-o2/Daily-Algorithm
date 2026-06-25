/*
https://www.acwing.com/problem/content/887/
组合数1：求组合数 C(a,b)%p 的值。

特点：
- a,b 的数值范围很小(<=2000)
- 通过递推公式法预处理 C(a,b)=C(a-1,b)+C(a-1,b-1)
*/
#include<iostream>
using namespace std;

const int N = 2010;
int c[N][N];
int p = 1e9+7;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//预处理初始化c[i][j]
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j <= i; j ++)
		{
			if(j == 0)
				c[i][j] = 1;
			else //j>0
			{
				c[i][j] = (c[i-1][j] + c[i-1][j-1]) % p;
			}
		}
	}
	
	int t;
	cin >> t;
	while(t --)
	{
		int a,b;
		cin >> a >> b;
		cout << c[a][b] << "\n";
	}
	return 0;
}