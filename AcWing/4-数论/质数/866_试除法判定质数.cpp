/*
https://www.acwing.com/problem/content/868/
【试除法】判断质数

IsPrime()函数注意事项：
- 需要考虑 if(n <= 1) 的情况
- 注意条件判断 i<=n/i 因为 i*i<=n 存在溢出的风险
*/
#include<iostream>
using namespace std;

int t;

bool IsPrime(int n)
{
	if(n <= 1)
		return false;
	for(int i = 2; i <= n/i; i ++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while(t --)
	{
		int x;
		cin >> x;
		cout << (IsPrime(x) ? "Yes\n" : "No\n");
	}
	return 0;
}