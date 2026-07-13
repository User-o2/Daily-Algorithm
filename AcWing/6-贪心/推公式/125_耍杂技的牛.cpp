/*
https://www.acwing.com/problem/content/127/
耍杂技的牛

【贪心-最大值最小化模型】邻项交换法进行贪心证明

*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 50010;
struct cow
{
	int w,s;
};
cow a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i].w >> a[i].s;
	
	sort(a,a+n,[](cow& x, cow& y)
	{
		return x.w+x.s <= y.w+y.s; //升序排序
	});
	
	int res = -2e9, sum = 0;
	for(int i = 0; i < n; i ++)
	{
		res = max(res, sum-a[i].s);
		sum += a[i].w;
	}
	cout << res << "\n";
	return 0;
}