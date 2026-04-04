/*
https://www.acwing.com/problem/content/description/831/

数组模拟队列
*/
#include<iostream>
#include<string> //需要读取string，需要cin+关流
using namespace std;

const int N = 100010;
int q[N];
//队头和队尾指针初始化，经典闭区间语义[hh,tt]
//队列非空情况下，hh<=tt；所以当hh>tt即为队列空
//指针的物理意义（队列非空下）：hh严格指向队头元素；tt严格指向队尾元素
int hh = 0, tt = -1;

void push(int x)
{
	q[++tt] = x; //类似栈的push，先自增
}

void pop()
{
	hh++; //逻辑删除
}

bool empty()
{
	return hh>tt;
}

int query()
{
	return q[hh]; //队头指针严格指向对头元素
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int m;
	cin >> m;
	while(m --)
	{
		string opt;
		cin >> opt;
		if(opt == "push")
		{
			int x;
			cin >> x;
			push(x); //在using namespace std;语义空间哪些是可以命名、哪些是不可以命名的？
		}
		else if(opt == "pop")
			pop();
		else if(opt == "empty")
		{
			if(empty())
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		else
			cout << query() << "\n";
	}
	return 0;
}
