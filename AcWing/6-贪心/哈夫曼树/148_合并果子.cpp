/*
https://www.acwing.com/problem/content/150/
合并果子：哈夫曼树问题

贪心：注意到这是一个不断重复累加计算的过程，所以只需要每次尽可能地搬重量小的果堆即可（即哈夫曼树的构建过程）
考虑使用优先队列维护。
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int a;
		cin >> a;
		pq.push(a);
	}
	
	long long sum = 0;
	while(pq.size() >= 2)
	{
		int a1 = pq.top(); pq.pop();
		int a2 = pq.top(); pq.pop();
		sum += a1+a2;
		pq.push(a1+a2);
	}
	cout << sum << "\n";
	return 0;
}