/*
https://leetcode.cn/problems/decode-string/?envType=study-plan-v2&envId=top-100-liked

【双栈法-待优化】

有点像是中缀表达式求值。感觉就是“试”出两个栈分别用来存什么
观察特点：
1. 数字之后一定是[]
2. 没有1[]这种，直接裸字母

规则：
1. 遇到数字：直接存stk_num
2. 遇到字母或者左括号：直接存stk_alpha
3. 遇到右括号，弹出结算：stk_alpha不断弹出，直到遇到左括号；stk_num弹出一个倍数
最后stk_alpha里面的就是答案
*/
class Solution {
public:
    string decodeString(string s) {
        //双栈法
        vector<int> stk_num;
        vector<string> stk_str;

        auto repeat = [](string str, int n) -> string
        {
            string res_str = "";
            res_str.reserve(str.size()*n);
            for(int i = 0; i < n; i ++)
                res_str += str;
            return res_str;
        };

        //从头到尾遍历s
        int n = s.size();
        for(int i = 0; i < n; i ++)
        {
            if(isdigit(s[i])) //1.遇到数字，找出完整的倍数数字，入栈
            {
                int j = i, res = 0;
                while(j<n && isdigit(s[j]))
                {
                    res = res*10 + s[j]-'0';
                    j ++;
                }
                stk_num.push_back(res);
                i = j-1;
            }
            else if(s[i] == '[') //2.遇到左括号，直接入栈
                stk_str.push_back("[");
            else if(isalpha(s[i])) //3.遇到字母，找出完整的字符串，入栈
            {
                int j = i;
                string res_str = "";
                while(j<n && isalpha(s[j]))
                {
                    res_str += s[j];
                    j ++;
                }
                i = j-1;
                stk_str.push_back(res_str);
            }
            else //4.遇到右括号，不断从stk_str弹出字符串，拼接；直到遇到左括号，并弹出左括号。然后从stk_num弹出一个执行复制操作
            {
                vector<string> tmp;
                while(stk_str.size() && stk_str.back()!="[")
                {
                    tmp.push_back(stk_str.back());
                    stk_str.pop_back();
                }
                stk_str.pop_back();

                string res_str = "";
                for(int j = tmp.size()-1; j >= 0; j --)
                    res_str += tmp[j];

                int num = stk_num.back(); stk_num.pop_back();
                stk_str.push_back(repeat(res_str,num));
            }
        }
        //返回答案
        string res = "";
        for(int i = 0; i < stk_str.size(); i ++)
            res += stk_str[i];
        return res;
    }
};