/*
https://www.acwing.com/problem/content/description/3627/

双指针-滑动窗口
确保不重复 vs 确保包含
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int t;
string s;

int main()
{
	cin >> t;
	while(t --)
	{
		cin >> s;
		
		//滑动窗口
		int n = s.size();
		vector<int> cnt(4,0);
		int res = n+1;
		int j = 0; //左端点
		for(int i = 0; i < n; i ++) //右端点
		{
			cnt[s[i]-'0'] += 1;
			//(cnt[1]>=1 && cnt[2]>=1 && cnt[3]>=1)这个判断可以使用一个变量进行优化
			while((cnt[1]>=1 && cnt[2]>=1 && cnt[3]>=1) && cnt[s[j]-'0']>1) //注意cnt[s[j]-'0']>1时才收缩
			{
				cnt[s[j]-'0'] -= 1;
				j ++;
			}
			//一定有j < i
			if(cnt[1]>=1 && cnt[2]>=1 && cnt[3]>=1)
				res = min(res,i-j+1); //len([j,i])
		}
		if(res == n+1)
			printf("0\n");
		else
			printf("%d\n",res);
	}
	return 0;
}

//因为字符串中只包含1,2,3，所以可以使用一个变量sum优化判断条件(cnt[1]>=1 && cnt[2]>=1 && cnt[3]>=1)
//如果还有其他数字，那么无法使用“第一次出现”这种规则维护单个sum变量了

//int main()
//{
//	cin >> t;
//	while(t --)
//	{
//		cin >> s;
//		
//		//滑动窗口
//		int n = s.size();
//		vector<int> cnt(4,0);
//		int sum = 0;
//		int res = n+1;
//		
//		int j = 0; //左端点
//		for(int i = 0; i < n; i ++) //右端点
//		{
//		    if(cnt[s[i]-'0'] == 0) //这个数字第一次出现
//		        sum += 1;
//			cnt[s[i]-'0'] += 1;
//			
//			while(sum==3 && cnt[s[j]-'0']>1) //注意cnt[s[j]-'0']>1时才收缩
//			{
//				cnt[s[j]-'0'] -= 1;
//				j ++;
//			}
//			//一定有j < i
//			if(sum==3)
//				res = min(res,i-j+1); //len([j,i])
//		}
//		if(res == n+1)
//			printf("0\n");
//		else
//			printf("%d\n",res);
//	}
//	return 0;
//}