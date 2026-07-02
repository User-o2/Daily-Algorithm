/*
https://www.acwing.com/problem/content/894/

台阶-Nim 游戏
必胜态：奇数级台阶上的异或和不为 0
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
	for(int i = 1; i <= n; i ++)
	{
		cin >> a;
		if(i % 2 == 1)
			res ^= a;
	}
	if(res != 0)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}