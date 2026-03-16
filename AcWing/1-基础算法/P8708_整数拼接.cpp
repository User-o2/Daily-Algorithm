/*
https://www.luogu.com.cn/problem/P8708

双指针-对撞指针
重要的点：
- 单调性的体现？
- 为什么跑两遍双指针
- 为什么res += r-l
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int N = 100010;
int n;
string a[N],k;

bool cmp(const string& a, const string& b) //判断是否有a<=b
{
	if(a.size() != b.size())
		return a.size() < b.size();
	else //字典序比较
		return a <= b;
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	sort(a,a+n,cmp); //升序排序 可以传自定义的bool函数
	
	long long res = 0;
	//拼接方式1：l+r
	int l = 0, r = n-1;
	while(l < r)
	{
		if(cmp(a[l]+a[r],k))
		{
			res += r-l;
			l ++;
		}
		else
			r --;
	}
	
	//拼接方式2：r+l
	l = 0, r = n-1;
	while(l < r)
	{
		if(cmp(a[r]+a[l],k))
		{
			res += r-l;
			l ++;
		}
		else
			r --;
	}
	cout << res;
	return 0;
}