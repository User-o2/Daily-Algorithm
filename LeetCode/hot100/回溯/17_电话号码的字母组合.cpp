/*
https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-100-liked

DFS-【N叉树模型】
填坑思想求解即可
*/
class Solution {
public:
    string mp[10] = {"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    vector<string> res;
    string path = "";
    void dfs(string& digits, int u)
    {
        if(u == digits.size()) //填坑
        {
            res.push_back(path);
            return;
        }
        
        string& cur_str = mp[digits[u]-'0'];
        for(int i = 0; i < cur_str.size(); i ++)
        {
            path.push_back(cur_str[i]);
            dfs(digits,u+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return res;

        dfs(digits,0);

        return res;
    }
};