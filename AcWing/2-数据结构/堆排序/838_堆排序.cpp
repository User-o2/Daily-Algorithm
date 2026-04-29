/*
https://www.acwing.com/problem/content/840/

考点：通过堆进行数字序列的Top-K提取

思路：
由于所求的是前m个小的元素，所以构建一个小根堆
（当然如果要求的是前m个大的元素，那么就要构建一个大根堆）
小根堆构建完毕之后，不断弹出m次堆顶即可。

总结：
- 构建堆：大顶堆和小顶堆在建堆时候的区别仅仅是down()函数内的大于/小于号的区别；
- down()和up()都可以理解为是堆调整算法；
- 为什么要从n/2开始自底向上建堆？（也就是[n/2,1]建堆）
因为 n/2（下取整）+1 到 n 属于叶子结点，没有子节点；[1,n/2(下取整)]属于非叶子节点。
证明：某节点x的左右节点分别为2*x，2*x+1，那么(n/2+1)*2一定是大于n的所以没有叶子结点；n/2*2一定是小于等于n的，所以有叶子节点。
- 时间复杂度为什么是O(N)？
不同层的节点向下调整的最大步数是不同的，且层数越高的节点数量越少。可以通过差比数列求和进行推导。
*/
#include<iostream>
using namespace std;

const int N = 100010;
int n,m;
int h[N],sz; //维护堆需要的变量

void down(int x) //注意这里的x是索引！
{
    int t = x; //变量t用来寻找节点x和左右子节点中最小的那个节点（小根堆）
    
    int l = 2*x;
    if(l<=sz && h[l]<h[t])
        t = l;
    int r = 2*x+1;
    if(r<=sz && h[r]<h[t])
        t = r;
        
    if(t != x) //需要进行堆调整
    {
        swap(h[t],h[x]); //将原本的h[x]交换到索引t:h[t]
        down(t);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    //NOTE:堆是基于1的索引！
    for(int i = 1; i <= n; i ++)
        cin >> h[i];
    
    sz = n;
    //开始建堆
    for(int i = n/2; i >= 1; i --)
        down(i);
    
    //不断弹出m次堆顶
    while(m --)
    {
        cout << h[1] << " ";
        h[1] = h[sz]; //将堆尾元素从堆顶开始调整
        sz --; //具体调整之前，注意需要先减掉sz，避免弹出的堆顶再次纳入堆结构
        
        down(1);
    }
    return 0;
}