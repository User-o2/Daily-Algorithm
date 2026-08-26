/*
https://leetcode.cn/problems/next-permutation/?envType=study-plan-v2&envId=top-100-liked

【下一个排列】模板题：std::next_permutation()的底层实现
[从右向左探测的三步法]

可以将这个问题描述为：
给定若干个数字，将其组合为一个整数。如何将这些数字重新排列，以得到[下一个][更大]的整数。
那么也就需要：
- 下一个数比当前更大
- 最小化下一个数的增量
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //1.从右向左寻找第一个相邻升序对(i,i+1)，使得nums[i]<nums[i+1]
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1])
            i --;
        if(i >= 0) //存在这样的升序对
        {
            //2.从右向左找第一个大于nums[i]的数 -> 必定落在区间[i+1,n-1]
            int j = n-1;
            while(j>=0 && nums[i]>=nums[j])
                j --;
            swap(nums[i],nums[j]);
        }
        //3.将nums[i+1,n-1]逆序
        reverse(nums.begin()+i+1, nums.end());
    }
};