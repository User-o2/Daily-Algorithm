/*
https://leetcode.cn/problems/largest-rectangle-in-histogram/?envType=study-plan-v2&envId=top-100-liked
【单调栈】
三次遍历优化为二次遍历：将vector<int>r的定义改为右侧最近<=i的元素
那么可以直接通过入栈的时候维护
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> stk;
        vector<int> l(n,-1), r(n,n);

        for(int i = 0; i < n; i ++) //寻找左侧最近更小元素
        {
            while(stk.size() && heights[stk.back()]>=heights[i])
            {
                //stk.back()是i的左侧最近的大于等于的元素，则i是stk.back()的右侧小于等于的元素
                r[stk.back()] = i;
                stk.pop_back();
            }
            if(stk.size())
                l[i] = stk.back();
            stk.push_back(i);
        }

        int res = 0;
        for(int i = 0; i < n; i ++)
            res = max(res,(r[i]-l[i]-1)*heights[i]);
        return res;
    }
};