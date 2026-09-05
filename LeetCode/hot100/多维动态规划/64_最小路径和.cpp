/*
https://leetcode.cn/problems/minimum-path-sum/?envType=study-plan-v2&envId=top-100-liked

【多维动态规划】
1.状态定义：f[i][j]表示从左上角(0,0)到达(i,j)的最小路径总和
2.状态转移：f[i][j] = min(f[i][j-1],f[i-1][j])+grid[i][j]
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); //m行n列
        vector<vector<int>> f(m,vector<int>(n,0));

        //base case：先填充边界
        f[0][0] = grid[0][0];
        for(int i = 1; i < m; i ++)
            f[i][0] = f[i-1][0] + grid[i][0];
        for(int i = 1; i < n; i ++)
            f[0][i] = f[0][i-1] + grid[0][i];
        
        for(int i = 1; i < m; i ++)
            for(int j = 1; j < n; j ++)
                f[i][j] = min(f[i][j-1],f[i-1][j]) + grid[i][j];
        return f[m-1][n-1];
    }
};