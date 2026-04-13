/*
https://www.luogu.com.cn/problem/P16235
补题-蓝桥杯2026 C++B组 D题

思维题
解法：
1.显然，如果选手人数不是5的倍数，无解
2.设选手人数为sum，5人一队，则最终一定分为sum/5队
  因为同一个队伍中选手的位置必须不同，那么对于同一个位置的选手们，不可以分到同一个队伍，
  所以同一个位置的选手人数不可以超过sum/5
3.为什么不需要判断n<5这种无解情况
  n<5，则sum/n > sum/5，天然不符合第2种要求
*/
#include<iostream>
using namespace std;

const int N = 100010;
int t;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		long long sum = 0;
		for(int i = 0; i < n; i ++)
		{
			cin >> a[i];
			sum += a[i];
		}
		
		if(sum % 5)
			cout << "F" << "\n";
		else
		{
			bool sta = true;
			for(int i = 0; i < n; i ++)
			{
				if(a[i] > sum/5)
				{
					sta = false;
					cout << "F" << "\n";
					break;
				}
			}
			if(sta)
				cout << "T" << "\n";
		}
	}
	return 0;
}