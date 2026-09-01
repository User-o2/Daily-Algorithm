/*
同向双指针
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	char tar = s[0];
	int max_len = 0;
	
	int n = s.size();
	//双指针
	for(int i = 0; i < n; i ++)
	{
		int j = i;
		while(j<n && s[j]==s[i])
			j ++;
		int cur_len = j-i;
		if(cur_len > max_len)
		{
			max_len = cur_len;
			tar = s[i];
		}
		i = j-1;
	}
	cout << tar << " " << max_len << "\n";
	return 0;
}