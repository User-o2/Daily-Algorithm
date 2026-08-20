/*
https://leetcode.cn/problems/largest-rectangle-in-histogram/?envType=study-plan-v2&envId=top-100-liked
【单调栈】
对于每一个柱子，求以本柱子的高度为长、最大宽度为宽的矩形面积，然后取一个max即可
那么对于每一个柱子，就要向左、向右尽可能的扩充：使用单调栈去寻找左侧最近更小、右侧最近更小的柱子位置，即可计算出宽度
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> stk;
        int n = heights.size();
        vector<int> l(n,-1), r(n,n);

        for(int i = 0; i < n; i ++) //寻找左侧最近较小
        {
            while(stk.size() && heights[stk.back()]>=heights[i])
                stk.pop_back();
            if(stk.size())
                l[i] = stk.back();
            stk.push_back(i);
        }

        stk.clear();
        for(int i = n-1; i >= 0; i --) //找右侧最近更小
        {
            while(stk.size() && heights[stk.back()]>=heights[i])
                stk.pop_back();
            if(stk.size())
                r[i] = stk.back();
            stk.push_back(i);
        }

        int res = 0;
        for(int i = 0; i < n; i ++)
            res = max(res, (r[i]-l[i]-1)*heights[i]);
        return res;
    }
};