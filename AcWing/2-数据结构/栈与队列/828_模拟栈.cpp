/*
https://www.acwing.com/problem/content/description/830/
模拟栈的标准范式
<还是较为简单的>
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;
int stk[N]; //数组模拟栈
int top; //top=0表示栈空，top>0表示栈中有元素；stk[top]永远指向栈顶

void push(int x)
{
	//指针上移，然后存入元素
	stk[++top] = x;
}

void pop()
{
	//实际数据无需抹除，直接将栈顶指针下移，逻辑上删除元素
	top --;
}

bool empty()
{
	//优雅判断
	return top==0;
}

int query()
{
	return stk[top];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int m;
	cin >> m;
	while(m --)
	{
		string opt; //有string的场景，使用cin+关流
		cin >> opt;
		if(opt == "push")
		{
			int x;
			cin >> x;
			push(x);
		}
		else if(opt == "pop")
			pop();
		else if(opt == "empty")
		{
			if(empty())
				cout << "YES" << "\n"; //关流之后不要使用endl
			else
				cout << "NO" << "\n";
		}
		else if(opt == "query")
			cout << query() << "\n";
	}
	return 0;
}