/*
https://leetcode.cn/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-100-liked

【二分】
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n*m-1; //查找存在性问题，解空间设为[0,n-1]更方便
        while(l < r)
        {
            int mid = (l+r)/2;
            int x = mid/m, y = mid%m;
            if(matrix[x][y] >= target)
                r = mid;
            else
                l = mid+1;
        }
        
        if(matrix[l/m][l%m] == target)
            return true;
        else
            return false;
    }
};