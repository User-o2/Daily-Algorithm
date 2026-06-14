/*
https://www.acwing.com/problem/content/876/
在某个连续范围内(1~n)求每一个数字的欧拉函数

- 在线性筛质数代码模板的基础上进行欧拉函数的计算
- 将 1~n 范围内的数字分为质数和合数进行计算
*/
#include<iostream>
using namespace std;

const int N = 1000010;
int prime[N],cnt; //筛质数用到的数据类型
bool sta[N];
int phi[N]; //存储欧拉函数

void get_ola(int n)
{
	phi[1] = 1; //特殊处理
	
	for(int i = 2; i <= n; i ++)
	{
		if(sta[i] == false) //没有被筛去，是质数
		{
			prime[cnt++] = i;
			
			//质数的欧拉函数
			phi[i] = i-1;
		}
		
		for(int j = 0; prime[j] <= n/i; j ++)
		{
			//prime[j]*i不会爆int，因为不会超过2e9
			sta[prime[j]*i] = true;
			
			//合数的欧拉函数
			if(i % prime[j] == 0)
			{
				phi[prime[j]*i] = prime[j]*phi[i];
				break;
			}
			else
			{
				//互质
				phi[prime[j]*i] = (prime[j]-1)*phi[i];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	get_ola(n);
	
	long long res = 0;
	for(int i = 1; i <= n; i ++)
		res += phi[i];
	cout << res << "\n";
	return 0;
}