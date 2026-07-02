/*
https://www.acwing.com/problem/content/907/

[贪心]区间选点
*/
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

const int N = 100010;
pair<int,int> line[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> line[i].first >> line[i].second;
		
	//本质上就是寻找最大不相交区间数量的问题
	//1.对[右端点][从小到大]排序
	sort(line,line+n,[](pair<int,int> a, pair<int,int> b){
		return a.second < b.second;
	});
	
	//2.选择右端点，为最优覆盖点
	int cnt = 0, ed = line[0].second;
	for(int i = 1; i < n; i ++)
	{
		if(ed < line[i].first)
		{
			cnt += 1;
			ed = line[i].second;
		}
	}
	cout << cnt+1 << "\n";
	return 0;
}