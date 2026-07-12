/*
https://www.acwing.com/problem/content/910/

最大不相交区间数量，等价于区间选点问题。
本质上都是求解“最大的、互不相交的区间数量”
*/
#include<iostream>
#include<utility>
#include<algorithm>
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
	
	//最大不相交区间数量，和区间选点本质相同
	sort(line,line+n,[](pair<int,int> a, pair<int,int> b){
		return a.second < b.second;
	});
	
	//统计数量
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