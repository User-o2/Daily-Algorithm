/*
https://www.acwing.com/problem/content/875/
【公式法】求某个数的欧拉函数

- 使用公式法求某个数的欧拉函数，这个公式需要记忆！
*/
#include<iostream>
#include<vector>
using namespace std;

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
		int res = n;
		
		vector<int> p;
		//质因数分解，用不到指数，所以可以不用记录
		for(int i = 2; i <= n/i; i ++)
		{
			if(n % i == 0)
			{
				while(n % i == 0)
					n /= i;
				//使用公式计算欧拉函数
				res = res/i * (i-1); //在线算法
			}
		}
		if(n > 1)
			res = res/n * (n-1);
			
		cout << res << "\n";
	}
	return 0;
}