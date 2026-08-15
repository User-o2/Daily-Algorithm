/*
https://www.acwing.com/problem/content/description/830/

【数组模拟栈】
*/
#include<iostream>
#include<string>
using namespace std;

const int N = 100010;
int stk[N];
int top;

// API 设计原则：对齐STL接口
void my_push(int x)
{
    stk[++top] = x;
}
void my_pop()
{
    top --;
}
int my_top()
{
    return stk[top];
}
bool my_empty()
{
    return top<=0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t --)
    {
        string opt;
        cin >> opt;
        if(opt == "push")
        {
            int x;
            cin >> x;
            my_push(x);
        }
        else if(opt == "pop")
        {
            my_pop();
        }
        else if(opt == "empty")
        {
            cout << (my_empty() ? "YES" : "NO") << "\n";
        }
        else
            cout << my_top() << "\n";
    }
    return 0;
}