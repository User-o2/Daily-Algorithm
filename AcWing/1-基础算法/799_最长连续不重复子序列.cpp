/*
https://www.acwing.com/problem/content/description/801/

双指针-滑动窗口
核心：先计数，然后再检查是否重复
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;
int n;
int a[N],s[N];

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
		scanf("%d",&a[i]);
		
	//滑动窗口
	int l = 0; //左端点
	int res = 0;
	for(int r = 0; r < n; r ++) //右端点
	{
		//扩张窗口
		s[a[r]] += 1; //加入新来的
		while(s[a[r]] > 1) //说明新来的造成了重复
		{
			//缩短窗口
			s[a[l]] -= 1;
			l ++;
		}
		//随时更新窗口最大长度
		res = max(res, r-l+1);
	}
	printf("%d",res);
	return 0;
}