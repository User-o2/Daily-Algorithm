/*
https://www.acwing.com/problem/content/2818/

双指针-同向双指针
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;
int a[N],b[N];
int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i ++)
		scanf("%d",&a[i]);
	for(int i = 0; i < m; i ++)
		scanf("%d",&b[i]);
	
	bool sta = true;
	int j = 0; //遍历b数组
	for(int i = 0; i < n; i ++) //遍历a数组
	{
		while(j < m && a[i] != b[j])
			j ++;
		if(j >= m) //遍历完b了无匹配，不是子序列
		{
			sta = false;
			break;
		}
		if(j < m) //匹配到一位，继续下一位的匹配
			j ++;
	}
	if(sta)
		printf("Yes");
	else
		printf("No");
	return 0;
}
