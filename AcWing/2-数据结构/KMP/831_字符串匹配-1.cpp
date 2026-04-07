/*
https://www.acwing.com/problem/content/description/833/
在一个文本串中查找一个模式串出现的索引
最优解是KMP算法，稳定的O(N+M)
这里.find()的平均时间复杂度为O(N)，但是脏数据会TLE

[.find()写法]
*/
#include<iostream>
#include<string>
using namespace std;

int n,m;
string p,s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> p >> m >> s;
	//.find(string str, int start_pos)
	for(int i = s.find(p); i != string::npos; i = s.find(p,i+1))
		cout << i << " ";
	return 0;
}