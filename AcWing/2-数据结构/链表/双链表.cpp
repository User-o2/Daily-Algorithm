/*
https://www.acwing.com/problem/content/description/829/

更新[标准范式]实现代码
双链表
*/

#include<iostream>
using namespace std;

const int N = 100010;
//所有的关系都是基于idx进行连接的，节点的值只是记录
int l[N]; //l[idx]表示节点idx的左节点（前驱）idx_l
int r[N]; //r[idx]表示节点idx的右节点（后继）idx_r
int e[N]; //e[idx]表示节点idx的值
int idx;

void init()
{
	//哨兵节点：0是最左指针，1是最右指针
	r[0] = 1;
	l[1] = 0;
	idx = 2; //真实的节点从2开始，则第k个节点的idx为k+1
}

void add_to_right(int k, int x) //在idx为k的右侧插入值为x的节点
{
	//画图更好理解！
	//先处理x的值以及两根线
	e[idx] = x;
	l[idx] = k;
	r[idx] = r[k];
	
	//再指向idx
	l[r[k]] = idx;
	r[k] = idx;
	
	idx ++;
}

void del(int k) //删除idx为k的节点
{
	//直接越过k即可
	l[r[k]] = l[k];
	r[l[k]] = r[k];
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
		string opt;
		cin >> opt;
		if(opt == "L")
		{
			int x;
			cin >> x;
			//最左侧插入x，即在左哨兵的右侧插入
			add_to_right(0,x);
		}
		else if(opt == "R")
		{
			int x;
			cin >> x;
			//最右端插入x，即在右哨兵的左节点的右侧插入
			add_to_right(l[1],x);
		}
		else if(opt == "D")
		{
			int k;
			cin >> k;
			//将第k个插入的节点删除，idx为k-1
			del(k+1);
		}
		else if(opt == "IL")
		{
			int k,x;
			cin >> k >> x;
			//在第k个插入节点的左侧插入，即在l[k-1]的右侧插入
			add_to_right(l[k+1],x);
		}
		else if(opt == "IR")
		{
			int k,x;
			cin >> k >> x;
			//在第k个插入节点的右侧插入，即在k-1的右侧插入
			add_to_right(k+1,x);
		}
	}
	//从左到右输出
	//0是最左指针，1是最右指针
	for(int idx = r[0]; idx != 1; idx = r[idx])
		cout << e[idx] << " ";
	return 0;
}