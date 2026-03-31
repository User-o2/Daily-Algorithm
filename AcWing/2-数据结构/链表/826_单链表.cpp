/*
https://www.acwing.com/problem/content/description/828/

数组模拟单链表-应对acm风格机试(浙大/CSP)
不过大多是考链表指针的逻辑变换
*/
#include<iostream>
using namespace std;

const int N = 100010;
int e[N]; //e[idx]存储节点idx的值
int ne[N]; //ne[idx]存储节点idx指向的下一个节点idx_next
int head; //记录头指针idx_head
int idx; //记录下一个节点存到e[]的索引

void init()
{
    head = -1;
    idx = 0;
}

void add_to_head(int x) //将x插入作为头指针
{
    //插入操作，先存值
    e[idx] = x;
    //然后变换关系
    ne[idx] = head;
    head = idx;
    idx ++; //下一个空位
}

void del(int k) //删除idx为k的节点的后一个节点
{
    if(ne[k] != -1) //鲁棒性：idx的后面还有节点
        ne[k] = ne[ne[k]];
}

void insert(int k,int x) //在idx为k的节点后面插入一个值为x的节点
{
    //插入操作，先存值
    e[idx] = x;
    //然后变换关系
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    
    int m;
    cin >> m;
    while(m --)
    {
        char opt;
        cin >> opt;
        if(opt == 'H')
        {
            int x;
            cin >> x;
            add_to_head(x);
        }
        else if(opt == 'D')
        {
            int k;
            cin >> k;
            if(k == 0 && head != -1)
                head = ne[head];
            else
                del(k-1); //第k个插入的数的idx是k-1
        }
        else if(opt == 'I')
        {
            int k,x;
            cin >> k >> x;
            insert(k-1,x);
        }
    }
    for(int idx = head; idx != -1; idx = ne[idx]) //遍历链表
        cout << e[idx] << " ";
    return 0;
}