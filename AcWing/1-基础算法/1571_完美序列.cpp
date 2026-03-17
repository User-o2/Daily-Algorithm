/*
https://www.acwing.com/problem/content/description/1573/

双指针-滑动窗口
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100010;
int n,p;
int a[N];

int main()
{
	scanf("%d%d",&n,&p);
	for(int i = 0; i < n; i ++)
		scanf("%d",&a[i]);
	//原题要求的是子序列，子序列在原数组中是不必连续的。
	//“完美序列”的判定条件仅仅依赖于集合中的最值，与元素原本的相对位置毫无关系。因此，对数组进行 sort 是破题的核心。
	sort(a,a+n);
	
	int res = 0;
	int j = 0; //窗口左端
	for(int i = 0; i < n; i ++) //窗口右端
	{
		//排序后最大值和最小值就分别为a[i],a[j]
		while(j<=i && a[i] > (long long)a[j]*p)
			j ++;
		//在窗口中必定有j<=i，所以必定有j<n，加上j<=i的条件在其他题目中保险一些
		res = max(res, i-j+1);
	}
	printf("%d",res);
	return 0;
}