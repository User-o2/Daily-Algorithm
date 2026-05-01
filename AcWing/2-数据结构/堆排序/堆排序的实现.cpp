/*
考点：原地堆排序
复杂度：时间 O(Nlog N)
*/
#include<iostream>
using namespace std;

const int N = 100010;
int h[N],sz; //维护堆需要的变量
int m,n;

void down(int x) //堆调整算法
{
    int t = x; //寻找节点x和左右子节点中的最大值
    int l = 2*x, r = 2*x+1;
    if(l<=sz && h[l]>h[t])
        t = l;
    if(r<=sz && h[r]>h[t])
        t = r;
        
    if(t != x) //x不是最大值，不应该作为父节点
    {
        swap(h[t],h[x]);
        down(t); //之前的h[x]的索引变为了t
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> h[i];
    
    //完整的堆排序（升序排序）共两步
    //第一步：构建大根堆，时间复杂度O(N)
    sz = n;
    for(int i = n/2; i >= 1; i --)
        down(i);
    
    //第二步：不断弹出最大节点
    while(sz > 1)
    {
        swap(h[1],h[sz]);
        sz --;
        down(1);
    }
    
    //输出排序之后的结果
    for(int i = 1; i <= n; i ++)
        cout << h[i] << " ";
    return 0;
}