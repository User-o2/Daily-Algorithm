/*
https://www.acwing.com/problem/content/3725/

双指针-跳跃指针
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1010;
int n,p[N];

int main()
{
	while(scanf("%d",&n)==1)
	{
		for(int i = 0; i < n; i ++)
			scanf("%d",&p[i]);
		
		//跳跃双指针
		int res = 0;
		int l = 0;
		while(l < n) //区间的左端点
		{
			int r = l;
			while(r+1<n && p[r+1]>=p[r]) //注意这里的r+1<n是为了防止越界
				r ++;
			//while循环退出之后就是最大的非下降区间了
			if(r > l)
				res = max(res, p[r]-p[l]);
			//因为p[r+1]<p[r]，所以起点l直接设为r+1即可
			l = r+1;
		}
		printf("%d\n",res);
	}
	return 0;
}