/*
https://leetcode.cn/problems/palindrome-partitioning/?envType=study-plan-v2&envId=top-100-liked

DFS-【二叉树模型】：割与不割
*/
class Solution {
public:
    vector<vector<string>> res;
    vector<bool> sta = vector<bool>(20,false);

    bool check(string& str)
    {
        if(str.size()==1)
            return true;
        
        bool sta = true;
        int l = 0, r = str.size()-1;
        while(l < r)
        {
            if(str[l] == str[r])
            {
                l ++;
                r --;
            }
            else
            {
                sta = false;
                break;
            }
        }
        return sta;
    }
    void dfs(string& s, int u) //u是遍历到的位置
    {
        if(u == s.size()-1)
        {
            vector<string> path;
            string sub_str = "";
            //遍历这一种分割的方式
            bool succeed = true;
            for(int i = 0; i < s.size(); i ++)
            {
                sub_str += s[i];
                if(sta[i]) //割
                {
                    if(check(sub_str)) //是回文
                    {
                        path.push_back(sub_str);
                        sub_str = "";
                    }
                    else //这种分割方式存在非回文子串，直接作废
                    {
                        succeed = false;
                        break;
                    }
                }
            }
            //处理最后的子串，因为最后sta[s.size()-1]一定是false
            if(sub_str.size() && check(sub_str))
                path.push_back(sub_str);
            else
                succeed = false;

            if(succeed)
                res.push_back(path);
            return;
        }

        //割
        sta[u] = true;
        dfs(s,u+1);
        sta[u] = false;

        //不割
        dfs(s,u+1);
    }

    vector<vector<string>> partition(string s) {
        dfs(s,0);
        return res;
    }
};