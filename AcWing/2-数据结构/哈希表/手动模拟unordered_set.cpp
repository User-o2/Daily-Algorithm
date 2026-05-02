/*
https://www.acwing.com/problem/content/description/842/
模拟哈希表-开放寻址法

模拟unordered_set
*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int N = 100010, M = 200003; //首先找出 >=200000 的第一个质数200003
const int have_pos = 0x3f3f3f3f; //四位
int n;
int h[M]; //实现哈希表所需要的变量

//将x映射到哈希值，x为待映射的大数值
int find(int x)
{
    int tar = (x % M + M) % M; //注意x的值可能为负数大数值，保证取模运算之后的结果在[0,M-1]
    while(h[tar]!=x && h[tar]!=have_pos) //寻找合适的坑位
    {
        tar ++;
        if(tar == M) //找到头了
            tar = 0;
    }
    //while退出之后一定是h[tar]==x：本来就插入了或者h[tar]==have_pos：找到了坑位。直接返回即可
    return tar;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //需要将h[]标记
    memset(h, 0x3f, sizeof(h));
    
    cin >> n;
    while(n --)
    {
        string opt;
        int x;
        cin >> opt >> x;
        if(opt == "I")
            h[find(x)] = x; //插入
        else if(opt == "Q")
        {
            if(h[find(x)] == x)
                cout << "Yes" << "\n";
            else
                cout << "No" << "\n";
        }
    }
    return 0;
}