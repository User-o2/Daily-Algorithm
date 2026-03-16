/*
https://www.luogu.com.cn/problem/P12289

模拟
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

string s;
int cnt[10];

int main()
{
	cin >> s;
	int res = 2e9;
	for(int l = 0; l+9 < s.size(); l ++) //窗口左端点
	{
		memset(cnt, 0, sizeof(cnt)); //不要忘记清空
		int r = l+9;
		for(int i = l; i <= r; i ++)
			cnt[s[i]-'0'] += 1;
			
		//直接遍历cnt[]:多的数字就是cnt[i]>1，少的数字为cnt[i]==0
		vector<int> lose,more;
		for(int i = 0; i <= 9; i ++) //升序遍历
		{
			//注意这里需要多次push
			if(cnt[i] > 1)
			{
				int k = cnt[i]-1;//多出的
				while(k --)
					more.push_back(i);
			}
			else if(cnt[i] == 0)
				lose.push_back(i);
		}
		
		//对应一一相减即可
		//必定有lose.size()==more.size()
		int cur_res = 0;
		for(int i = 0; i < lose.size(); i ++)
			cur_res += abs(lose[i]-more[i]);
		res = min(cur_res,res);
	}
	printf("%d",res);
	return 0;
}