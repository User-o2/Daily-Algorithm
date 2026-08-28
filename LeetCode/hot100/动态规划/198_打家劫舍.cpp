/*
https://leetcode.cn/problems/house-robber/?envType=study-plan-v2&envId=top-100-liked

【动态规划】
也就是求“间隔最大和”的问题。
- 将f[i]定义为：考虑前i个数字得到的间隔最大和的值。则f[n]即为答案。
- 状态转移方程：f[i] = max(f[i-1],f[i-2]+nums[i-1]) //第i个数字为nums[i-1]
- 也就是“考虑前i个数字得到的间隔最大和的值”=max{“不选第i个数字，考虑前i-1个数字得到的间隔最大值”，“选第i个数字+考虑前i-2个数字得到的间隔最大值”}
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n+1); //动态规划注意1：开n+1！

        f[1] = nums[0];
        for(int i = 2; i <= n; i ++)
            f[i] = max(f[i-2]+nums[i-1],f[i-1]); //注意nums[]和f[]的索引是错位的
        return f[n];
    }
};