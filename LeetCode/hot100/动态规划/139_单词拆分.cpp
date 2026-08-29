/*
https://leetcode.cn/problems/word-break/?envType=study-plan-v2&envId=top-100-liked

【动态规划】
1.状态定义：定义f[i]为字符串的前i个字符[0:i-1]是否可以被拼成（false/true）。
2.状态转移：
f[i] 属于 {false,true}。使用一个指针j遍历分割点，将前i个字符[0:i-1]拆分为[0:j-1]和[j:i-1]。那么f[i]==true就需要满足：
- 前缀可被拼成：[0:j-1]可以被拼成，即f[j]=true
- 后缀是字典中的单词：[j:i-1]是字典中的一个单词
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> f(n+1,false);

        //准备O(1)的查询集
        unordered_map<string,bool> dict;
        for(auto& ele : wordDict)
            dict[ele] = true;

        f[0] = true; //base case：前0个字符可以被拼成
        for(int i = 1; i <= n; i ++) //f[i]
        {
            for(int j = 0; j < i; j ++) //分割点
            {
                string str = s.substr(j,i-j);
                if(f[j]==true && dict.count(str)) //前缀可被拼成、后缀是字典中的单词
                {
                    f[i] = true;
                    break; //一旦找到可以被拼成的方式，就直接 break
                }
            }
        }
        return f[n];
    }
};