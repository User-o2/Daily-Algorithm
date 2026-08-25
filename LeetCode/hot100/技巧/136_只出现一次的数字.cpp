/*
https://leetcode.cn/problems/single-number/?envType=study-plan-v2&envId=top-100-liked

【技巧】：异或运算
异或运算也称为不进位加法，满足的运算性质：
- X ^ X = 0
- X ^ 0 = X
- 满足交换律和结合律
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i ++)
            res ^= nums[i];
        return res;
    }
};