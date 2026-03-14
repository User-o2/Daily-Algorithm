/*
https://www.luogu.com.cn/problem/P9325

双指针-中心拓展
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 5010;
int n,a[N],res[N];
//res[i]表示长度为i的区间的不对称值

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
		scanf("%d",&a[i]);
		
	//将res[i]设为无穷大，约为1e9
	memset(res,0x3f,sizeof(res)); //<cstirng>
	//中心拓展法，枚举区间的中心
	for(int i = 0; i < n; i ++) //区间中心
	{
		//区间长度为奇数
		int l = i, r = i;
		int sum = 0;
		while(l >= 0 && r < n)
		{
			//优化点就是在这里，没有重复计算
			sum += abs(a[l]-a[r]);
			//每移动一次就是区间长度的改变，所以需要维护答案
			res[r-l+1] = min(res[r-l+1],sum);
			l --;
			r ++;
		}
		
		//区间长度为偶数
		l = i, r = i+1;
		sum = 0;
		while(l >= 0 && r < n)
		{
			sum += abs(a[l]-a[r]);
			res[r-l+1] = min(res[r-l+1],sum);
			l --;
			r ++;
		}
	}
	for(int i = 1; i <= n; i ++)
		printf("%d ",res[i]);
	return 0;
}