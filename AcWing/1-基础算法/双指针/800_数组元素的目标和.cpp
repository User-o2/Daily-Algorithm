/*
https://www.acwing.com/problem/content/802/

解法1-哈希表
没有用到“升序排序”这个特殊条件
*/

#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;

const int N = 100010;
unordered_map<int ,int>mp;
int n,m,x;
int a[N],b[N];

int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d",&a[i]);
		mp[a[i]] = i; //保证有唯一解，那么映射没问题
	}
	
	for(int i = 0; i < m; i ++)
	{
		scanf("%d",&b[i]);
		if(mp.count(x-b[i]))
		{
			printf("%d %d",mp[x-b[i]],i);
			break;
		}
	}
	return 0;
}