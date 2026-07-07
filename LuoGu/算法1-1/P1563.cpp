/*
https://www.luogu.com.cn/problem/P1563

朝内0：左顺-、右逆+
朝外1：左逆+、右顺-

0向左数，1向右数
*/
#include<iostream>
using namespace std;

const int N = 100010;
int face[N];
string name[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		cin >> face[i] >> name[i];
		
	int idx = 0, face_idx = face[idx];
	for(int i = 0; i < m; i ++)
	{
		int a,b;
		cin >> a >> b;
		//指针加
		if((a==0 && face_idx==1) || (a==1 && face_idx==0))
		{
			idx = (idx+b)%n;
			face_idx = face[idx];
		}
		else
		{
			idx = (idx-b+n)%n;
			face_idx = face[idx];
		}
	}
	cout << name[idx] << "\n";
	return 0;
}