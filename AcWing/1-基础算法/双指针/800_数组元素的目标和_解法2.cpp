/*
https://www.acwing.com/problem/content/description/802/

双指针-对撞指针
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;
int n,m,x;
int a[N],b[N];

int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i = 0; i < n; i ++)
		scanf("%d",&a[i]);
	for(int j = 0; j < m; j ++)
		scanf("%d",&b[j]);
	
	int j = m-1;
	for(int i = 0; i < n; i ++)
	{
		while(a[i]+b[j] > x) //偏大
			j --;
		if(a[i]+b[j] == x) //刚好
		{
			printf("%d %d",i,j);
			break; //唯一解，直接退出
		}
		//偏小，继续移动i
	}
	return 0;
}