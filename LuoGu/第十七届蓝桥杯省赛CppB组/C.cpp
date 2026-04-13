/*
https://www.luogu.com.cn/problem/P16234
补题-蓝桥杯2026 C++B组 C题

思维题
*/
#include<iostream>
using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while(t --)
	{
		long long n,x,y;
		cin >> n >> x >> y;
		
		//也就是[x,y]之间的数的个数
		if(y-x >= 0)
			cout << y-x+1 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
	
}