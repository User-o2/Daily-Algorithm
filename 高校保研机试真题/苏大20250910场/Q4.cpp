/*
判断质数
O(N·根号N)
*/
#include<iostream>
#include<unordered_map>
using namespace std;

bool IsPrime(int n)
{
	if(n <= 1)
		return false;
	else
	{
		for(int i = 2; i <= n/i; i ++)
		{
			if(n % i == 0)
				return false;
		}
		return true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	unordered_map<int,int> mp;
	for(int i = 0; i < n; i ++)
	{
		int num;
		cin >> num;
		mp[num] ++;
	}
	
	for(auto& p : mp) //引用避免拷贝
	{
		int cnt = p.second;
		if(IsPrime(cnt))
		{
			cout << "1\n";
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}