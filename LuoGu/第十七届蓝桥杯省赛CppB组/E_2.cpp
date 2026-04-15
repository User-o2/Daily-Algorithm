/*
https://www.luogu.com.cn/problem/P16236
补题-蓝桥杯2026 C++B组 E题

[AC解法：贪心]
思路：
1. 维护一些变量：
- res：LQ聚合数量的最大值
- cnt_L：当前位置之前L的数量
- cnt_Q：当前位置之后Q的数量
- cnt：当前位置之后'?'的数量

2. 贪心+状态转移
先做统计分析，之后遍历一遍字符串：
- 遇到L：cnt_L++;
- 遇到Q：res += cnt_L; cnt_Q--;
- 遇到'?'：cnt--; res += max(cnt_L, cnt+cnt_Q);
也就是比较换成L还是换成Q哪个带来的增益更大
*/

#include<iostream>
#include<string>
using namespace std;

int n;
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> s;
	
	//首先进行统计
	long long res = 0;
	int cnt_L = 0, cnt_Q = 0, cnt = 0;
	for(auto ele : s)
	{
		if(ele == 'Q')
			cnt_Q ++;
		else if(ele == '?')
			cnt ++;
	}
	
	//开始遍历
	for(auto ele : s)
	{
		if(ele == 'L')
			cnt_L ++;
		else if(ele == 'Q')
		{
			res += cnt_L;
			cnt_Q --;
		}
		else //'?'
		{
			cnt --;
			//cnt_L是变为Q带来的增益，cnt+cnt_Q是变为L带来的增益
			if(cnt_L > cnt+cnt_Q) //变为Q，直接结算
				res += cnt_L;
			else //变为L，蓄势待发
				cnt_L ++;
		}
	}
	cout << res << "\n";
	return 0;
}