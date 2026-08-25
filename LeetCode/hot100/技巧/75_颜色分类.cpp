/*
https://leetcode.cn/problems/sort-colors/?envType=study-plan-v2&envId=top-100-liked

【三色排序】：三指针扫描法
定义三个指针：
- p0：0要放置的位置
- cur：目前的探索指针
- p2：2要放置的位置

三个指针将整个数组序列分为了四个区域：
- [0,p0)：全是0
- [p0,cur)：全是1
- [cur,p2]：未知区域
- (p2,n-1]：全是2

初始化：
p0=0, cur=0, p2=n-1

规则：
- a[cur]==0：swap(a[p0],a[cur]); p0++; cur++; 为什么cur++呢？因为一定有p0==1。（根据区域定义）
- a[cur]==1：cur++;
- a[cur]==2：swap(a[p2],a[cur]); p2--; 因为p2所在的区域元素值未知，所以cur待在原地不动。
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, cur = 0, p2 = nums.size()-1;
        
        while(cur <= p2) //[cur,p2]是未知区域
        {
            if(nums[cur] == 0)
            {
                swap(nums[cur],nums[p0]);
                p0 ++;
                cur ++;
            }
            else if(nums[cur] == 1)
                cur ++;
            else
            {
                swap(nums[cur],nums[p2]);
                p2 --;
            }
        }
    }
};