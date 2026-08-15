/*
https://www.acwing.com/problem/content/description/3305/

栈的应用：中缀表达式求值
[手写数组模拟栈]版本
*/

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

const int N = 500010;
//栈顶指针为0表示栈为空
int num[N], top_num; //操作数
char opt[N]; //运算符
int top_opt; //注意栈顶指针不要开为char！
string str;

void push_num(int x)
{
    num[++top_num] = x;
}

void pop_num()
{
    if(top_num != 0)
        top_num --;
}

void push_opt(char c)
{
    opt[++top_opt] = c;
}

void pop_opt()
{
    if(top_opt != 0)
        top_opt --;
}


int pr(char c) //运算符的优先级
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/') //乘除的优先级为2
        return 2;
    else
        return 0;
}

void eval() //从num中弹出两个操作数，从opt中弹出一个运算符，进行运算
{
    int b = num[top_num]; pop_num();
    int a = num[top_num]; pop_num();
    char c = opt[top_opt]; pop_opt();
    
    int res = 0;
    if(c == '*')
        res = a*b;
    else if(c == '/')
        res = a/b;
    else if(c == '+')
        res = a+b;
    else
        res = a-b;
    push_num(res);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    int n = str.size();
    for(int i = 0; i < n; i ++) //开始遍历每一个字符，会遇到4种类型的符号
    {
        char c = str[i];
        if(isdigit(c)) //1.遇到的是数字
        {
            int res = 0;
            //双指针 拿到真实的操作数
            int j = i;
            while(j<n && isdigit(str[j]))
            {
                res = res*10 + str[j]-'0';
                j ++;
            }
            //while退出之后要么j==n要么str[j]不是数字
            push_num(res);
            i = j-1;
        }
        else if(c=='+' || c=='-' || c=='*' || c=='/') //2.遇到运算符
        {
            //不是'('并且前一个运算符的优先级高，需要结算
            while(top_opt && opt[top_opt]!='(' && pr(opt[top_opt])>=pr(c)) //需要结算运算才可将运算符push到stack
                eval();
            push_opt(c);
        }
        else if(c == '(') //3.遇到左括号，直接入栈！
            push_opt(c);
        else //4.遇到右括号-注意有括号无需进栈，直接结算到左括号
        {
            while(top_opt && opt[top_opt]!='(')
                eval();
            //while退出就是遇到左括号了，然后把左括号弹出
            pop_opt();
        }
    }
    
    //遍历完符号，如果opt还存在运算符，需要结算
    while(top_opt)
        eval();
    //最后留下的一个num的栈顶就是答案
    cout << num[top_num] << "\n";
    return 0;
}