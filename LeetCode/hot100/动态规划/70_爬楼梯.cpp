/*
https://leetcode.cn/problems/climbing-stairs/?envType=study-plan-v2&envId=top-100-liked

【动态规划】
定义f[i]为到达第i个台阶的方法数量。则f[n]即为答案
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n+1);
        
        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i <= n; i ++)
            f[i] = f[i-1] + f[i-2];
            //到达第i个台阶的方法数量 = 到达第i-1个台阶的方法数量（然后再跳一步）+到达第i-2个台阶的方法数量（然后再跳两步）
        return f[n];
    }
};