/*
https://www.acwing.com/problem/content/description/805/

区间合并（贪心）
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

const int N = 100010;
int n;

int main()
{
    scanf("%d",&n);
    vector<pair<int,int>> pairs;
    for(int i = 0; i < n; i ++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        pairs.push_back({l,r});
    }
    
    //按照左端点进行排序
    sort(pairs.begin(),pairs.end());
    
    int cnt = 0;
    pair<int,int> cur = pairs[0]; //当前的区间
    for(int i = 1; i < pairs.size(); i ++)
    {
        if(cur.second >= pairs[i].first)
            cur.second = max(cur.second, pairs[i].second);
        else
        {
            cnt ++;
            cur = pairs[i];
        }
    }
    cnt ++; //别忘记最后一个区间段
    printf("%d",cnt);
    return 0;
}