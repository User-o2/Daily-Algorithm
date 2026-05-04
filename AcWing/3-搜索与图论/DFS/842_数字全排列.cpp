/*
https://www.acwing.com/problem/content/844/
N叉树搜索模型
*/
#include<iostream>
#include<vector>
using namespace std;

const int N = 10;
int n;
int path[N]; //路径是定长的，使用静态数组即可
bool vis[N]; //是否访问

void dfs(int u) //u表示该填的坑位，坑位1~n
{
    if(u == n+1)
    {
        for(int i = 1; i <= n; i ++)
            cout << path[i] << " ";
        cout << "\n";
        return;
    }
    
    //对于本坑位，所有没有使用过的数字都是可能的
    for(int i = 1; i <= n; i ++) //数字1~n
    {
        if(vis[i] == false) //还没有用过
        {
            vis[i] = true;
            path[u] = i; //填上坑位u
            dfs(u+1);
            //恢复现场
            vis[i] = false;
            path[u] = 0; //可不做
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    //统一基于1的索引
    dfs(1);
    return 0;
}