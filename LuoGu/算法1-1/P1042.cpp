
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int N  = 2510;
string s[N];
int idx;

void output_res(int num)
{
	int w = 0, l = 0;
	for(int cnt = 0; cnt < idx; cnt ++)
	{
		string info = s[cnt];
		for(int i = 0; i < info.size(); i ++)
		{
			if(info[i]=='W')
			{
				w ++;
				if(w >= num && abs(w-l)>=2)
				{
					cout << w << ":" << l << "\n";
					w = 0, l = 0;
				}
			}
			else if(info[i] == 'L')
			{
				l ++;
				if(l>=num && abs(w-l)>=2)
				{
					cout << w << ":" << l << "\n";
					w = 0, l = 0;
				}
			}
			else if(info[i]=='E')
			{
				cout << w << ":" << l << "\n";
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string str;
	while(cin >> str)
		s[idx++] = str;
	
	output_res(11);
	cout << "\n";
	output_res(21);
	return 0;
}