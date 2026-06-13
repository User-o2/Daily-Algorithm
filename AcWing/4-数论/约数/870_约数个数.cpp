/*
https://www.acwing.com/problem/content/872/
【公式法】求约数个数

只求约数的个数，没必要把具体的约数求出来
*/
#include<iostream>
#include<unordered_map>
using namespace std;

const int mod = 1e9+7;
int t;
unordered_map<int,int> mp; //<底数，指数>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		
		//本质是质因数分解
		for(int i = 2; i <= n/i; i ++)
		{
			if(n % i == 0)
			{
				int s = 0;
				while(n % i == 0)
				{
					n /= i;
					s ++;
				}
				mp[i] += s;
			}
		}
		if(n > 1)
			mp[n] += 1;
	}
	
	//公式法计算约数的个数：累乘
	long long res = 1;
	for(const auto& p : mp)
		res = res * (p.second+1) % mod;
	cout << res << "\n";
	return 0;
}