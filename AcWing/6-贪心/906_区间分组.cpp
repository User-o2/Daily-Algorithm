/*
https://www.acwing.com/problem/content/description/908/

区间分组问题
可以转为“最少需要多少间会议室”的问题
*/
#include<iostream>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 100010;
pair<int,int> line[N];
priority_queue<int,vector<int>,greater<int>> heap; //小根堆

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> line[i].first >> line[i].second;
	
	//1.排序
	sort(line,line+n); //默认按照pair<>的[左端点][从小到大排序]
	//先开始的会议先占用
	
	//2.模拟开会
	for(int i = 0; i < n; i ++)
	{
		if(heap.size()==0 || heap.top()>=line[i].first) //下一场会议的最早开始时间早于最早结束的会议
		{
			//新开一个组（会议室）
			heap.push(line[i].second); //加入结束时间
		}
		else //有空闲的会议室，不必新开
		{
			//占用空闲的会议室，更新会议结束时间
			heap.pop(); //空闲的会议室一定是最早结束的
			heap.push(line[i].second);
		}
	}
	cout << heap.size() << "\n";
	return 0;
}