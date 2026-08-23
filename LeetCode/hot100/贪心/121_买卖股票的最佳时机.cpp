/*
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-100-liked

【贪心】
肯定是低价买入、高价卖出。
一个很自然的想法就是，从左到右枚举每一个买入的价格，然后向后枚举卖出的价格，时间复杂度是O(N^2)
如何优化：
从左向右枚举每一个**卖出的价格**，同时从左向右枚举的时候，顺便维护一个最小的买入价格，这样时间复杂度就来到了O(N)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //由于不能当天买入、当天卖出，所以第一天不能卖出
        int res = 0, min_price = prices[0];
        for(int i = 1; i < prices.size(); i ++) //从第二天开始遍历
        {
            res = max(res,prices[i]-min_price); //本天卖出
            min_price = min(min_price,prices[i]); //更新最少买入价格
        }
        return res;
    }
};