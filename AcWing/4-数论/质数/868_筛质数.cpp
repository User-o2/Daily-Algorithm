/*
https://www.acwing.com/problem/content/description/870/
范围内筛质数 - 线性筛算法
*/
#include<iostream>
using namespace std;

const int N = 1000010;
int num;
int prime[N],cnt; //把质数存下来
bool sta[N]; //是否被筛去（即是否是合数）

void get_prime(int n)
{
	for(int i = 2; i <= n; i ++) //2~n范围内找质数
	{
		if(sta[i] == false) //不是合数，即为质数
			prime[cnt++] = i;
		
		for(int j = 0; prime[j] <= n/i; j ++) //每一个i都要进行筛选，i在这里类似一个倍数的作用
		{
			sta[i*prime[j]] = true; //合数
			
			//线性筛的核心数学原理：每个合数只被其最小的质因数筛掉，所以只被筛掉一次，保证O(N)
			if(i % prime[j] == 0)
				break;
/*
当 i % prime[j] == 0 触发 break 时，意味着 prime[j] 已经是 i 的最小质因子。如果此时不 break，继续用下一个质数 prime[j+1] 去乘以 i 得到合数 C=i×prime[j+1]，
那么C的最小质因子其实是 prime[j]，它应该在后续被 prime[j] 乘以某个数时筛掉，而不是在此处被 prime[j+1] 筛掉。理解这一点，才是掌握了线性筛的灵魂。
*/
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> num;
	
	get_prime(num);
	cout << cnt << "\n";
	return 0;
}