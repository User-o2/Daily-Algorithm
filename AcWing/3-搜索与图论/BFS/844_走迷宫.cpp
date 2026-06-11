/*
https://www.acwing.com/problem/content/846/
BFS求解网格图最短路问题
*/
#include<iostream>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;

const int N = 110;
int n,m;
int mp[N][N]; //01地图

/* BFS所需要的数据类型 */
int dist[N][N]; //作用：记录距离同时判断是否已访问过
queue<pair<int,int>> q;
int dx[] = {0,0,1,-1},dy[] = {-1,1,0,0};

int bfs(int st_x, int st_y)
{
    //初始化为-1，标记+记录距离
    memset(dist, -1, sizeof(dist));
    
    //每个节点最多入队一次、出队一次。每个节点都是入队的时候记录距离！
    q.push({st_x,st_y});
    dist[st_x][st_y] = 0; //起点需要移动0次
    //这里专门特判起点是否就是终点
    if(st_x==n-1 && st_y==m-1)
        return 0;
    
    while(!q.empty())
    {
        pair<int,int> cur = q.front(); q.pop();
        int cur_x = cur.first, cur_y = cur.second;
        
        //遍历当前节点的每一个邻居
        for(int i = 0; i < 4; i ++)
        {
            int nex_x = cur_x+dx[i], nex_y = cur_y+dy[i];
            //越界判断+是否可访问+是否第一次到达
            if(nex_x>=0 && nex_x<n && nex_y>=0 && nex_y<m && mp[nex_x][nex_y]==0 && dist[nex_x][nex_y]==-1)
            {
                //满足条件：入队、记录距离
                q.push({nex_x,nex_y});
                dist[nex_x][nex_y] = dist[cur_x][cur_y]+1;
                
                //入队的时候就要检查是否到达终点
                //不要等到出队的时候再检查！每个点最多入队一次、出队一次，所以只需要在入队的时候检查即可
                if(nex_x==n-1 && nex_y==m-1)
                    return dist[nex_x][nex_y];
            }
        }
    }
    // return -1; //无解
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> mp[i][j];
    
    //从起点开始进行BFS
    cout << bfs(0,0);
    
    return 0;
}