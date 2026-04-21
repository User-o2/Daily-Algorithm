/*
https://www.luogu.com.cn/problem/P16239
补题-蓝桥杯2026 C++B组 H题

算法标签：数学推导（贪心）、二分查找优化
通过二分查找算法优化优先队列，通过100%样例
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010, mod = 998244353;
int n,m;
struct Info{
	int a,b,k,div_res;
};
Info p[N];

bool check(int x) //检查x是否可以作为最大的L
{
	long long cnt = 0;
	for(int i = 0; i < n; i ++)
	{
		if(x >= p[i].div_res)
			cnt += x - p[i].div_res;
	}
	if(cnt <= m)
		return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
	{
		cin >> p[i].a >> p[i].b;
		//存储下来，空间换时间
		p[i].div_res = p[i].a/p[i].b;
	}
	
	//先找一个整数L，使得每个队员的整数部分ai/bi均至少达到L
	//二分时间复杂度O(n·logm)
	int l = 0, r = m;
	while(l < r)
	{
		int mid = l+r+1 >> 1;
		if(check(mid)) //mid还可以尝试更大
			l = mid;
		else
			r = mid-1;
	}
	
	int less = m;
	//找到目标的整数部分l之后，更新每一个队员的整数部分
	for(int i = 0; i < n; i ++)
	{
		if(p[i].div_res < l)
		{
			int delta = l - p[i].div_res;
			p[i].k += delta;
			less -= delta;
		}
	}
	
	//剩余的部分一定有less<n，排序取前less个各分配一次即可
	//排序时间复杂度O(n·logn)
	sort(p,p+n,[](const Info& p1, const Info& p2)
	{
		//将除法转换为乘法运算，防止精度丢失
		long long val1 = p1.a + (long long)p1.k * p1.b;
		long long val2 = p2.a + (long long)p2.k * p2.b;
	    // 交叉相乘规避浮点精度问题，且必须使用严格小于号 <
		return val1 * p2.b < val2 * p1.b;
	}); //但是3个int变量相乘还是有溢出long long变量的风险
	for(int i = 0; i < less; i ++)
		p[i].k += 1;
	
	long long res = 1;
	for(int i = 0; i < n; i ++)
		res = res * (p[i].a + (long long)p[i].k*p[i].b) % mod;
	cout << res << "\n";
	return 0;
}