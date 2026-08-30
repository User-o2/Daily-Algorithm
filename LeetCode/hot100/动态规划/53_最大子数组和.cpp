/*
https://leetcode.cn/problems/maximum-subarray/

【动态规划】最大子数组和
1.状态定义：f[i]为以nums[i]为结尾的连续子数组的最大和
2.状态转移：
设x=f[i]，则x有两种转移状态：
- 接在历史子数组后面。即“以nums[i-1]为结尾的连续子数组的最大和”+x
- 不接在历史子数组后面。x作为新开的一个连续子数组

分类讨论：
当f[i-1]>0，要拼起来：f[i] = f[i-1]+x
当f[i-1]<=0，不用拼了：f[i] = x
其实不需要if-else分类讨论，直接取两种转移状态的最大值即可。代数统一为：f[i] = max(x,x+f[i-1])
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);

        //base case：根据定义即可
        f[0] = nums[0];
        for(int i = 1; i < n; i ++)
            f[i] = max(nums[i], nums[i]+f[i-1]);
        
        int res = -2e9;
        for(int i = 0; i < n; i ++) //max{以任意元素结尾的最大和}
            res = max(res, f[i]);
        return res;
    }
};