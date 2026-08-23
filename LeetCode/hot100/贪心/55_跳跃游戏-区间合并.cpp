/*
https://leetcode.cn/problems/jump-game/?envType=study-plan-v2&envId=top-100-liked

【贪心-区间合并】
可以将每个点以及可以到达的下标合成一个区间，这样的话，合并所有区间，如果最后合并成了一个区间就可以到达，否则就不能到达。
时间复杂度O(N)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<pair<int,int>> p;
        
        int n = nums.size();
        for(int i = 0; i < n; i ++)
            p.push_back({i,i+nums[i]}); //区间已经按照左端点排序
        
        int cnt = 1; //合并后的区间个数
        int l = p[0].first, r = p[0].second;
        for(int i = 1; i < n; i ++)
        {
            if(p[i].first <= r) //可以合并
                r = max(r,p[i].second);
            else
            {
                l = p[i].first;
                r = p[i].second;
                cnt ++;
            }
        }
        return cnt>1 ? false : true;
    }
};