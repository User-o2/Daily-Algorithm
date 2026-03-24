/*
https://www.acwing.com/problem/content/description/804/
离散化+前缀和

稀疏大值域的单点修改与区间查询问题：
题目是**离线查询**（所有查询操作都在修改操作之后），可以把所有可能被访问到的坐标提取出来，
将其压缩到一段连续的密集索引数组中，然后再进行add操作和查询。
类似降维
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

const int N = 300010; //n+2m <= 3e5
vector<int> alls; //存储所有用到的位置下标
vector<pair<int,int>> query; //存储查询用到的位置
vector<pair<int,int>> add; //存储加值操作用到的位置
int a[N]; //最多也就N个用到的下标
int s[N]; //前缀和，这里无需long long
int n,m;

int search(int x) //使用二分查找，找到原位置x离散化之后的下标
{
	int l = 0, r = alls.size()-1;
	while(l < r)
	{
		int mid = l+r >> 1;
		if(alls[mid] >= x)
			r = mid;
		else
			l = mid+1;
	}
	return l+1; //一定会找到，直接返回下标+1（因为前缀和基于1的索引）
}

int main()
{
	scanf("%d%d",&n,&m);
	//收集坐标
	for(int i = 0; i < n; i ++)
	{
		int x,c;
		scanf("%d%d",&x,&c);
		add.push_back({x,c});
		alls.push_back(x);
	}
	for(int i = 0; i < m ; i ++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		query.push_back({l,r});
		alls.push_back(l);
		alls.push_back(r);
	}
	
	//开始离散化
	//1.排序+去重 时间复杂度瓶颈：O(NlogN)
	sort(alls.begin(),alls.end());
	//unique将相邻重复元素移动到末尾，erase进行区间去重
	alls.erase(unique(alls.begin(),alls.end()),alls.end());
	
	//2.执行add操作
	for(int i = 0; i < add.size(); i ++)
	{
		int idx = search(add[i].first);
		a[idx] += add[i].second; //确保a[]的下标是基于1的索引
	}
	
	//3.前缀和加速
	for(int i = 1; i < N; i ++)
		s[i] = s[i-1] + a[i];
		
	//4.处理查询
	for(int i = 0; i < query.size(); i ++)
	{
		int l_idx = search(query[i].first);
		int r_idx = search(query[i].second);
		printf("%d\n",s[r_idx]-s[l_idx-1]);
	}
	return 0;
}