/*
https://www.acwing.com/problem/content/description/3771/

双指针-跳跃指针
题目要求“最少删除多少个字母，使得不存在连续的3个x”
那么就可以遍历一遍字符串，找出所有连续的x作为块
对于每一个"x块":
- 如果长度>=3，就记录删除的x数;
- 如果长度<3，继续处理下一个"x块";
*/

#include<iostream>
#include<string>
using namespace std;

int n;
string s;

int main()
{
	cin >> n >> s;
	int res = 0;
	
	//对撞指针
	int l = 0;
	while(l < n) //l是左指针[l,r]
	{
		if(s[l] == 'x')
		{
			int r = l; //r是右指针[l,r]
			//r去探索"x块"的边界
			while(r+1 < n && s[r+1] == 'x')
				r ++;
			//"x块":[l,r]已经最大
			int len = r-l+1;
			if(len >= 3)
				res += len-2; //需要删除的x个数
			
			l = r+1; //探索下一个"x块"
		}
		else
			l ++;
	}
	printf("%d",res);
	return 0;
}