/*
https://www.acwing.com/problem/content/888/b
求组合数2：求组合数 C(a,b)%p 的值
使用快速幂预处理阶乘

特点：
- 查询次数很大 (10^5)
- a,b的数值范围较大 (10^6)
- 模数 p 是质数，可以使用快速幂计算逆元：a在模p下的逆元是a^(p-2)%p
*/
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 100010;
const int p = 1e9+7;
int fact[N], infact[N]; //阶乘和逆元

int fast(int a, int b, int p)
{
	int res = 1;
	while(b)
	{
		if(b&1)
			res = (ll)res*a % p;
		a = (ll)a*a % p;
		b >>= 1;
	}
	return res;
}

int C(int a, int b)
{
	if(b == 0)
		return 1;
	else
		return (ll)fact[a] * infact[b] % p * infact[a-b] % p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//O(N)预处理
	fact[0] = infact[0] = 1;
	for(int i = 1; i <= N; i ++) //预处理阶乘
	{
		fact[i] = (ll)i * fact[i-1] % p;
	}
	
	infact[N-1] = fast(fact[N-1],p-2,p); //N-1阶乘的逆元 = fast(N-1的阶乘，p-2,p)
	//逆推阶乘的逆元
	for(int i = N-2; i >= 1; i --)
	{
		infact[i] = (ll)(i+1) * infact[i+1] % p;
	}
	
	int t;
	cin >> t;
	while(t --)
	{
		int a,b;
		cin >> a >> b;
		cout << C(a,b) << "\n";
	}
	return 0;
}