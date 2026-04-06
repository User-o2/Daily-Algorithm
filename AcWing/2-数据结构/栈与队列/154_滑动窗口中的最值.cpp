/*
https://www.acwing.com/problem/content/description/156/
单调队列
*/
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1000010;
int a[N],n,k;
int q[N];
int hh=0,tt=-1; //双端队列[hh,tt]

int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i ++)
		scanf("%d",&a[i]);
	
	//先是滑动窗口中的最小值
	for(int i = 0; i < n; i ++) //注意i是滑动窗口的右端点
	{ //滑动窗口的范围为[i-k+1,i]
		//队头滑出
		if(hh<=tt && q[hh]<i-k+1)
			hh ++;
		//队尾删除
		while(hh<=tt && a[q[tt]]>=a[i]) //如果队尾比即将进入滑动窗口的元素更大，删去即可
			tt --;
		//队尾插入
		q[++tt] = i;
		if(i >= k-1) //滑动窗口成型
			printf("%d ",a[q[hh]]); //队头是滑动窗口的最小值
	}
	
	printf("\n");
	hh = 0, tt = -1;
	//滑动窗口最大值
	for(int i = 0; i < n; i ++)
	{
		if(hh<=tt && q[hh]<i-k+1)
			hh ++;
		while(hh<=tt && a[q[tt]]<=a[i])
			tt --;
		q[++tt] = i;
		if(i >= k-1)
			printf("%d ",a[q[hh]]);
	}
	return 0;
}