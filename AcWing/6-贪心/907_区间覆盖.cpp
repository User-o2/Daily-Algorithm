/*
https://www.acwing.com/problem/content/909/
区间覆盖：贪心+跳跃双指针

1. 按左端点从小到大进行排序
2. 选择“左端点可以覆盖st”的区间集合中，右端点最大的那一个max_r（最优选择）
3. 更新st为max_r，继续循环
*/
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

const int N = 100010;
pair<int,int> a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int st,ed,n;
	cin >> st >> ed >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i].first >> a[i].second;
	
	//排序
	sort(a,a+n);
	
	//跳跃双指针
	int res = 0;
	bool sta = false;
	
	int l = 0;
	while(l < n) //[l,r]
	{
		int max_r = -2e9; //记录本组集合中区间右端点可以到达的最大值
		int r = l;
		//找出“左端点可以覆盖st”的区间集合中，右端点最大的那个
		while(r < n && a[r].first <= st)
		{
			max_r = max(max_r, a[r].second);
			r ++;
		} //while循环退出之后，找到本组集合[l,r-1]，这个区间表示“左端点可以覆盖当前st”的区间集合
		
		if(max_r < st) //无解
			break;
		else
		{
			res ++; //选中这个区间
			st = max_r;
		}
		
		if(max_r >= ed) //找到了足够的区间
		{
			sta = true;
			break;
		}
		
		l = r; //跳跃双指针：开始寻找下一组区间
	}
	if(sta)
		cout << res << "\n";
	else
		cout << "-1\n";
	return 0;
}