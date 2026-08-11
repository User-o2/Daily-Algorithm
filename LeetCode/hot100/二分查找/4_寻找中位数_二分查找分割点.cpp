/*
https://leetcode.cn/problems/median-of-two-sorted-arrays/?envType=study-plan-v2&envId=top-100-liked

【二分查找】时间复杂度 O(log(n+m))
回到中位数的本质：就是可以将所有数字分为左、右数量相等（或差1）的数。
- 我们需要分别在两个子数组中找到一个“分割点”，分为两组。使得左侧部分的数组元素数量等于右侧元素数量（或多1）。
- 那么就可以在任意数组的一侧进行二分查找，查找切割点所在的位置，那么在另一子数组就确定了。
- check()函数：left2<=right1说明足足够大，可以继续向左推进切割点
- n+m为奇数，返回左侧组的最大值；n+m为偶数，返回（左侧组最大值+右侧组最小值）/2
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m)
            return findMedianSortedArrays(nums2,nums1);

        int p = n+m;
        int tar = (p+1)/2; //tar为左侧组需要分出的元素个数
        //(p+1)/2：当p为奇数，刚好左组多1个；当p为偶数，刚好左右两组对半分

        auto check = [&](int mid) -> bool
        {
            int result = tar-mid;
            int right1 = mid<n ? nums1[mid] : 2e9;
            int left2 = result-1>=0 ? nums2[result-1] : -2e9;
            return left2 <= right1; //表示right1足够大，可以再小一点
        };

        int l = 0, r = n; //表示在索引元素的左侧切割
        while(l < r)
        {
            int mid = l+r >> 1;
            if(check(mid)) //分割点是唯一确定的，不具有单调性，需要注意check函数的写法
                r = mid;
            else
                l = mid+1;
        }

        //最后l就是找到的分割点，必然满足left1<=right2 && left2<=right1
        int result = tar-l;
        //需要处理边界情况
        int left1 = l-1>=0 ? nums1[l-1] : -2e9;
        int right1 = l<n ? nums1[l] : 2e9;
        int left2 = result-1>=0 ? nums2[result-1] : -2e9;
        int right2 = result<m ? nums2[result] : 2e9;
        if(p % 2 == 0)
            return double(max(left1,left2)+min(right1,right2))/2;
        else
            return double(max(left1,left2));
    }
};