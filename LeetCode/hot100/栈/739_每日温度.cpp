/*
https://leetcode.cn/problems/daily-temperatures/?envType=study-plan-v2&envId=top-100-liked

【单调栈】
寻找右边最近的更大元素
- 从右向左遍历
- 如果栈顶元素<=当前遍历到的元素，那么栈顶元素不可能是答案，出栈
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> stk;
        vector<int> res(temp.size());

        //从右向左遍历
        for(int i = temp.size()-1; i >= 0; i --)
        {
            //1.栈顶删除
            while(stk.size() && temp[stk.back()]<=temp[i])
                stk.pop_back();
            if(stk.size())
                res[i] = stk.back()-i;
            else
                res[i] = 0;
            
            //2.栈顶插入
            stk.push_back(i);
        }
        return res;
    }
};