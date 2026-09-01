#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int month,day;
	cin >> month >> day;
	int a[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	int cnt = 0;
	if(month <= 1)
	{
		int del = day-1; //差的天数
		cnt = del % 7; //对7取模
	}
	else
	{
		int del = 30;
		for(int i = 2; i < month; i ++)
			del += a[i];
		del += day;
		cnt = del % 7;
	}
	
	if(cnt+3 > 7)
		cout << cnt+3-7 << "\n";
	else
		cout << cnt+3 << "\n";
	return 0;
}