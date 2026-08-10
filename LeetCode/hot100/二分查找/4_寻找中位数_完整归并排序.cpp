/*
https://leetcode.cn/problems/median-of-two-sorted-arrays/?envType=study-plan-v2&envId=top-100-liked

【完整归并排序写法】时间复杂度 O(n+m)log(n+m)
找到两个正序数组的中位数，即找到合并后数组第k小的数。其中大概有k=(n+m)/2。
- (n+m)%2==0：目标为(merge[(n+m)/2]+merge[(n+m)/2-1])/2
- (n+m)%2==1：目标为merge[(n+m)/2]
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> num;
        for(int i = 0; i < n; i ++)
            num.push_back(nums1[i]);
        for(int i = 0; i < m; i ++)
            num.push_back(nums2[i]);

        //归并排序，将数组区间[l,r]排序
        vector<int> tmp(n+m);
        auto mergeSort = [&](this auto&& self, int l ,int r){
            if(l >= r)
                return;
            int mid = l+r >> 1; //[l,mid],[mid+1,r]
            self(l,mid);
            self(mid+1,r);

            //现在可以认为两个子数组均为有序的
            int k = l;
            int i = l, j = mid+1;
            while(i <= mid && j <= r)
            {
                if(num[i] <= num[j])
                    tmp[k ++] = num[i ++];
                else
                    tmp[k ++] = num[j ++];
            }
            while(i <= mid)
                tmp[k ++] = num[i ++];
            while(j <= r)
                tmp[k ++] = num[j ++];
            
            //使得[l,r]有序之后，拷贝回原数组
            for(int i = l; i <= r; i ++)
                num[i] = tmp[i];
        };
        mergeSort(0,n+m-1);

        if((n+m) % 2 == 0)
            return double(num[(n+m)/2] + num[(n+m)/2-1]) / 2;
        else
            return double(num[(n+m)/2]);
    }
};