/*
https://leetcode.cn/problems/search-in-rotated-sorted-array/?envType=study-plan-v2&envId=top-100-liked

【二分】
看题解、优化代码：
1.找到两个区间分界点的方式：找到最小值的下标从“以nums[0]作为比较对象”转为“以nums[n-1]”作为比较对象
2. 确定要去寻找的区间，这样的话边界情况下l=0可以兜底
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n)
            return -1;
        
        //首先去寻找旋转的边界：nums最小值的下标
        int l = 0, r = n-1;
        while(l < r)
        {
            int mid = l+r >> 1;
            if(nums[mid] <= nums[n-1])
                r = mid;
            else
                l = mid+1;
        }
        //这种写法也适配k=0，也就是等价于没有旋转的情况->找到0
        //这种写法，在边界情况下l=0，一定可以访问nums[l]兜底 -> 不用担心边界情况会越界

        int idx = l; //然后就拆分为[0,idx-1],[idx,n-1]两部分
        if(target <= nums[n-1]) //去[idx,n-1]找
            l = idx, r = n-1;
        else //去[0,idx-1]找
            l = 0, r = idx-1;
        while(l < r)
        {
            int mid = l+r >> 1;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid+1;
        }
        return nums[l] == target ? l : -1;
    }
};