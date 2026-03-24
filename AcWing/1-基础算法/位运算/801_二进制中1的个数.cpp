/*
https://www.acwing.com/problem/content/803/

位运算。
就是使用一些位运算的符号进行高效运算：|, &, ~, >>, ^
lowbit(x) = x & -x，返回x的二进制表示中的1以及之后的位
*/

#include<iostream>
#include<cstdio>
using namespace std;

int n;

int main()
{
	int num;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d",&num);
		int cnt = 0;
		while(num)
		{
			if(num & 1 == 1)
				cnt ++;
			num >>= 1;
		}
		printf("%d ",cnt);
	}
	return 0;
}