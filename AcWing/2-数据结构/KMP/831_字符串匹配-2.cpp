/*
/*
https://www.acwing.com/problem/content/description/833/
在一个文本串中查找一个模式串出现的索引
注意需要重叠匹配！

[暴力写法]
*/
*/
#include<iostream>
#include<string>
using namespace std;

int n,m;
string p,s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> p;
    cin >> m >> s;
    
    //暴力代码：循环套双指针O(M*N)
    for(int st = 0; st <= m-n; st ++) //从s[st]开始匹配p
    {
    	int i = st, j = 0;
    	while(i<m && j<n && s[i] == p[j])
    	{
    		i ++;
    		j ++;
		}
		if(j == n) //完全匹配到了p
			cout << st << " ";
	}
	return 0;
}