/*
https://leetcode.cn/problems/longest-common-subsequence/?envType=study-plan-v2&envId=top-100-liked

【多维动态规划】-最长公共子序列
1.状态定义：定义f[i][j]为考虑a的前i个字符[0:i-1]和b的前j个字符[0:j-1]，最长公共子序列的长度
2.状态转移：
- if(a[i-1] != b[j-1])：那么最长公共子序列中一定不会同时包含a[i-1]和b[j-1]。只需要考虑，最长公共子序列中：有a[i-1]无b[j-1]、无a[i-1]有b[j-1]、无a[i-1]无b[j-1]。则f[i][j] = max({f[i-1][j],f[i][j-1],f[i-1][j-1]}); 这里根据定义，一定有f[i-1][j-1]<=f[i-1][j],f[i-1][j-1]<=f[i][j-1]，所以max()中直接省略掉即可。
- if(a[i-1]==b[j-1])：那么直接f[i][j]=f[i-1][j-1]+1;
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1,0));

        //base case: f[i][0] = f[0][j] = 0;
        for(int i = 1; i <= n; i ++) //考虑a的前i个字符
        {
            for(int j = 1; j <= m; j ++) //考虑b的前j个字符
            {
                if(text1[i-1] == text2[j-1]) //当前字符，注意这里的索引是i-1,j-1
                    f[i][j] = f[i-1][j-1]+1;
                else
                    f[i][j] = max(f[i][j-1],f[i-1][j]);
            }
        }
        return f[n][m];
    }
};