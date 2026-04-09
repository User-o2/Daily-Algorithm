/*
https://www.acwing.com/problem/content/description/242/
并查集的应用 - 拓展域并查集

- 在普通并查集中，x仅代表节点x，在本题目中每个节点有三个维度的属性：x同类域，x+n猎物域，x+2*n天敌域
- 当所有动物的相对关系都确定时，这3N个节点最终会严格地坍缩为 3 个巨大的集合
- 对于任意一个编号x，x+n,x+2n同样也是普通的编号，用来维护不同的集合
*/

#include<iostream>
using namespace std;

const int N = 150010; //3*maxdata
int p[N]; //fa[x]表示x的父节点，x指向fa[x]
int n,k;

int find(int x) //寻找x所在集合的根节点+路径压缩
{
	if(x != p[x])
		p[x] = find(p[x]);
	return p[x];
}

bool same(int x, int y) //判断x和y是否在同一个集合中
{
	return find(x)==find(y);
}

void merge(int x, int y) //合并x和y两个域，即合并集合
{
	p[find(x)] = find(y); //让x所在集合的根节点指向y所在集合的根节点
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;

	//初始化并查集
	for(int i = 1; i <= 3*n; i ++) //拓展域
		p[i] = i;
		
	int cnt = 0;
	while(k --) //在线处理
	{
		int d,x,y;
		cin >> d >> x >> y;
		//因为读到的这条数据只和之前的数据有关，所以在线处理
		if(x>n || y>n)
			cnt ++;
		else
		{
			if(d == 1) //声称x和y是同类
			{
				//如果x吃y（y在x的猎物域）或者y吃x（x在y的猎物域），为假话
				if(same(x+n,y) || same(x,y+n)) //这里的判断条件可以有多种选择.比如，检查是否有x吃y，可以检查x是否在y的天敌域same(x,y+2n)，也可以检查y是否在x的猎物域same(x+n,y)
				//这里same(x+n,y)和same(x,y+2n)是等价的，因为引入一条规则时会同时更新三个平行域
					cnt ++;
//				//检查是否已经配置好（这条分支判断其实是冗余的）
//				else if(same(x,y))
//					continue;
				else
				{
					//状态的纠缠同步：当引入一条新规则时，必须把这条规则在三个平行域全部更新 x,x+n,x+2n
					merge(x,y);
					merge(x+n,y+n);
					merge(x+2*n,y+2*n);
				}
			}
			else if(d == 2) //声称x吃y
			{
				//是否冲突：如果x和y是同类或者y吃x（x在y的猎物域），就是假话
				if(same(x,y) || same(x,y+n))
					cnt ++;
//				//是否已经配置好
//				else if(same(x,y+2*n))
//					continue;
				else //配置
				{
					merge(x,y+2*n); //metge(a,b)等价于merge(b,a)
					merge(x+n,y);
					merge(x+2*n,y+n);
				}
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}