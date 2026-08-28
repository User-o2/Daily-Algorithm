/*
https://leetcode.cn/problems/pascals-triangle/?envType=study-plan-v2&envId=top-100-liked

【动态规划】
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        for(int i = 0; i < numRows; i ++)
        {
            res[i].resize(i+1,1); //.resize()成员函数的妙用
            for(int j = 1; j < i; j ++) //res[2][1]开始，只填非首非尾的元素
                res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
        return res;
    }
};