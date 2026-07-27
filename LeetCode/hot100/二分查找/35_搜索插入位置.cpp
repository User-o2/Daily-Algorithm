/*
https://leetcode.cn/problems/search-insert-position/?envType=study-plan-v2&envId=top-100-liked

【二分查找-模板题】
下标型二分
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //寻找第一个>=target的元素
        int l = 0, r = nums.size();
        while(l < r)
        {
            int mid = (l+r)/2;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid+1;
        }
        //有可能都<target，不过自动处理了
        return l;
    }
};