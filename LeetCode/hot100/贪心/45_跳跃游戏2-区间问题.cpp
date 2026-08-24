/*
https://leetcode.cn/problems/jump-game-ii/?envType=study-plan-v2&envId=top-100-liked

【贪心-区间问题】
这个问题也可以转化为一个区间问题。
- 每一个索引及其对应的存储值其实就是构成了一个区间，题目说一定可以到达 n-1，那么说所有的索引对应的区间一定可以合并成一个区间，覆盖目标线段[0,n−1]。
- 题目所求的是到达 n-1 的最小跳跃次数，那么也就是：给定若干个区间，求最少需要多少个区间才能覆盖目标线段[0,n−1]。
- 所以就贪心地，每次取能够使得区间合并的、右端点的最大那个区间。
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;

        int res = 1; //n>1，最少需要一个区间
        //在可以合并的区间中找出右端点最大的那个
        int r = nums[0]; //当前[已合并区间]的右端点
        int nex_r = nums[0]; //在可合并的候选区间中，能到达的最远右边界
        for(int i = 1; i < n; i ++) //遍历每一个区间[i,i+nums[i]]
        {
            if(r >= n-1)
                return res;
            
            nex_r = max(nex_r,i+nums[i]);
            if(i == r) //遍历的区间即将超出当前已合并区间，接下来需要选出一个右端点最大的区间进行合并
            {
                res ++;
                r = nex_r;
            }
        }
        return 0; //兜底返回
    }
};