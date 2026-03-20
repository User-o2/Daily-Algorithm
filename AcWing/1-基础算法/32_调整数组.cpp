/*
https://www.acwing.com/problem/content/description/30/
双指针 - 对撞指针
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() <= 1)
            return;
            
        int l = 0, r = array.size()-1;
        while(l < r)
        {
            while(l < r && array[l] % 2 == 1) //在不相撞的前提下，l寻找第一个偶数
                l ++;
            while(l < r && array[r] % 2 == 0) //在不相撞的前提下，r寻找第一个奇数
                r --;
            if(l < r)
            {
                //swap
                int tmp = array[l];
                array[l] = array[r];
                array[r] = tmp;
                
                l ++;
                r --;
            }
        }
    }
};