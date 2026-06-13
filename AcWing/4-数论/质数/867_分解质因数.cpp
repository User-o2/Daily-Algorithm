/*
https://www.acwing.com/problem/content/869/
【试除法】分解质因数

- 质因数分解定理：任何一个大于 1 的正整数都可以唯一表示为质因数的乘积。所以质因数就可以比作是这个数的基因。
- 质因数分解的本质就是：搜索质因数 -> 计算出底数 -> 下一个质因数

注意：
- 需要检查是否存在大于sqrt(n)的质因子！
*/
#include<iostream>
using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		
		//分解质因数
		for(int i = 2; i <= n/i; i ++) //注意这里循环的上界不断减小
		{
			if(n % i == 0)
			{
				int s = 0;
				while(n % i == 0)
				{
					n /= i;
					s ++;
				}
				cout << i << " " << s << "\n";
			}
		}
		if(n > 1) //一个整数n最多只有一个大于sqrt(n)的质因子
			cout << n << " 1" << "\n";
		cout << "\n";
	}
	return 0;
}