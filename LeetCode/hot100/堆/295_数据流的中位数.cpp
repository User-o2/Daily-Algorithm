/*
https://leetcode.cn/problems/find-median-from-data-stream/?envType=study-plan-v2&envId=top-100-liked

【中位数+堆的应用】：实时添加元素、实时查询中位数
思路：
1.和之前的中位数+二分的题目很像，回归到中位数的本质：中位数是可以将一个元素序列划分为左右相等的两部分。左部分中的元素<=右部分中的元素。规定左部分元素的个数与右部分元素的个数相等（或左部分多1）。
2.当序列元素个数为奇数，此时左部分元素个数多1，中位数为左部分的最大值；当序列元素个数为偶数，此时左部分元素个数等于右部分，中位数为(左部分最大值+右部分最小值)/2。
3.使用大根堆维护左部分，小根堆维护右部分。添加数字的规则：
- 若当前左部分个数==右部分个数：num加入右，右.top加入左；
- 若当前左部分个数>右部分个数：num加入左，左.top加入右
*/
class MedianFinder {
private:
    priority_queue<int> left; //大根堆
    priority_queue<int,vector<int>,greater<int>> right; //小根堆
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(left.size() == right.size())
        {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        else
        {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
        //NOTE：以这种逻辑add，那么就会自动维护好左右的数量关系吗？
        //是的，利用堆的最值特性满足大小关系（保证左部分所有元素<= right中所有元素）、利用添加数字的规则满足数量关系（每次插入，两个堆交替净增 1，永远满足 left.size() == right.size() 或 left.size() == right.size()+1）
    }
    
    double findMedian() {
        if(left.size() == right.size())
            return (double(left.top())+double(right.top()))/2;
        else
            return double(left.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */