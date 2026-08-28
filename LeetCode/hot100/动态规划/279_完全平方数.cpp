/*
https://leetcode.cn/problems/perfect-squares/?envType=study-plan-v2&envId=top-100-liked

【动态规划】
- 定义f[i]为：和为i的完全平方数的最少数量
- 状态转移方程为：f[i] = min(f[i-1^1]+1, f[i-2^2]+1, ...)
- 也就是min(“和为i-1的完全平方数的最少数量 + 1”，和为i-2^2的完全平方数的最少数量 + 1，...)
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n+1,2e9);
        f[0] = 0;
        f[1] = 1;
        for(int i = 2; i <= n; i ++) //和为i的完全平方数的最少数量
        {
            for(int j = 1; j*j <= i; j ++)
            {
                f[i] = min(f[i],f[i-j*j]+1);
                //这里如果存在i==j*j，即i是一个完全平方数，直接f[i]=1
            }
        }
        return f[n];
    }
};