/*
https://www.acwing.com/problem/content/description/3305/

栈的应用：表达式求值
*/

#include<iostream>
#include<string>
#include<cctype> //c + char-type -> cctype
#include<stack>
using namespace std;

string s;
stack<int> num; //操作数
stack<char> opt; //运算符

int priority(char c) //运算符优先级
{
    if(c=='-' || c=='+')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else
        return 0; //左括号，右括号不会入栈
}

void eval() //弹出两个操作数和一个运算符进行计算
{
	//左结合律
    int b = num.top(); num.pop(); //先出栈的是右操作数
    int a = num.top(); num.pop(); //左操作数
    char c = opt.top(); opt.pop(); //运算符
    
    int res = 0;
    if(c == '*')
        res = a*b;
    else if(c == '/')
        res = a/b;
    else if(c == '+')
        res = a+b;
    else
        res = a-b;
        
    num.push(res);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i ++) //遍历每一个字符，可能是数字/操作符/左右括号
    {
    	char c = s[i];
    	
        if(isdigit(c)) //1.遇到数字：读完整个数，压入操作数栈
        {
            int res = 0;
            int j = i;
            while(j<n && isdigit(s[j])) //注意想好这个while的判断条件
            {
                res = res*10 + (s[j]-'0');
                j ++;
            }
            //最后要么j==n，要么s[j]不是数字
            num.push(res); //数字入栈
            i = j-1; //抵消掉i++
        }
        else if(c=='+' || c=='-' || c=='*' || c=='/') //2.遇到运算符
        {
        	//先把运算符栈顶中不是左括号、且优先级>=当前的运算符全部计算掉，再把当前运算符入栈
            //比较当前的运算符
            //只要前一个（栈顶）运算符优先级大，先结算
            while(opt.size() && opt.top()!='(' && priority(opt.top())>=priority(c))
                eval();
            opt.push(c); //然后入栈当前运算符
        }
        else if(c=='(') //3.遇到左括号
            opt.push(c); //直接入栈
        else //4.遇到右括号
        {
        	//进行括号内的结算，一直计算直到遇到左括号，然后弹出左括号
            while(opt.size() && opt.top()!='(')
                eval();
            opt.pop(); //左括号出栈
        }
    }
    
    //5.遍历完字符串，结算运算符栈中剩余的运算
    while(opt.size())
        eval();
    //6.最终计算结果一定是：运算符栈为空、操作数栈只剩一个数（最终答案）
    cout << num.top() << "\n";
    return 0;
}