/*
https://www.acwing.com/problem/content/799/

差分
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;
int n,m,l,r,c;
int a[N],S[N];

//实现使S[l]~S[r]之间的每个元素加上c
void insert(int l, int r, int c)
{
	a[l] += c;
	a[r+1] -= c;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d",&S[i]);
		//初始化差分数组a[]
		insert(i,i,S[i]);
	}
	
	while(m --)
	{
		scanf("%d%d%d",&l,&r,&c);
		insert(l,r,c);
	}
	
	//输出最终的序列
	//注意，insert()函数本质上是在差分数组a[]上进行修改，需要最后更新为S[]
	for(int i = 1; i <= n; i ++)
	{
		S[i] = S[i-1] + a[i];
		printf("%d ",S[i]);
	}
	return 0;
}