/*
https://www.acwing.com/problem/content/840/
堆排序模板题
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100010;
int h[N], n, m, Size;

void down(int x) //注意x表示元素下标
{
    int t = x;
    if(2*x <= Size && h[t] > h[2*x])
        t = 2*x;
    if(2*x+1 <= Size && h[t] > h[2*x+1])
        t = 2*x+1;
    if(t != x)//递归结束条件
    {
        swap(h[t], h[x]);
        down(t);  //交换的不是下标而是值，现在h[t]就是原来的值
    }
}
void up(int x)
{
    // while(x/2 && h[x] < h[x/2])
    // {
    //     swap(h[x], h[x/2]);
    //     x /= 2;
    // }
    if(x/2 && h[x] < h[x/2])
    {
        swap(h[x], h[x/2]);
        up(x/2);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &h[i]);
    //建堆    
    Size = n;//建堆先写Size，因为down函数会用到
    for(int i = n/2; i > 0; i --)
        down(i);
    
    while( m --)
    {
        printf("%d ", h[1]);
        h[1] = h[Size --];
        down(1);
    }
    
    return 0;
}