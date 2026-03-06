/*
https://www.acwing.com/problem/content/description/795/

高精度×低精度
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string a;
int b;
vector<int> A,res;

vector<int> mul(vector<int>& A, int b)
{
	vector<int> C;
	
	//从个位乘起
	int t = 0; //进位
	for(int i = 0; i < A.size(); i ++)
	{
		int s = t + A[i]*b;
		C.push_back(s%10);
		t = s / 10;
	}
	while(t) //保存最后的进位
	{
		C.push_back(t%10);
		t /= 10;
	}
	return C;
}

int main()
{
	cin >> a >> b;
	
	//注意这里特判一下，否则需要额外处理前导零
	if(b == 0)
	{
		cout << "0";
		return 0;
	}
		
	//之后需要从个位开始乘起，倒序存储到vector
	for(int i = a.size()-1; i >= 0; i --)
		A.push_back(a[i]-'0');
	
	res = mul(A,b);
	
	for(int i = res.size()-1; i >= 0; i --)
		cout << res[i];
	
	return 0;
}