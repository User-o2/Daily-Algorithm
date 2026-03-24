/*
https://www.acwing.com/problem/content/description/796/

高精度除法：高精度÷低精度
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string a;
int b;
vector<int> A,res;

vector<int> div(vector<int>& A, int b, int& x) //引用传出余数
{
	vector<int> C;//商
	
	//模拟除法：从高位开始除起
	int t = 0;//余数
	for(int i = A.size()-1; i >= 0; i --)
	{
		int s = t*10 + A[i];
		C.push_back(s/b); //商
		t = s%b; //余数
	}
	x = t;
	
	//除去高位可能存在的前导零
	//目前高位商存储在低索引，先翻转一下
	reverse(C.begin(), C.end());
	//现在个位存储在低索引
	while(C.size()>1 && C.back()==0)
		C.pop_back();
	
	return C;
}

int main()
{
	cin >> a >> b;
	
	//高精度惯例：倒序存储
	for(int i = a.size()-1; i >= 0; i --)
		A.push_back(a[i]-'0');
	
	int x = 0; //余数
	res = div(A,b,x); //商
	
	//倒序输出
	for(int i = res.size()-1; i >= 0; i --)
		cout << res[i];
	cout << endl << x;
	return 0;
}