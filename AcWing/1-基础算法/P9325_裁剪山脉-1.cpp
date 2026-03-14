/*
https://www.luogu.com.cn/problem/P9325

双指针
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 5010;
int n,a[N];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
		scanf("%d",&a[i]);
	for(int len = 1; len <= n; len ++) //裁剪窗口的长度
	{
		int res = 2e9;
		for(int i = 0; i+len-1 < n; i ++) //遍历窗口左端点
		{
			int l = i;
			int r = l+len-1;
			
			//计算[l,r]区间内的不对称值
			int sum = 0;
			while(l < r)
			{
				sum += abs(a[l]-a[r]);
				l ++, r--;
			}
			res = min(res,sum);
		}
		printf("%d ",res);
	}
	return 0;
}