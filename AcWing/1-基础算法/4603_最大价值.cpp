/*
https://www.acwing.com/problem/content/4606/
双指针-跳跃指针
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int t;

int main()
{
	cin >> t;
	while(t --)
	{
		int n;
		string s;
		int res = 0;
		cin >> n >> s;
		
		//跳跃指针
		//寻找每一个"AP··P"块
		int l = 0;
		while(l < n)
		{
			if(s[l] == 'A') //找到"AP··P"块[l,r]
			{
				int r = l;
				while(r+1<n && s[r+1]=='P') //持续扩展
					r ++;
				//此"AP··P"块遍历完毕[l,r]
				res = max(res, r-l);
				
				l = r+1; //寻找下一个"AP··P"块
			}
			else
				l ++;
		}
		cout << res << endl;
	}
	return 0;
}