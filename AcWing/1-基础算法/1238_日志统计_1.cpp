/*
https://www.acwing.com/problem/content/description/1240/

不使用双指针算法，也可以优雅AC
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 100010;
vector<int> t[N]; //id->vector{time,..}
int n,d,k;

int main()
{
	scanf("%d%d%d",&n,&d,&k);
	
	//存入帖子的id和点赞时间ts
	for(int i = 0; i < n; i ++)
	{
		int ts,id;
		scanf("%d%d",&ts,&id);
		t[id].push_back(ts);
	}
	
	//遍历每一个id
	for(int id = 0; id < N; id ++)
	{
		if(t[id].size())
		{
			if(k == 1)
				printf("%d\n",id);
			else
			{
			    //将帖子id的点赞时间排序
				sort(t[id].begin(),t[id].end());
				
				//思维上，有两种检查方式：
				//1. 常规思路：检查时间段<D内的点赞次数是否>=K
				//2. 逆向思维：检查点赞次数为K的时间差是否<D
				//这里采用逆向思维
				int len = t[id].size();
				for(int l = 0; l+k-1 < len; l ++)
				{
				    if(t[id][l+k-1]-t[id][l] < d) //计算时间差
				    {
				        printf("%d\n",id);
				        break;
				    }
				}
			}
		}
	}
	return 0;
}