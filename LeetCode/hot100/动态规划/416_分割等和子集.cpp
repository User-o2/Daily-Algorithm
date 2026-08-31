/*
https://leetcode.cn/problems/partition-equal-subset-sum/?envType=study-plan-v2&envId=top-100-liked

【动态规划】分割等和子集
可以转为0-1背包问题。要求将数组分为两个子集，使得这两个子集的元素和相等，也就是：是否可以从数组中抽取一部分元素，使得元素之和等于Sum/2。
装满型0-1背包：背包的容积为Sum/2，每个物品的体积是数值，每个物品只能选一次。
每个物品测状态转移策略：选或不选。
1.状态定义：
定义f[i][j]为：从前i个物品中选，是否可以装满容积为j的背包{false,true}
2.base case：
f[0][j]=false，j>0
f[i][0]=true，i>=0，不选即可凑成0
3.状态转移：
每个物品可以选或不选。
- j>=nums[i]：背包容得下，可以选或不选，那么f[i][j] = f[i-1][j]（不选） || f[i-1][j-nums[i]]（选）
- j<nums[i]：背包容不下，只能不选，f[i][j] = f[i-1][j]
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        //剪枝
        if(n < 2)
            return false;
        int Sum = 0;
        for(int i = 0; i < n; i ++)
            Sum += nums[i];
        if(Sum % 2 == 1)
            return false;

        int m = Sum/2;
        vector<vector<bool>> f(n+1,vector<bool>(m+1,false));
        //base case
        f[0][0] = true; //f[0][j]=false，j>0

        for(int i = 1; i <= n; i ++) //f[i][]，从前i个物品[0:i-1]中选
        {
            for(int j = 0; j <= m; j ++)
            {
                //第i个元素选或不选
                if(j >= nums[i-1]) //NOTE:第i个元素是nums[i-1]
                    f[i][j] = f[i-1][j] || f[i-1][j-nums[i-1]];
                else
                    f[i][j] = f[i-1][j];
            }
        }
        return f[n][m];
    }
};