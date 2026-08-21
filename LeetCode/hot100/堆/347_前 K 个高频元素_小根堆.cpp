/*
https://leetcode.cn/problems/top-k-frequent-elements/?envType=study-plan-v2&envId=top-100-liked

【哈希表+小根堆】
1.要求前K个出现次数最多的元素，首先使用哈希表统计次数；
2.然后手动维护一个大小为k的小根堆：
- 为什么维护小根堆：求前K个次数最大，因为小根堆pop()出去的一定是K个中最小的那个，遍历一遍哈希表之后，留下的一定是最大的K个
时间复杂度：O(n·logk)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int n = nums.size();
        for(int i = 0; i < n; i ++)
            count[nums[i]] ++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //默认是大根堆，这里使用greater<Type>初始化为小根堆
        for(auto& x : count) //NOTE：map或者unordered_map遍历得到的x是一个pair，而不是key
        {
            pq.push({x.second,x.first}); //注意存入的顺序{次数，值}
            if(pq.size() > k) //手动限制大小，维护一个大小为k的堆
                pq.pop();
        }

        vector<int> res;
        for(int i = 0; i < k; i ++)
        {
            res.push_back(pq.top().second); //存入的是值
            pq.pop();
        }
        return res;
    }
};