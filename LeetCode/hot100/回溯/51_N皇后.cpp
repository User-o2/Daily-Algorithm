/*
https://leetcode.cn/problems/n-queens/description/?envType=study-plan-v2&envId=top-100-liked

【DFS- N叉树模型】N皇后问题
注意到，一行必定会放置且只放置一个皇后，所以对于每一行，去搜索列即可
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        vector<int> col(n,0);
        vector<int> dis(2*n,0), udis(2*n,0);
        vector<string> mp(n,string(n,'.'));
        
        auto dfs = [&](this auto&& dfs, int u) //开始搜索第u行
        {
            if(u == n) //找到一个解
            {
                res.push_back(mp);
                return;
            }

            //遍历本行的所有可能位置：每一列
            for(int i = 0; i < n; i ++)
            {
                if(col[i]==0 && dis[u+i]==0 && udis[u-i+n]==0)
                {
                    col[i] = dis[u+i] = udis[u-i+n] = 1;
                    mp[u][i] = 'Q';
                    dfs(u+1); //进入下一行
                    col[i] = dis[u+i] = udis[u-i+n] = 0;
                    mp[u][i] = '.';
                }
            }
        };

        dfs(0); //从第0行开始搜索
        return res;
    }
};