/*
https://leetcode.cn/problems/median-of-two-sorted-arrays/?envType=study-plan-v2&envId=top-100-liked

【双指针】时间复杂度 O(n+m)
找到两个正序数组的中位数，即找到合并后数组第k小的数。其中大概有k=(n+m)/2。
- (n+m)%2==0：目标为(merge[(n+m)/2]+merge[(n+m)/2-1])/2
- (n+m)%2==1：目标为merge[(n+m)/2]

既然两个数组已经是排好序的，只需要利用归并排序的思想，使用 O(n+m) 的时间复杂度，完成两个数组的有序合并，然后区目标索引即可。
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //归并排序：双指针实现[0,n-1],[0,m-1]合并两个子数组
        int n = nums1.size(), m = nums2.size();
        int q = n+m;
        vector<int> tmp(q);

        int i = 0, j = 0;
        int k = 0;
        while(i < n && j < m)
        {
            if(nums1[i] <= nums2[j])
                tmp[k++] = nums1[i++];
            else
                tmp[k++] = nums2[j++];
        }
        while(i < n)
            tmp[k++] = nums1[i++];
        while(j < m)
            tmp[k++] = nums2[j++];
        
        //tmp[]完成了有序合并
        if(q % 2 == 0)
            return double(tmp[q/2]+tmp[q/2-1]) / 2;
        else
            return double(tmp[q/2]);
    }
};