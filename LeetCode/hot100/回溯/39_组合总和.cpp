/*
https://leetcode.cn/problems/combination-sum/?envType=study-plan-v2&envId=top-100-liked

DFS【N叉树模型】
注意剪枝的技巧（排序+提前剪枝）
注意是组合而不是排列
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& candidates, int target, int sum, int u)
    {
        if(sum > target)
            return;
        if(sum == target)
        {
            res.push_back(path);
            return;
        }

        for(int i = u; i < candidates.size(); i ++)
        {
            if(sum+candidates[i] > target) //如果加上当前元素之后就超出了，直接break，因为后面的元素更大
                break;
            path.push_back(candidates[i]);
            dfs(candidates,target,sum+candidates[i],i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates,target,0,0);
        return res;
    }
};