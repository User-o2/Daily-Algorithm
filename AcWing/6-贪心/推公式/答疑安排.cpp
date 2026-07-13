/*
https://www.lanqiao.cn/problems/1025/learning/
答疑安排

顺序调度类问题，可使用“邻项交换法”进行推导
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
struct Time
{
    int s,a,e;
};
Time stu[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> stu[i].s >> stu[i].a >> stu[i].e;
    
    sort(stu,stu+n,[](const Time& x, const Time& y){
        return x.s+x.a+x.e <= y.s+y.a+y.e;
    });

    long long res = 0;
    int e_i = 0, t = 0;
    for(int i = 0; i < n; i ++)
    {
        t += e_i + stu[i].s + stu[i].a;
        res += t;
        e_i = stu[i].e;
    }
    cout << res << "\n";
    return 0;
}