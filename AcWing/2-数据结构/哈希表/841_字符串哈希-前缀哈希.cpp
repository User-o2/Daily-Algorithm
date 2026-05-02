/*
https://www.acwing.com/problem/content/description/843/
字符串哈希算法-前缀哈希

核心思想是将字符串映射为数字
- 首先O(N)预处理前缀哈希值
- 然后基于类似前缀和的思想，以O(1)的时间复杂度进行区间哈希值的查询
*/
#include<iostream>
using namespace std;

const int N = 100010;
typedef unsigned long long ull;
int n,m;
char str[N];

const int P = 131; //P进制数，经验值
ull h[N],p[N]; //维护字符串哈希需要的变量
/*
使用ull数据类型，自动进行对 2^64 的取模运算
h[i]表示str[1,i]子字符串的哈希值
P[i]表示p的i次方对 2^64 取余的结果
*/

ull get_hash(int l, int r) //获得str[l,r]这段子字符串的哈希值
{
    return h[r] - h[l-1]*p[r-l+1]; //将str[1,l-1]这段子字符串的哈希值左移r-l+1位，然后相减，剩余的就是str[l,r]子字符串的哈希值
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> (str+1); //基于1的索引读入str
    
    //首先，计算出所有元素h[i]和P[i]备用
    h[0] = 0, p[0] = 1;
    for(int i = 1; i <= n; i ++) //前缀和，基于1的索引
    {
        p[i] = p[i-1]*P; //幂运算，没什么好说的
        h[i] = h[i-1]*P + str[i]; //h[i]和h[i-1]的关系可以基于哈希函数展开h[i]和h[i-1]可以推导出来
    }
    
    //然后进行区间哈希值的查询
    while(m --)
    {
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(get_hash(l1,r1) == get_hash(l2,r2))
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }
    return 0;
}