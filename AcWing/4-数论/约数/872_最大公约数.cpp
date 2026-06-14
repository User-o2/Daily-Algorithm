/*
https://www.acwing.com/problem/content/874/
- 最大公约数 gcd(a,b)
- 最小公倍数 lmc(a,b) = a*b / gcd(a,b)
*/
#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b,a%b) : a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while(t --)
	{
		int a,b;
		cin >> a >> b;
		cout << gcd(a,b) << "\n";
	}
	return 0;
}