/*
https://www.luogu.com.cn/problem/P8783

双指针-滑动窗口+二维前缀和
*/
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 510;
int n,m,k;
int a[N][N];

int get_sum(int x1, int y1, int x2, int y2)
{
	return a[x2][y2] - a[x2][y1-1] - a[x1-1][y2] + a[x1-1][y1-1];
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			scanf("%d",&a[i][j]);
			//前缀和初始化
			//这里[i][j]只是表示以(0,0),(i,j)为对角点的矩形内的和
			a[i][j] = a[i][j-1] + a[i-1][j] - a[i-1][j-1] + a[i][j];
		}
	
	//因为所有子矩阵的个数接近500^4，需要开long long
	long long res = 0;
	//使用滑动窗口优化
	//首先遍历子矩阵的上下边界
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++) //暴力遍历子矩阵所有的上下边界
		{
			//对于以直线x=i,x=j为上下边界的子矩阵：
			//本质上就是将二维转为一维，使用滑动窗口维护
			for(int l = 1, r = 1; r <= m; r ++) //滑动窗口[l,r]
			{
				while(l<=r && get_sum(i,l,j,r)>k)
					l ++;
				if(l <= r)
					res += r-l+1;
			}
		}
	printf("%lld",res);
	return 0;
}