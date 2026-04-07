/*
https://www.acwing.com/problem/content/description/145/

求最大的异或对
*/

#include<iostream>
using namespace std;

const int N = 100010;
int n;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	//暴力
	int res = 0;
	for(int i = 0; i < n; i ++)
		for(int j = i+1; j < n; j ++)
			res = max(res, a[i]^a[j]);
	cout << res << "\n";
	return 0;
}