/*
https://www.acwing.com/problem/content/873/
【公式法】求约数之和

注意点：
- 避免变量遮蔽
- const 遍历
*/
#include<iostream>
#include<unordered_map>
using namespace std;

const int mod = 1e9+7;
unordered_map<int,int> mp; //<底数，指数>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		
		//质因数分解
		for(int i = 2; i <= n/i; i ++)
		{
			while(n % i == 0)
			{
				n /= i;
				mp[i] ++;
			}
		}
		if(n > 1)
			mp[n] ++;
	}
	
	//公式法：相加再相乘
	long long res = 1;
	for(const auto& ele : mp) //mp遍历的元素是pair<>
	{
		long long tmp = 1;
		int p = ele.first, k = ele.second; //p^k
		for(int i = 0; i < k; i ++)
			tmp = (tmp*p + 1) % mod;
			
		res = res * tmp % mod;
	}
	cout << res << "\n";
	return 0;
}