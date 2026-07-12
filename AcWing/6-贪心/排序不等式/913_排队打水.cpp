/*
https://www.acwing.com/problem/content/description/915/
排队打水
【排序不等式/最短作业优先】：顺序和>=乱序和>=逆序和
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
	
	sort(a,a+n); //降序排序
	
	long long sum = 0;
	for(int i = 0; i < n; i ++)
		sum += a[i] * (n-1-i);
	cout << sum << "\n";
	return 0;
}