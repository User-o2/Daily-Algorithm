/*
https://www.luogu.com.cn/problem/P16233
补题-蓝桥杯2026 C++B组 B题
快速幂
*/
#include<iostream>
using namespace std;

int n = 2026;
int mod = 998244353;

long long fast_pow(int a, int b) //a^b
{
	long long res = 1;
	while(b)
	{
		if(b & 1)
			res = res * a % mod;
		b >>= 1;
		a = (long long)a*a % mod;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//n*2^(n-1)
	cout << (long long)n * fast_pow(2,n-1) % mod;
	return 0;
	
}