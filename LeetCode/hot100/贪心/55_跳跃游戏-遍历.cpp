/*
https://leetcode.cn/problems/jump-game/?envType=study-plan-v2&envId=top-100-liked

【贪心】
- 从前向后遍历每一个下标，并维护[可到达的最远下标]，既然可以到达这个最远下标，那么较近的那些下标就一定可以到达。
- 每到达一个下标，和[可到达的最远下标]进行比较。如果小于等于最远下标，那么就可以到达当前下标，然后继续更新[可到达的最远下标]。
- 遍历过程中可以返回 false，否则最后返回 true。
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_idx = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
            if(i > max_idx) //无法到达
                return false;
            max_idx = max(max_idx, i+nums[i]);
        }
        return true;
    }
};