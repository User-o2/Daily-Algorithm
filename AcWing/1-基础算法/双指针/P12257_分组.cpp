/*
https://www.luogu.com.cn/problem/P12257
贪心+同向双指针
1. 首先要排序，尽可能让刚好>=2*a[i]的a[j]和他组队，这样就最大化利用数值大小；
2. 后面双指针i,j，分别遍历前半部分和后半部分。
3. 如果n为奇数，中间的数字直接忽略，因为分好组之后让他直接插入最小值的组即可；
4. 如果n为偶数，刚好对半分遍历即可
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100010;
int a[N];
int n;

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
		scanf("%d",&a[i]);
	
	sort(a,a+n);
	
	//同向双指针
	int res = 0, mid = (n+1)/2;
	int i = 0, j = mid;
	while(i < mid && j < n)
	{
		if(a[j] >= a[i]*2) //可以组队
		{
			res ++;
			i ++;
			j ++;
		}
		else
			j ++;
	}
	printf("%d",res);
	return 0;
}