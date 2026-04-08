/*
https://www.acwing.com/problem/content/839/
并查集的简单应用
Q:
具体来说，并查集属于是图论的算法？
*/
#include<iostream>
#include<string>
using namespace std;

const int N = 100010;
int p[N],cnt[N]; //p[x]表示x指向p[x];某集合中的元素个数为cnt[root]
int n,m;

int find(int x)
{
	if(p[x] != x) //非根节点需要递归找根
		p[x] = find(p[x]); //将x指向集合的根节点
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	
	//初始化并查集和集合大小
	for(int i = 1; i <= n; i ++)
	{
		p[i] = i;
		cnt[i] = 1;
	}
	
	while(m --)
	{
		string opt;
		cin >> opt;
		if(opt == "C")
		{
			int a,b;
			cin >> a >> b;
			
			//NOTE：注意细节，这里如果两个节点本就是连通的（也就是本就是在一个集合中），不能再次累加集合元素！
			if(find(a) != find(b)) //在a和b中连一条边，其实就是合并集合
			{
				int roota = find(a), rootb = find(b);
				p[roota] = rootb; //集合a的根节点指向集合b的根节点
				cnt[rootb] += cnt[roota];
				//集合b的元素总个数为cnt[find(b)]，既然将集合a指向了集合b，那么集合b就要累加，只看集合根节点的cnt[]即可
			}
		}
		else if(opt == "Q1")
		{
			int a,b;
			cin >> a >> b;
			if(find(a) == find(b)) //判断是否在同一集合中
				cout << "Yes" << "\n";
			else
				cout << "No" << "\n";
		}
		else
		{
			int a;
			cin >> a;
			cout << cnt[find(a)] << "\n";
		}
	}
	return 0;
}