/*
https://leetcode.cn/problems/longest-palindromic-substring/?envType=study-plan-v2&envId=top-100-liked

双指针-【中心扩展法】O(N^2)
根据两个指针的移动方向与相对关系，分为三种：
1.同向双指针（快慢指针、滑动窗口）
2.相向双指针（对撞指针）
3.背向双指针（扩散指针）-> 中心扩展法即为典型代表

中心扩展法的核心思想就是枚举子串的中心，逐步向左右扩展判断是否是回文串。
- 奇回文串：以单个字母作为扩展的中心
- 偶回文串：以双字母作为扩展的中心

中心扩展法的经典应用场景：回文子串（注意不是回文子序列）
- 回文子串的计数问题
- 求最长回文子串
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int res_l = 0, res_r = -1; //NOTE:技巧，使用2个指针即可维护答案字符串s[res_l:res_r]
        //奇回文串
        for(int i = 0; i < n; i ++) //以s[i]为中心，逐步扩展
        {
            int l = i, r = i;
            while(l>=0 && r<n && s[l]==s[r]) //对于每一个扩展中心，尽力扩展到最边界
            {
                l --;
                r ++;
            }
            //实际的回文串为[l+1:r-1]，指针维护的答案为[res_l:res_r]
            if(r-l-1 > res_r-res_l+1)
            {
                res_l = l+1;
                res_r = r-1;
            }
        }

        //偶回文串
        for(int i = 0; i < n-1; i ++) //以s[i],s[i+1]作为中心，逐步扩展
        {
            int l = i, r = i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l --;
                r ++;
            }
            if(r-l-1 > res_r-res_l+1)
            {
                res_l = l+1;
                res_r = r-1;
            }
        }

        return s.substr(res_l, res_r-res_l+1);
    }
};