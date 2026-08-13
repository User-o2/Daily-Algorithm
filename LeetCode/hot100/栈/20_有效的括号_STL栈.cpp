/*
https://leetcode.cn/problems/valid-parentheses/?envType=study-plan-v2&envId=top-100-liked

【STL栈】
这个有效字符串本质上就是判定：
是否可以通过反复消除字符串中相邻的匹配括号对，最终能将字符串彻底清空。
“相邻消消乐”
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char,char> match = {{'(',')'}, {'{','}'}, {'[',']'}}; //左括号->右括号

        for(int i = 0; i < s.size(); i ++)
        {
            if(match.count(s[i])) //1.是左括号，入栈
                stk.push(s[i]);
            else //2.是右括号
            {
                if(stk.empty() || match[stk.top()]!=s[i]) //栈空或者栈顶不匹配
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};