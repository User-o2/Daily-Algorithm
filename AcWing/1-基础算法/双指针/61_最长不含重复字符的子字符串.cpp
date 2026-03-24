/*
https://www.acwing.com/problem/content/57/

双指针-滑动窗口
*/

class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        int n = s.size();
        vector<int> cnt(27,0);
        int j = 0, res = 0; //j来维护窗口左端点
        for(int i = 0; i < n; i ++) //i维护窗口右端点
        {
            cnt[s[i]-'a'] += 1; //计入窗口内的元素
            while(cnt[s[i]-'a'] > 1)
            {
                cnt[s[j]-'a'] -= 1;
                j ++;
            }
            //一定有j<=i
            res = max(res, i-j+1);
        }
        return res;
    }
};