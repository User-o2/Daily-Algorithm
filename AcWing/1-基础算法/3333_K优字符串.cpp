/*
https://www.acwing.com/problem/content/3336/
双指针-伪·对撞指针
*/
#include<iostream>
#include<string>
using namespace std;

int t,n,k;
string s;

int main()
{
	cin >> t;
	int cnt = 1;
	while(t --)
	{
		cin >> n >> k;
		cin >> s;
		
		int score = 0;
		int l = 0, r = n-1;
		//对撞指针的极简标准边界永远是 l < r
		while(l < r)
		{
			if(s[l] != s[r])
				score++;
			l ++;
			r --;
		}
		//优良分数本质就是不对称的个数
		//目标不对称的个数为k
		//现在不对称的个数为score
		//为什么是abs(k-score):因为现在不对称的个数可能高于k，那么就需要改为对称
		cout << "Case #" << cnt++ << ": " << abs(k-score) << endl;
	}
	return 0;
}