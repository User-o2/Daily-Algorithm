/*
https://leetcode.cn/problems/top-k-frequent-elements/?envType=study-plan-v2&envId=top-100-liked

【哈希表】
先使用哈希表记录，然后使用转为vector<pair>进行排序
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> count; //<值，次数>
        for(int i = 0; i < n; i ++)
            count[nums[i]] ++;

        vector<pair<int,int>> p(count.begin(),count.end());
        sort(p.begin(),p.end(),[](const pair<int,int>& a,const pair<int,int>& b)
        {
            if(a.second != b.second)
                return a.second > b.second;
            else
                return a.first > b.first;
        });

        vector<int> res;
        for(int i = 0; i < k; i ++)
            res.push_back(p[i].first);
        return res;
    }
};