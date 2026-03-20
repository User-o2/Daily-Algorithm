/*
https://www.acwing.com/problem/content/4385/

双指针-同向双指针
可以将题目转换为"子序列匹配"的问题
*/
#include<iostream>
#include<string>
using namespace std;

int t;
string I,P;

int main()
{
	cin >> t;
	int idx = 1;
	while(t--)
	{
		cin >> I >> P;
		
		int i = 0, j = 0;
		int n = I.size(), m = P.size();
		while(i < n && j < m)
		{
			if(I[i] != P[j])
				j ++;
			else
			{
				i ++;
				j ++;
			}
		}
		cout << "Case #" << idx++ << ": ";
		if(i == n)
			cout << m-n << endl;
		else
			cout <<"IMPOSSIBLE" << endl;
	}
	return 0;
}