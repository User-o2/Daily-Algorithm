/*
https://icpc.qlu.edu.cn/p/1757
波兰表达式（前缀表达式）求值

前缀表达式的特点：
- 在前缀表达式中，两个操作数的运算符一定紧挨着它俩，并且运算符在操作数的前面
- 前缀表达式同样是没有括号的

求解的算法流程：
那么只需要**从右向左**遍历表达式字符串，然后使用一个**操作数栈**存储操作数，遇到运算符就弹出两个操作数进行运算即可。


样例1：
+ 1 2
3
样例2：
* + 3 4 5
35
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int N = 1000010;
long long num[N]; //操作数栈，注意看数值范围是否需要开long long！
int tt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//读入表达式
	vector<string> str;
	string s;
	while(cin >> s)
		str.push_back(s);
	
	int n = str.size();
	for(int i = n-1; i >= 0; i --) //从右向左遍历
	{
		string c = str[i];
		if(c=="+" || c=="-" || c=="*" || c=="/") //1.遇到运算符
		{
			long long a = num[tt--]; //注意前缀表达式倒序遍历先弹出的是左操作数
			long long b = num[tt--];
			
			long long res = 0;
			if(c == "+")
				res = a+b;
			else if(c == "-")
				res = a-b;
			else if(c == "*")
				res = a*b;
			else
				res = a/b;
			num[++tt] = res;
		}
		else //2.遇到数字，直接入栈！
			num[++tt] = stoll(c);
	}
	cout << num[tt] << "\n";
	return 0;
}