/*
https://www.acwing.com/problem/content/106/
货仓选址

【绝对值三角不等式、中位数模型】|x|+|y|>=|x-y|
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	sort(a,a+n);
	
	int mid = a[n/2];
	long long res = 0;
	for(int i = 0; i < n; i ++)
		res += abs(mid-a[i]);
		
	cout << res << "\n";
	return 0;
}