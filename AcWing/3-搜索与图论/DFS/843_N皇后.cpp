/*
https://www.acwing.com/problem/content/845/
n皇后问题 - 本质上还是N叉树模型

因为任意两个皇后都不能处于同一行、同一列或同一斜线上
所以每一行必定只能有一个皇后，那么我们去遍历行即可。
每一行放置了一个皇后之后，就去遍历下一行
这样的遍历方式，直接保证了行与行之间不会冲突。还需要维护判断两个皇后不可以出现在同一列或同一斜线
*/
#include<iostream>
using namespace std;

const int N = 15;
int n;
char mp[N][N];
bool col[N],dg[2*N],udg[2*N];


void dfs(int u) //要遍历第u行
{
    if(u == n+1)
    {
        //直接输出棋盘
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= n; j ++)
                cout << mp[i][j];
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    //对于本行，每一列都是可能的放置点，所以遍历本行所有列
    for(int i = 1; i <= n; i ++)
    {
        if(col[i]==false && dg[u+i]==false && udg[u-i+n]==false)
        {
            //修改全局的维护状态
            col[i] = true;
            dg[u+i] = true;
            udg[u-i+n] = true;
            mp[u][i] = 'Q';
            
            dfs(u+1);
            
            col[i] = false;
            dg[u+i] = false;
            udg[u-i+n] = false;
            mp[u][i] = '.';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 1; i <= n; i ++) //基于1的索引
        for(int j = 1; j <= n; j ++)
            mp[i][j] = '.';
            
    dfs(1); //从第1行开始遍历
    
    return 0;
}