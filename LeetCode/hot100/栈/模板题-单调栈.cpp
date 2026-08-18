/*
https://www.acwing.com/problem/content/832/

【单调栈】-模板题
寻找左边第一个较小的数
- 从左向右遍历
- 栈中维护的是答案序列：如果栈顶元素>=当前遍历到的元素，则栈顶不可能是答案，出栈
*/
#include<iostream>
using namespace std;

const int N = 100010;
int a[N];
int stk[N],top;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    
    //从左向右遍历
    for(int i = 0; i < n; i ++)
    {
        //1.栈顶删除
        while(top && a[stk[top]]>=a[i])
            top--;
        if(top)
            cout << a[stk[top]] << " ";
        else
            cout << "-1 ";
        
        //2.栈顶插入
        stk[++top] = i;
    }
    return 0;
}