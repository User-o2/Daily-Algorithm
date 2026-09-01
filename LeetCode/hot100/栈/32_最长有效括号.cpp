/*
https://leetcode.cn/problems/longest-valid-parentheses/?envType=study-plan-v2&envId=top-100-liked

【栈】
“括号匹配”类问题，可以尝试使用栈来求解。
思路：
- 栈中存储的是索引。遇到左括号直接入栈，遇到右括号出栈，还是采用“相邻相消”的策略
- 可以理解为栈中存储的是“最长有效括号的前一个索引”，可以理解为维护**有效括号的边界**。栈中存储的有两种索引：1)左括号的索引；2)有效括号的边界索引（无效右括号的索引）。可以根据“出栈之后栈是否为空”来判断有效括号的情况。

复习关于模拟栈的方式，不要用stack：
- vector模拟栈，.back()访问栈顶，.push_back()入栈，.pop_back()出栈
- 普通数组+tt=-1指针模拟栈，stk[tt]访问栈顶，stk[++tt]=x入栈，tt--出栈
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stk; //TODO:我习惯使用vector（核心代码模式）和普通数组（acm模式）来模拟栈，而不习惯使用STL的stack，是否推荐？
        stk.push_back(-1); //初始哨兵，初始的边界索引

        int res = 0;
        for(int i = 0; i < s.size(); i ++)
        {
            if(s[i] == '(') //1.遇到左括号直接入栈
                stk.push_back(i);
            else //2.遇到右括号
            {
                int idx = stk.back(); //可能是配对的左括号，也可能是边界
                stk.pop_back();

                if(stk.empty()) //pop之后栈为空，说明当前右括号是无效括号、弹出的是有效括号的边界
                    stk.push_back(i); //重新将当前无效的右括号索引入栈，作为新的有效括号边界
                else //pop之后栈不空，说明弹出的是配对的左括号索引，使用栈顶更新res
                    res = max(res,i-stk.back());
                /*
                执行 pop() 后如果栈不空，st.top()百分之百必然是有效边界：
                - 如果左边还有没匹配的左括号，st.top() 就是那个紧挨着当前合法串左边的未匹配左括号索引
                - 如果左边没有多余的左括号了，st.top() 就是哨兵 -1或某个多余的无效右括号索引
                */
            }
        }
        return res;
    }
};