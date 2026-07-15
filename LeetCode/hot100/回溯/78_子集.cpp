/*
https://leetcode.cn/problems/subsets/?envType=study-plan-v2&envId=top-100-liked

【二叉树模型】DFS求解子集
对于每一个元素，有两种选择：选或不选
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(int u, vector<int>& nums)
    {
        if(u == nums.size())
        {
            res.push_back(path);
            return;
        }

        //选
        path.push_back(nums[u]);
        dfs(u+1,nums);
        path.pop_back();

        //不选
        dfs(u+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return res;
    }
};