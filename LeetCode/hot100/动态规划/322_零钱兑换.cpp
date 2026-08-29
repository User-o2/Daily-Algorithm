/*
https://leetcode.cn/problems/coin-change/?envType=study-plan-v2&envId=top-100-liked

【动态规划】
- 状态定义：f[i]表示凑出金额i所需要的最少硬币个数
- 状态转移：f[i] = min(f[i-coin_1]+1, f[i-coin_2]+1, ...)
- 也就是：“凑出金额i所需要的最少硬币个数” = min{“凑出金额i-coin_1所需要的最少硬币个数+1”, “凑出金额i-coin_2所需要的最少硬币个数+1”, ...}
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount+1,2e9); //最小值的初始化

        f[0] = 0; //边界：凑出金额0所需要的最少硬币个数为0
        for(int i = 1; i <= amount; i ++)
        {
            //所有硬币都可以尝试凑一下
            for(int j = 0; j < coins.size(); j ++)
            {
                if(i-coins[j] >= 0) //可以凑
                    f[i] = min(f[i], f[i-coins[j]]+1);
            }
        }
        return f[amount]>amount ? -1 : f[amount];
    }
};