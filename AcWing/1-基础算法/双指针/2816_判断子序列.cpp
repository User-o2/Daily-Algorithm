/*
https://www.acwing.com/problem/content/2818/
双指针-同向双指针
*/

//Upd 2026.3.16：单层while循环足矣，优雅~
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;
int a[N],b[N];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i ++)
        scanf("%d",&a[i]);
    for(int j = 0; j < m; j ++)
        scanf("%d",&b[j]);
    
    //判断子序列
    int i = 0, j = 0;
    int cnt = 0;
    while(i < n && j < m)
    {
        if(a[i] == b[j]) //匹配到
        {
            cnt += 1;
            i ++;
            j ++;
        }
        else //未匹配到
            j ++;
    }
    if(cnt == n)
        printf("Yes");
    else
        printf("No");
    return 0;
}