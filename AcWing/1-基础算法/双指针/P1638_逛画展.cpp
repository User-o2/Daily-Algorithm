/*
https://www.luogu.com.cn/problem/P1638

双指针-滑动窗口
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1000010, M = 2010;
int n,m;
int a[N],s[M];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i ++)
		scanf("%d",&a[i]);
	
	//注意a[]中仅包含1-m数字
	//本质就是求一个最短的窗口[x,y]，使得窗口内包含1-m全部的数字
	int x = 0,y = 0;
	int cnt = 0, min_len = n+1;
	int j = 0; //维护左端点
	for(int i = 0; i < n; i ++)
	{
		if(s[a[i]] == 0)
			cnt += 1;
		s[a[i]] += 1;
		while(cnt==m && s[a[j]]>1)
		{
			s[a[j]] -= 1;
			j ++;
		}
		if(cnt==m && i-j+1<min_len) //<确保输出x最小的那个解
		{
			min_len = i-j+1;
			x = j, y = i;//[j,i]
		}
	}
	printf("%d %d",x+1,y+1);
	return 0;
}