/*
https://leetcode.cn/problems/longest-increasing-subsequence/?envType=study-plan-v2&envId=top-100-liked

【动态规划】-最长上升子序列
1.状态定义：f[i]为以第i个数字为结尾的最长上升子序列的长度
2.状态转移：
f[i] = max{f[j] + 1},j<i && nums[j]<nums[i]
也就是遍历i的所有可能的前一个节点j，看i是否可以接在j的后面：“以第i个数字为结尾的最长上升子序列的长度” = max{“所有以第j个数字为结尾的最长上升子序列的长度”} + 1
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n+1,1); //初始化为1，最起码长度为1

        //f[1] = 1，以第一个数字结尾的最长上升子序列的长度为1
        for(int i = 2; i <= n; i ++) //f[i]，第i个数字
        {
            for(int j = 1; j < i; j ++) //从第1个数字开始，遍历结尾i所有可能的前一个数字（第j个数字）
            {
                if(nums[j-1] < nums[i-1]) //第i个数字nums[i-1]可以接在以第j个数字nums[j-1]为结尾的最长上升子序列的后面
                    f[i] = max(f[i], f[j]+1);
            }
        }

        int res = 0;
        for(int i = 1; i <= n; i ++)
            res = max(res,f[i]);
        return res; //以第几个数字结尾均有可能
    }
};