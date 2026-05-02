/*
本题原本是手动模拟unordered_set，有两种模拟算法：
- 开放寻址法
- 拉链法
首选开放寻址法
*/
#include<iostream>
#include<unordered_set>
using namespace std;

const int N = 100010;
unordered_set<int> s;
int n;

int main()
{
    cin >> n;
    while(n --)
    {
        string opt;
        cin >> opt;
        if(opt == "I")
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if(opt == "Q")
        {
            int x;
            cin >> x;
            if(s.count(x))
                cout << "Yes" << "\n";
            else
                cout << "No" << "\n";
        }
    }
    return 0;
}