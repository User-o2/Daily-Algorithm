/*
https://leetcode.cn/problems/evaluate-reverse-polish-notation/
后缀表达式求值（逆波兰表达式）

后缀表达式的特点：两个操作数一定紧挨着他俩的运算符？
后缀表达式是无括号的？
所以算法流程是：使用一个操作数栈存储操作数，遇到运算符就弹出两个操作数进行结算
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) //注意这里的元素是string
    {
        vector<int> num(10010); //操作数栈
        int tt = 0;

        int n = tokens.size();
        for(int i = 0; i < n; i ++) //遍历整个表达式
        {
            string c = tokens[i];
            if(c=="+" || c=="-" || c=="*" || c=="/") //1.遇到运算符，直接弹出两个数字计算即可
            {
                int b = num[tt--]; //先出栈的是左操作数
                int a = num[tt--];

                int res = 0;
                if(c == "+")
                    res = a+b;
                else if(c == "-")
                    res = a-b;
                else if(c == "*")
                    res = a*b;
                else
                    res = a/b;
                num[++tt] = res;
            }
            else //2.遇到数字，直接入栈！
                //将string转为数字，注意需要防范负数的情况，所以直接使用stoi()最方便
                num[++tt] = stoi(c);
        }
        return num[tt];
    }
};