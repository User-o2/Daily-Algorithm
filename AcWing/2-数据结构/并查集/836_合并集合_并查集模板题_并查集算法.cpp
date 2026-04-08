/*
https://www.acwing.com/problem/content/description/838/
并查集模板题
并查集算法
*/
#include<iostream>
#include<string>
using namespace std;

const int N = 100010;
int p[N]; //p[x]表示x的父节点，可以理解为x指向p[x].有点类似链表的nex[x]
int n,m;

int find(int x) //核心函数：寻找x所在的集合（根节点）
{
	//这个函数的本质作用是：将x指向根节点（特殊情况是x本身就是根节点、本身就指向自己）
	if(p[x] != x) //x不是根节点，即x没有指向自己；如果是根，直接返回
		p[x] = find(p[x]); //递归找根，找到根之后赋给p[x]返回
	//递归调用之后，p[x] = 根节点，即x指向了根节点
	return p[x]; //返回根节点
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		p[i] = i; //初始化并查集：一开始父节点是本身，p[i] = i指向自己
		
	while(m --)
	{
		string opt;
		int a,b;
		cin >> opt >> a >> b;
		if(opt == "M")
		{
			int root_a = find(a), root_b = find(b);
			if(root_a != root_b) //如果a和b不在同一个集合
				p[root_a] = root_b; //将a所在集合的根节点指向集合b的根节点，完成合并
		}
		else
		{
			if(find(a) != find(b))
				cout << "No" << "\n";
			else
				cout << "Yes" << "\n";
		}
	}
	return 0;
}