/*
https://www.acwing.com/problem/content/description/3305/

中缀表达式求值-模拟栈的应用
记忆运算规则：
从左到右解析中缀表达式，
1. 遇到操作数，直接入栈
2. 遇到运算符，如果栈顶运算符的优先级>=当前运算符，不断结算，之后入栈当前运算符；否则直接入栈当前运算符
3. 遇到左括号，直接入栈
4. 遇到右括号，不断结算，直到栈顶运算符变为左括号，并弹出左括号
表达式遍历结束之后，清算运算符栈中残存的所有运算符。最终操作数栈顶就是运算结果。
*/
#include<iostream>
#include<cctype>
#include<map>
using namespace std;

const int N = 100010;
//双栈法：运算符和操作数
int stk_num[N],top_num;
char stk_opt[N];int top_opt;

void push_num(int x)
{
    stk_num[++top_num] = x;
}
void pop_num()
{
    top_num --;
}
void push_opt(char c)
{
    stk_opt[++top_opt] = c;
}
void pop_opt()
{
    top_opt --;
}
void caculate() //弹出一个运算符和两个操作数进行运算
{
    char opt = stk_opt[top_opt]; pop_opt();
    int b = stk_num[top_num]; pop_num();
    int a = stk_num[top_num]; pop_num();
    
    int res = 0;
    if(opt == '-')
        res = a-b;
    else if(opt == '+')
        res = a+b;
    else if(opt == '*')
        res = a*b;
    else
        res = a/b;
    push_num(res);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<char,int> pr = {{'+',1},{'-',1},{'*',2},{'/',2}}; //运算符的优先级
    
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i ++) //开始遍历每一个字符
    {
        if(isdigit(s[i])) //1.遇到操作数，将完整的操作数进栈
        {
            int j = i,res = 0;
            while(j<n && isdigit(s[j]))
            {
                res = res*10 + s[j]-'0';
                j ++;
            }
            push_num(res);
            i = j-1;
        }
        else if(pr.count(s[i])) //2.遇到运算符 TODO学习一下算法为什么work：因为表达式中的运算符一定和对应的两个操作数是紧挨着+使用运算优先级判断
        {
            while(top_opt>0 && stk_opt[top_opt]!='(' && pr[stk_opt[top_opt]]>=pr[s[i]]) //如果前面已经入栈的一个操作符优先级较高，就先结算前面的操作符
                caculate();
            push_opt(s[i]); //将此操作符入栈
        }
        else if(s[i] == '(') //3.遇到左括号，直接入栈
            push_opt(s[i]);
        else //4.遇到右括号，结算直到左括号
        {
            while(top_opt>0 && stk_opt[top_opt]!='(')
                caculate();
            pop_opt(); //左括号出栈
        }
    }
    while(top_opt > 0) //如果还有剩余的运算符，结算掉
        caculate();
    cout << stk_num[top_num] << "\n";
    return 0;
}