/*
https://leetcode.cn/problems/edit-distance/?envType=study-plan-v2&envId=top-100-liked

【动态规划】-最小编辑距离
给定两个单词a和b，返回将a转为b的最小编辑距离。
效果上，对a插入等价于对b删除、对a删除等价于对b插入，对a替换等价于对b替换。所以直接对a进行操作即可。
1.状态定义：定义f[i][j]表示将a的前i个字符[0:i-1]转为b的前j个字符[0:j-1]所需要的最短编辑距离。
2.状态转移：
- if(a[i-1]==b[j-1]): f[i][j] = f[i-1][j-1];
- if(a[i-1]!=b[j-1]): //可以选择对a插入/删除/替换
（1）插入：f[i][j] = f[i][j-1]+1
（2）删除：f[i][j] = f[i-1][j]+1
（3）替换：f[i][j] = f[i-1][j-1]+1
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1,0));

        //base case
        //f[0][0] = 0;
        for(int i = 1; i <= n; i ++)
            f[i][0] = i;
        for(int i = 1; i <= m; i ++)
            f[0][i] = i;
        
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                if(word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1];
                else
                    f[i][j] = min({f[i][j-1],f[i-1][j],f[i-1][j-1]}) + 1;
            }
        }
        return f[n][m];
    }
};