/*
https://leetcode.cn/problems/permutations/?envType=study-plan-v2&envId=top-100-liked

DFS-全排列
【N叉树模型】以“填坑”的思想进行求解
*/
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int u, vector<int>& path, vector<bool>& sta)
    {
        if(u == nums.size())
        {
            res.push_back(path);
            return;
        }

        //对于本坑位，尝试所有可能的数字
        for(int i = 0; i < nums.size(); i ++)
        {
            if(sta[i] == false)
            {
                path.push_back(nums[i]);
                sta[i] = true;
                dfs(nums,u+1,path,sta);
                path.pop_back();
                sta[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        int n = nums.size();
        vector<bool> sta(n,false);
        vector<int> path;

        dfs(nums,0,path,sta);
        
        return res;
    }
};