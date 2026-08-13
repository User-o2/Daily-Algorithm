/*
https://leetcode.cn/problems/min-stack/?envType=study-plan-v2&envId=top-100-liked

【模拟最小栈】
做法：使用一个辅助栈进行同步维护。
同步辅助栈的本质就是在主栈的每一个状态下维护对应的最小值。

NOTE：
手动模拟栈的方式有两种：
1. 使用普通数组：需要额外维护一个栈顶指针；约定top=0表示栈空，top>0表示栈中不空；stk[top]永远指向栈顶
2. 使用 vector：直接使用 .back() 访问栈顶；.empty()查询是否栈空
*/
class MinStack {
private:
    vector<int> stk,min_stk;
public:
    MinStack() {
    }
    
    void push(int value) {
        stk.push_back(value);
        //同步更新辅助栈维护的最小值
        if(min_stk.empty() || min_stk.back()>=value)
            min_stk.push_back(value);
        else
            min_stk.push_back(min_stk.back());
    }
    
    void pop() {
        stk.pop_back();
        min_stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return min_stk.back();
    }
};

/**
 * MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */