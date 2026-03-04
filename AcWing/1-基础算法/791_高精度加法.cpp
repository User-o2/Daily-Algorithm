/*
https://www.acwing.com/problem/content/793/

高精度加法
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string a,b;
vector<int> A,B,res;

//封装成函数，应对混合高精度计算
vector<int> add(vector<int>& A, vector<int>& B)
{
	vector<int> res;
	
	//开始模拟加法
	int r = 0; //维护进位
	for(int i = 0; i < A.size() || i < B.size(); i ++) //从个位开始加起，完全遍历
	{
		int sum = r;
		if(i < A.size())
			sum += A[i];
		if(i < B.size())
			sum += B[i];
		r = sum / 10; //进位
		sum = sum % 10;
		res.push_back(sum); //倒序存储
	}
	//别忘记处理最后的进位
	if(r)
		res.push_back(r);
	return res;
}

int main()
{
	cin >> a >> b;
	
	//将每一数位的char转换为int，倒序存储到vector，准备进行加法模拟
	//倒序存储的目的：对齐个位
	for(int i = a.size()-1; i >= 0; i --)
		A.push_back(a[i]-'0');
	for(int i = b.size()-1; i >= 0; i --)
		B.push_back(b[i]-'0');
	
	vector<int> res = add(A,B);
	//倒序输出
	for(int i = res.size()-1; i >= 0; i --)
		cout << res[i]; //cout和printf不建议混用
	return 0;
}