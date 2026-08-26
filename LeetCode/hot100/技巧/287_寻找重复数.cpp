/*
https://leetcode.cn/problems/find-the-duplicate-number/?envType=study-plan-v2&envId=top-100-liked

【寻找重复数】
题目信息；数组包含n+1个整数，每个整数的取值范围严格在[1,n]之内
要求：不修改原数组、O(1)空间复杂度
方法：二分查找-值域二分
将元素的值域分为两个区间：[1,mid]（最大容量为mid个不同的数）, [mid+1,n]（最大容量为n-mid个不同的数）。

【证明】
那么就存在两种情况：
- 重复数字的值落在[1,mid]：那么值在[mid+1,n]内的数字一定没有重复 => 则值在[mid+1,n]内的数字个数一定小于等于最大容量n-mid => 又数字个数固定为n+1，所以值在[1,mid]内的数字个数一定大于等于n+1-(n-mid)=mid+1，也就是严格大于mid
- 重复数字的值落在[mid+1,n]：那么值在[1,mid]内的数字一定没有重复 => 则值在[1,mid]内的数字个数一定小于等于最大容量mid => 又数字个数固定为n+1，所以值在[mid+1,n]内的数字个数一定大于等于n+1-mid，也就是严格大于n-mid
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1; //数字值域范围[1,n]，n+1个数

        int l = 1, r = n; //值域的范围[1,n]
        while(l < r)
        {
            int mid = l+r >> 1;
            int cnt = 0;
            for(int i = 0; i < nums.size(); i ++)
            {
                if(nums[i] <= mid) //统计值域在[1,mid]中的数字
                    cnt ++;
            }
            //属于比较抽象的check条件
            if(cnt > mid) //值在[1,**mid**]内的数字个数严格大于**mid**，说明重复数字的值域在[1,mid]区间
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};