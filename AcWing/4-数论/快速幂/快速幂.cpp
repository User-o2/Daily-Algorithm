/*
https://www.acwing.com/problem/content/877/
快速幂模板题
*/

#include<iostream>
using namespace std;

typedef long long ll;

ll fast_pow(ll a, ll b, ll p)
{
	ll res = 1;
	while(b)
	{
		if(b & 1) //注意这里关系运算符(==)的优先级大于位运算符(&)
			res = res*a % p;
		a = a*a % p;
		b >>= 1;
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t --)
    {
    	ll a,b,p;
    	cin >> a >> b >> p;
    	cout << fast_pow(a,b,p) << "\n";
	}
	return 0;
}