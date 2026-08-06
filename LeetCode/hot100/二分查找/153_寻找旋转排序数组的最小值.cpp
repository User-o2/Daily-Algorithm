/*
https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/?envType=study-plan-v2&envId=top-100-liked

【二分】
解题思路：
使用二分找到最小值的索引（也是两个有序区间的边界），然后输出即可
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        
        //二分寻找最小值索引（适配边界情况 edge case）
        while(l < r)
        {
            int mid = l+r >> 1;
            if(nums[mid] <= nums[n-1])
                r = mid;
            else
                l = mid+1;
        }
        return nums[l]; //返回最小值

        // 这种写法为何适配边界情况：
        // if(l == 0) //表示完整的有序数组
        //     return nums[0];
        // else //分为[0,l-1],[l,n-1]
        //     return nums[l]; //右边区间的右端点就是最小值
    }
};