/*
https://leetcode.cn/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-100-liked

DFS-【二叉树模型】
填坑+二叉树+剪枝
*/
class Solution {
private:
    vector<string> res;
    string path;
    void dfs(int n, int l, int r, int u) //填坑+二叉树模型
    {
        if(u == 2*n)
        {
            res.push_back(path);
            return;
        }
        
        //左括号
        if(l < n)
        {
            path.push_back('(');
            dfs(n,l+1,r,u+1);
            path.pop_back();
        }
        if(r < n && r < l)
        {
            path.push_back(')');
            dfs(n,l,r+1,u+1);
            path.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return res;
        dfs(n,0,0,0);
        return res;
    }
};