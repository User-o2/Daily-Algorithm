/*
https://www.acwing.com/problem/content/871/
【试除法】求约数
*/
#include<iostream>
#include<vector>
#include<algorithm>
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
		
		//试除法求约数
		vector<int> div;
		for(int i = 1; i <= n/i; i ++)
		{
			if(n % i == 0)
			{
				div.push_back(i);
				if(n / i != i)
					div.push_back(n/i);
			}
		}
		sort(div.begin(), div.end());
		for(int x : div)
			cout << x << " ";
		cout << "\n";
	}
	return 0;
}