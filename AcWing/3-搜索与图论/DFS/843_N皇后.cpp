/*
https://www.acwing.com/problem/content/845/
n皇后问题
因为任意两个皇后都不能处于同一行、同一列或同一斜线上
所以每一行必定只能有一个皇后，那么我们去遍历行即可。
每一行放置了一个皇后之后，就去遍历下一行

那么，对行进行遍历保证了两个皇后不会出现在同一行中，还需要维护判断两个皇后不可以出现在同一列或同一斜线
*/
#include<iostream>
#include<string>
using namespace std;

const int N = 15;
char a[N][N]; //字符地图推荐使用二维字符数组
int n;
bool col[N],dg[2*N],udg[2*N]; //维护冲突信息

void dfs(int u) //u指的是行数，0~n-1
{
	if(u == n)
	{
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < n; j ++)
				cout << a[i][j];
			cout << "\n";
		}
		cout << "\n";
		return; //结束返回
	}
	
	for(int i = 0; i < n; i ++) //对于本行，遍历每一列
	{   //u行i列
		if(col[i]==false && dg[u-i+n]==false && udg[u+i]==false)
		{
			a[u][i] = 'Q';
			col[i] = true;
			dg[u-i+n] = true;
			udg[u+i] = true;
			
			dfs(u+1); //继续填下一行
			
			//恢复现场
			a[u][i] = '.';
			col[i] = false;
			dg[u-i+n] = false;
			udg[u+i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	//棋盘初始化
	for(int i = 0; i < n; i ++) //索引为0~n-1
		for(int j = 0; j < n; j ++)
			a[i][j] = '.';
	dfs(0); //从第0行开始遍历
	return 0;
}