/*
https://www.acwing.com/problem/content/3725/
双指针-跳跃指针

如何写得更优雅—>双层while循环
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
		while(l < n) //维护[l,r]，使其为一个爬坡
		{
			int r = l;
			while(r+1<n && p[r+1]>=p[r]) //注意这里的r+1<n是为了防止越界
				r ++;
            //while退出有两种可能：r==n-1 or p[r+1]<p[r]
            //这两种可能均表示[l,r]已到达极限
			if(r > l) //满足区间长度>=2的要求
				res = max(res, p[r]-p[l]);
			//因为p[r+1]<p[r]，所以起点l直接设为r+1即可
			l = r+1;
		}
		printf("%d\n",res);
	}
	return 0;
}