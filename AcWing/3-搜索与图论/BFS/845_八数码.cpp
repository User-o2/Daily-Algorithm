/*
https://www.acwing.com/problem/content/847/
BFS-八数码

- queue<pair<string,int>>直接优化为queue<string>，使用str.find('x')直接查找索引，时间复杂度忽略不计，减少心智负担
- my_swap()函数可以使用<algorithm>的原生swap()，直接交换
*/
#include<iostream>
#include<string>
#include<unordered_map>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

string ed = "12345678x";
unordered_map<string,int> dist; //记录到达某一状态所需要的步数
queue<string> q; //记录某一个状态
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

int bfs(string& st)
{
	if(st == ed)
		return 0;
	q.push(st);
	dist[st] = 0;
	
	while(q.size())
	{
		string cur_s = q.front(); q.pop();
		int cur_idx = cur_s.find('x');
		
		//遍历4个邻居：1维索引转为2维坐标进行swap()
		int x = cur_idx/3, y = cur_idx%3;
		for(int i = 0; i < 4; i ++)
		{
			int nex_x = x+dx[i], nex_y = y+dy[i];
			//越界避免
			if(nex_x>=0 && nex_x<3 && nex_y>=0 && nex_y<3)
			{
				//转回一维索引
				int nex_idx = nex_x*3 + nex_y;
				string nex_s = cur_s;
				swap(nex_s[nex_idx],nex_s[cur_idx]);
				
				//入队的时候直接检查！
				if(nex_s == ed)
					return dist[cur_s]+1;
				else if(!dist.count(nex_s)) //必须是没有到达过
				{
					q.push(nex_s);
					dist[nex_s] = dist[cur_s]+1;
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string st,ele;
	for(int i = 0; i < 9; i ++)
	{
		cin >> ele;
		st += ele;
	}
	cout << bfs(st) << "\n";
	return 0;
}