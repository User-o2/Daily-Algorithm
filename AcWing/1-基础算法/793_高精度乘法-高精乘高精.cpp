/*
https://www.acwing.com/problem/content/795/

高精度×高精度
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> A,B,res;
string a,b;

vector<int> mul(vector<int>& A, vector<int>& B)
{
	//注意高精度乘法这里需要预先开内存
	//n位数乘以m位数，乘积是 n+m 位数或 n+m-1 位数
	//所以最后需要处理前导零
	vector<int> C(A.size()+B.size(), 0);
	
	//从个位乘起，模拟乘法AxB
	for(int i = 0; i < A.size(); i ++)
		for(int j = 0; j < B.size(); j ++)
			C[i+j] += A[i]*B[j];
	
	//处理C每一位的进位，从个位向高位进位
	for(int i = 0; i < C.size()-1; i ++) //NOTE：i 的遍历的上界应该是C.size()-1.因为不可能超过n+m位
	{
		C[i+1] += C[i]/10;
		C[i] %= 10;
	}
	
	//处理前导零
	while(C.size()>1 && C.back()==0)
		C.pop_back();
	return C;
}

int main()
{
	cin >> a >> b;
	//倒序存储到vector，对齐个位
	for(int i = a.size()-1; i >= 0; i --)
		A.push_back(a[i]-'0');
	for(int i = b.size()-1; i >= 0; i --)
		B.push_back(b[i]-'0');
		
	res = mul(A,B);
	//因为是倒序存储，所以要倒序输出
	for(int i = res.size()-1; i >= 0; i --)
		cout << res[i];
	return 0;
}