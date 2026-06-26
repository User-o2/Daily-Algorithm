/*
https://www.acwing.com/problem/content/892/
容斥原理：注意容斥原理是对“集合的大小/元素的个数”而言的

求1~n中能被{p1,p2,...,pm}中至少一个数整除的数的个数
使用容斥原理，建模m个集合为：
- 1~n中能被 p1 整除的数的个数 A1
- 1~n中能被 p1 整除的数的个数 A2
- ...
- 1~n中能被 pm 整除的数的个数 Am

题目所求即为 A1~Am 的并集的元素个数，也就是被{p1,p2,...,pm}中至少一个数整除的数的个数
而 A1~Am 的并集的元素个数，可以使用容斥原理进行求解
*/
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 20;
int p[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
		cin >> p[i];
	
	int res = 0;
	//等价为 2^m 个加数的和
	for(int i = 1; i < (1<<m); i ++) //2^m-1 个状态，注意这里需要从1开始遍历，至少选择p[i]中的一个！
	{
		//对于每一个 m 位二进制的状态 i
		bool sta = true;
		int t = 1, num = 0; //num是本状态下分母的个数
		for(int j = 0; j < m; j ++) //检查 i 的每一位
		{
			if((i>>j) & 1) //说明p[j]这个质数被选择作为分母的因子（基于0的索引）
			{
				if((ll)t*p[j] > n) //说明n不可以被同时整除、也就是交集为空，此时这个二进制i无效
				{
					sta = false;
					break;
				}
				else
				{
					t *= p[j];
					num ++;
				}
			}
		}
		if(sta) //合法
		{
			if(num % 2 == 0) //偶减
				res -= n/t;
			else //奇加
				res += n/t;
		}
	}
	cout << res << "\n";
	return 0;
}