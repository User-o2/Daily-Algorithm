/*
https://www.acwing.com/problem/content/791/

二分查找
因为整数数组按照升序排列，可以使用二分确定边界
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100000;
int n,q,k;
int a[N];

int main()
{
    scanf("%d%d",&n,&q);
    for(int i = 0; i < n; i ++)
        scanf("%d",&a[i]);
    while(q --)
    {
        scanf("%d",&k);
        int l_idx = -1, r_idx = -1;
        
		//查找左边界
        int l = 0, r = n-1;
        while(l < r)
        {
        	int mid = l+r >> 1;
        	if(a[mid] >= k)
        		r = mid;
        	else
        		l = mid+1;
		}
		
		//检查数组中是否存在k
		if(a[l] != k)
			printf("-1 -1\n");
		else
		{
			l_idx = l;
			
			//查找右边界
			l = 0, r = n-1;
			while(l < r)
			{
				int mid = l+r+1 >> 1;
				if(a[mid] <= k)
					l = mid;
				else
					r = mid-1;
			}
			//当左边界存在时，右边界是一定存在的
			r_idx = l;
			printf("%d %d\n",l_idx,r_idx);
		}
    }
    return 0;
}