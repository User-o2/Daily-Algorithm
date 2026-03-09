/*
https://www.acwing.com/problem/content/description/800/

差分矩阵
*/
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1010;
int n,m,q;
int x1,y1,x2,y2,c;
long long a[N][N],S[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
	a[x1][y1] += c;
	a[x1][y2+1] -= c;
	a[x2+1][y1] -= c;
	a[x2+1][y2+1] += c;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			scanf("%lld",&S[i][j]);
			//初始化差分矩阵
			insert(i,j,i,j,S[i][j]);
		}
	
	while(q --)
	{
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
		insert(x1,y1,x2,y2,c);
	}
	
	//insert是在a[][]上修改的，需要基于a[][]更新S[][]
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1] + a[i][j];
			printf("%lld ",S[i][j]);
		}
		printf("\n");
	}
	return 0;
}