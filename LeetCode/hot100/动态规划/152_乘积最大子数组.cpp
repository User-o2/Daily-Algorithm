/*
https://leetcode.cn/problems/maximum-product-subarray/?envType=study-plan-v2&envId=top-100-liked

【动态规划】
1.状态定义：
- f_max[i]：以nums[i]为结尾的连续子数组的最大乘积值
- f_min[i]：以nums[i]为结尾的连续子数组的最小乘积值
2. 状态转移：
设nums[i]=x，对于x有两种策略：
- 和前面拼接。也就是在“以nums[i-1]为结尾的子数组”后面拼接上x
- 不和前面拼接。也就是x单开为一个新的子数组
分类讨论：
（1）当x>0，f_max[i]=max(x,x*f_max[i-1]);f_min[i]=min(x,x*f_min[i-1])
（2）当x<0，f_max[i]=max(x,x*f_min[i-1]);f_max[i]=min(x,x*f_max[i-1])
（3）当x=0,f_max[i]=f_min[i]=0
代数统一：
f_max=max(x,x*f_max[i-1],x*f_min[i-1])
f_max=min(x,x*f_max[i-1],x*f_min[i-1])
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> f_max(n),f_min(n);
        
        //base case：根据状态定义
        f_max[0] = f_min[0] = nums[0];
        for(int i = 1; i < n; i ++)
        {
            int x = nums[i];
            //维护状态转移
            f_max[i] = max({x,x*f_max[i-1],x*f_min[i-1]}); //C++11支持max({a,b,c,...})
            f_min[i] = min({x,x*f_max[i-1],x*f_min[i-1]});
        }

        int res = -2e9;
        for(int i = 0; i < n; i ++) //以任意一个元素结尾均有可能成为答案
            res = max(res, f_max[i]);
        return res;
    }
};