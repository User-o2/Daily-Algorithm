/*
https://www.acwing.com/problem/content/798/

二维前缀和

在草稿上画矩形分析，现场推导:
1. a[i][j]表示的是以(0,0)为左上角、以(i,j)为右下角的矩形内元素的和
2. 画图推导的时候一定是利用a[i][j]矩形内部已知的前缀和进行推导，比如a[i][j-1],a[i-1][j],a[i-1][j-1]
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1010;
int n,m,q;
int x1,y1,x2,y2;
int a[N][N]; //一般应该开long long

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			scanf("%d",&a[i][j]);
	
	//二维前缀和初始化
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			a[i][j] = a[i][j-1] + a[i-1][j] - a[i-1][j-1] + a[i][j];
	
	while(q --)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int res = a[x2][y2] - a[x2][y1-1] - a[x1-1][y2] + a[x1-1][y1-1];
		printf("%d\n",res);
	}
	return 0;
}