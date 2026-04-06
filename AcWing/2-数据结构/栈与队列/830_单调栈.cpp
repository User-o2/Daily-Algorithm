/*
https://www.acwing.com/problem/content/description/832/
单调栈 - 模板题

目标是找到每一个元素a[i]的左边第一个小于它的元素
单调栈中存储的是元素的下标，维护的是一个单调递增的元素序列
stk[]中存储的都是a[i]左边的数，如果a[stk[tt]]>=a[i]，那么：
- a[i]的“左边第一个小于它的数”不可能是a[stk[tt]]
- a[i]之后（右边）元素的“左边第一个小于它的数”同样不可能是a[stk[tt]]，因为a[i]更小且a[i]更近
那么a[stk[tt]]就没用了，直接出栈即可

*/
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;
int a[N];
int stk[N], tt; //单调栈，tt=0表示栈为空

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++)
        scanf("%d",&a[i]);
    
    //开始遍历，对于每一个元素a[i]，寻找其左边第一个<它的数
    for(int i = 0; i < n; i ++)
    {
        while(tt && a[stk[tt]]>=a[i])
            tt --;
        if(tt) //a[stk[tt]]<a[i]
            printf("%d ",a[stk[tt]]);
        else
            printf("-1 ");
        
        stk[++tt] = i; //入栈的是元素的下标
    }
    return 0;
}