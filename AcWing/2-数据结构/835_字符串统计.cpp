/*
https://www.acwing.com/problem/content/description/837/

字符串统计
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	unordered_map<string,int> mp;
	cin >> n;
	while(n --)
	{
		string opt, str;
		cin >> opt >> str;
		if(opt == "I")
			mp[str] ++;
		else
			cout << mp[str] << "\n";
	}
	return 0;
}