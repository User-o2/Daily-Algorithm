/*
https://www.acwing.com/problem/content/797/

前缀和
*/
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;
int n,m,a[N]; //这里int不会爆，不开long long了
int l,r;

int main()
{
	scanf("%d%d",&n,&m);
	
	//注意前缀和基于1的索引
	for(int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	
	//前缀和初始化
	for(int i = 1; i <= n; i ++)
		a[i] = a[i-1] + a[i];//S[i] = S[i-1] + a[i]
	
	while(m --)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n", a[r]-a[l-1]);
	}
	return 0;
}