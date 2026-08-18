/*
https://leetcode.cn/problems/decode-string/?envType=study-plan-v2&envId=top-100-liked

【双栈法】
因为C++的强类型特性，单栈无法同时存储string和int
有点像是中缀表达式求值。感觉就是“试”出两个栈分别用来存什么
观察特点：
1. 数字之后一定是[]
2. 没有1[]这种格式

规则：
1. 遇到数字：直接存stk_num
2. 遇到字母或者左括号：直接存stk_alpha
3. 遇到右括号，弹出结算：stk_alpha不断弹出，直到遇到左括号；stk_num弹出一个倍数进行复制操作

最后stk_alpha里面连接起来就是答案
*/
class Solution {
public:
    string decodeString(string s) {
        vector<string> stk_alpha;
        vector<int> stk_num;

        auto repeat = [](string str, int k)
        {
            string res = "";
            res.reserve(str.size()*k);
            for(int i = 0; i < k; i ++)
                res += str;
            return res;
        };

        int n = s.size();
        for(int i = 0; i < n; i ++) //遍历表达式
        {
            if(isdigit(s[i])) //1.遇到数字，提取完整之后进栈
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
            else if(isalpha(s[i])) //2.遇到字母，提取完整之后进栈
            {
                int j = i;
                while(j<n && isalpha(s[j]))
                    j ++;
                stk_alpha.push_back(s.substr(i,j-i));
                i = j-1;
            }
            else if(s[i] == '[') //3.遇到左括号，直接进栈
                stk_alpha.push_back("[");
            else //4.遇到右括号，不断弹出字符串进行拼接，直到遇到左括号；然后弹出倍数进行复制
            {
                string res_str = "";
                while(stk_alpha.size() && stk_alpha.back()!="[")
                {
                    res_str = stk_alpha.back() + res_str; //从前面接上
                    stk_alpha.pop_back();
                }
                stk_alpha.pop_back(); //弹出左括号

                int k = stk_num.back();
                stk_num.pop_back();
                stk_alpha.push_back(repeat(res_str,k));
            }
        }

        //最后接在一起
        string res = "";
        for(int i = 0; i < stk_alpha.size(); i ++)
            res += stk_alpha[i];
        return res;
    }
};