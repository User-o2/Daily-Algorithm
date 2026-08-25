/*
https://leetcode.cn/problems/majority-element/?envType=study-plan-v2&envId=top-100-liked

技巧：【摩尔投票法】
绝对众数，即题目中的“多数元素”，在数组中出现的次数严格大于⌊ n/2 ⌋

1.设数组 A 的长度为 n，其中元素 M 的出现频数满足 freq_A(M) > n/2（即 M 为绝对众数）。
若从 A 中同时移除两个互不相同的元素 x 与 y（x ≠ y），得到长度为 n-2 的新数组 A'，则在 A' 中，M 依然满足多数元素性质，即：
freq_A'(M) > (n-2)/2。这个是可以证明的。
2.既然绝对众数比其他所有元素出现次数之和都要多，那么想象一下极端情况：其他所有元素联合起来去打这个绝对众数，也是打不过的。所以使用“不同的两个数两两相消”的策略，最后剩余的那个数一定是绝对众数。
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x = 0, hp = 0;
        for(int i = 0; i < n; i ++)
        {
            if(hp == 0) //上一个擂主已经没血了
            {
                x = nums[i];
                hp = 1;
            }
            else //擂主还有血
            {
                if(x == nums[i]) //支援回血
                    hp ++;
                else
                    hp --;
            }
        }
        //如果数组中不一定存在这个绝对众数，还需要检验一下最后的 x 出现次数是否严格大于 n/2。
        return x;
    }
};