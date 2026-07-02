/*
https://www.acwing.com/problem/content/893/
Nim游戏 - 异或和求解Nim游戏
*/
#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,a;
	cin >> n;
	
	int res = 0;
	for(int i = 0; i < n; i ++)
	{
		cin >> a;
		res ^= a;
	}
	if(res == 0)
		cout << "No\n";
	else
		cout << "Yes\n";
		
	return 0;
}