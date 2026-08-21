/*
https://leetcode.cn/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-100-liked

堆的应用（优先队列）
- 优先队列原地堆化 O(N)
- 弹出堆顶O(logN)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end()); //原地堆化大顶堆
        for(int i = 0; i < k-1; i ++)
            pq.pop();
        return pq.top();
    }
};