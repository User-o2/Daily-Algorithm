/*
https://leetcode.cn/problems/palindrome-partitioning/?envType=study-plan-v2&envId=top-100-liked

DFS-【二叉树模型】：割与不割
优化代码实现：提前剪枝
*/
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool check(string& s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] == s[r])
            {
                l ++;
                r --;
            }
            else
                return false;
        }
        return true;
    }
    void dfs(string& s, int st, int u) //从st开始的子串，开始判断u处是否切割
    {
        if(u == s.size())
        {
            res.push_back(path);
            return;
        }

        //不割
        if(u < s.size()-1)
            dfs(s,st,u+1);

        //割
        if(check(s,st,u))
        {
            path.push_back(s.substr(st,u-st+1));
            dfs(s,u+1,u+1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s,0,0);
        return res;
    }
};