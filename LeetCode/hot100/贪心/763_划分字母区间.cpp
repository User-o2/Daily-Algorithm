/*
https://leetcode.cn/problems/partition-labels/?envType=study-plan-v2&envId=top-100-liked

【贪心】
这道题目的本质是区间合并。
同一字母最多出现在一个片段中，并且划分的片段需要连续，那么就意味着：某个字母第一次出现的下标和最后一次出现的下标构成一个[区间]，并且这个区间必须在一个片段中。在这个片段中涉及到的其他字母，对应的区间也要在这个片段中。
那么其实就是区间的合并问题。
*/
class Solution {
public:
    vector<int> partitionLabels(string& s) {
        vector<bool> vis(26,false); //0-25
        vector<pair<int,int>> p;

        int n = s.size();
        for(int i = 0; i < n; i ++)
        {
            int idx = s[i]-'a';
            if(vis[idx] == false) //新的字母，左端点
            {
                vis[idx] = true;
                
                //寻找区间的右端点，从右向左数第一个就是
                for(int j = n-1; j >= 0; j --)
                {
                    if(s[j] == s[i])
                    {
                        p.push_back({i,j}); //[i,j]区间
                        break;
                    }
                }
            }
        }

        //找完所有的区间，已经自动按照左端点排序。进行区间合并
        vector<int> res;
        int l = p[0].first, r = p[0].second;
        for(int i = 1; i < p.size(); i ++)
        {
            if(p[i].first <= r) //可以合并
                r = max(r,p[i].second);
            else
            {
                res.push_back(r-l+1);
                l = p[i].first;
                r = p[i].second;
            }
        }
        res.push_back(r-l+1); //别忘了最后一个区间
        return res;
    }
};