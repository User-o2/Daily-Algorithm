/*
https://leetcode.cn/problems/valid-parentheses/?envType=study-plan-v2&envId=top-100-liked

【数组模拟栈】
这个有效字符串本质上就是判定：
是否可以通过反复消除字符串中相邻的匹配括号对，最终能将字符串彻底清空。
“相邻消消乐”
*/
class Solution {
public:
    bool isValid(string s) {
        int top = 0;
        vector<char> stk(s.size()+10);
        map<char,char> match = {{'(',')'}, {'{','}'}, {'[',']'}}; //左括号->右括号
        
        //API设计思想，对齐STL接口
        auto my_push = [&](char c) -> void
        {
            stk[++top] = c;
        };
        auto my_pop = [&]() -> void
        {
            top--;
        };
        auto my_top = [&]() -> char
        {
            return stk[top];
        };

        for(int i = 0; i < s.size(); i ++)
        {
            if(match.count(s[i])) //1.遇到左括号，入栈
                my_push(s[i]);
            else //2.遇到右括号，出栈匹配
            {
                if(top <= 0 || match[my_top()]!=s[i]) //栈空或者不匹配
                    return false;
                else
                    my_pop();
            }
        }
        return top>0 ? false : true;
    }
};