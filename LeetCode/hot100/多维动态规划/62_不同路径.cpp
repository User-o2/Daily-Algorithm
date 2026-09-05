/*
https://leetcode.cn/problems/unique-paths/?envType=study-plan-v2&envId=top-100-liked

【多维动态规划】
1.状态定义：f[i][j]定义为到达(i,j)存在的所有路径数目。
2. 状态转移：f[i][j] = f[i][j-1]+f[i-1][j]
3. 这道题也可以使用[组合数学]直接求解：C(m-1+n-1, m-1)
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m,vector<int>(n,0));

        //base case
        for(int i = 0; i < m; i ++)
            f[i][0] = 1;
        for(int i = 0; i < n; i ++)
            f[0][i] = 1;
        
        for(int i = 1; i < m; i ++)
        {
            for(int j = 1; j < n; j ++)
            {
                f[i][j] = f[i][j-1] + f[i-1][j];
            }
        }
        return f[m-1][n-1];
    }
};