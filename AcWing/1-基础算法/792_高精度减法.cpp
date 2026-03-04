/*
https://www.acwing.com/problem/content/794/

高精度减法

总结一下[高精度加法和减法]
1. 都是先读入到string，模拟手动计算的过程
2. 之后对齐个位，存储到vector
3. 进行模拟计算：
- 都是从个位开始遍历、完全遍历；
- 都是维护两个变量：for循环之外，加法需要维护进位、减法需要维护借位；for循环内，维护一个计算结果即可
4. 最后，加法需要处理最后的进位，减法需要去除前导零
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> A,B,res;
string a,b;

//判断是否有a > b
bool judge(string& a, string& b)
{
	//长度相同，直接按照字典序比较即可
	if(a.size() == b.size())
		return a >= b; //string 支持基于字典序的符号比较(<=,>=,==,<,>)
	else
		//比较位数
		return a.size() > b.size();
}

//大数A 减 小数B
vector<int> sub(vector<int>& A, vector<int>& B)
{
	vector<int> res;
	int r = 0; //维护借位
	for(int i = 0; i < A.size(); i ++) //从个位开始遍历，完全遍历
	{
		int s = A[i] - r;
		if(i < B.size())
			s -= B[i];
		
		if(s >= 0)
		{
			r = 0;
			res.push_back(s);
		}
		else
		{
			r = 1; //不够减，借一位
			res.push_back(s+10);
		}
	}
	
	//去除前导零，这里使用while+.back()判断而不是for循环
	while(res.size()>1 && res.back()==0)
		res.pop_back();
	return res;
}

int main()
{
	cin >> a >> b;
	//依旧是倒序存储，准备模拟减法
	//倒序存储：对齐个位，减法从个位减起
	for(int i = a.size()-1; i >= 0; i --)
		A.push_back(a[i]-'0');
	for(int i = b.size()-1; i >= 0; i --)
		B.push_back(b[i]-'0');
	
	if(judge(a,b)) //a>b
		res = sub(A,B);
	else
	{
		printf("-");
		res = sub(B,A);
	}
	
	//得到的是去除前导零的vector，倒序输出即可
	for(int i = res.size()-1; i >= 0; i --)
		cout << res[i];
	return 0;
}