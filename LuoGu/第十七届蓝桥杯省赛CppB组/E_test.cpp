/*
E题-子问题拓展
求解字符串中子序列出现的次数
*/
#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s = "LQLQLQQLLQ";
	int n = s.size();
	
	//1.暴力做法
	int cnt = 0;
	for(int i = 0; i < n; i ++)
	{
		if(s[i] == 'L')
		{
			for(int j = i+1; j < n; j ++)
			{
				if(s[j] == 'Q')
					cnt ++;
			}
		}
	}
	cout << cnt << "\n";
	
	//2.O(N)线性dp优化（拓展性高，属于dp算法）
	int dp_L = 0;
	cnt = 0;
	for(int i = 0; i < n; i ++)
	{
		//状态转移'L'or'Q'
		if(s[i] == 'L')
			dp_L += 1;
		else if(s[i] == 'Q')
			cnt += dp_L; //以Q为右端点，能够匹配的LQ对一定是dp_L
	}
	cout << cnt << "\n";
	return 0;
}