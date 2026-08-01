/*
https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/?envType=study-plan-v2&envId=top-100-liked

【二分】
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        if(!nums.size())
            return res;

        //首先来找第一个位置，也就是找左侧第一个 >= target 的位置
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = l+r >> 1;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid+1;
        }
        if(nums[l] != target)
            return res;
        res[0] = l;
        
        //第二个位置，也就是找右侧第一个 <= target 的位置
        l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = l+r+1 >> 1;
            if(nums[mid] <= target)
                l = mid;
            else
                r = mid-1;
        }
        res[1] = l;
        return res;
    }
};