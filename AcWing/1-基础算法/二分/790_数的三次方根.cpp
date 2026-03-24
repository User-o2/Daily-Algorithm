/*
https://www.acwing.com/problem/content/description/792/

浮点数二分
*/

#include<iostream>
#include<cstdio>
using namespace std;

double n;

int main()
{
	scanf("%lf",&n);
	
	double l = -100, r = 100;
	//浮点数二分，直接暴力循环100次，必定找到答案
	for(int i = 0; i < 100; i ++)
	{
		double mid = (l+r)/2;
		//浮点数二分不用+-1
		if(mid*mid*mid >= n)
			r = mid;
		else
			l = mid;
	}
	printf("%.6lf",l);
	return 0;
}