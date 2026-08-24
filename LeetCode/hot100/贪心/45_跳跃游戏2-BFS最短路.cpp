/*
https://leetcode.cn/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-100-liked

【BFS】
本题是求“最小跳跃次数”，一个想法就是把它转化为一个求最短路的问题->BFS。

BFS状态空间树：第一层是起点，第二层是起点可以到达的所有节点...以此类推。
这样就是一个类似层序遍历的BFS。

对于每一个节点，入队后立马检查是否为目标节点，并且注意添加对起点的检查
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        queue<int> q;

        int res = 0; //当前的层数
        q.push(0); //起点这里无需检查是否为终点，因为if(n==1)已经判断过了
        int vis_bound = 0; //已经访问到的边界

        while(q.size())
        {
            int sz = q.size(); //当前层的节点个数
            for(int i = 0; i < sz; i ++) //出队、扩展当前层的每一个节点
            {
                int cur = q.front(); q.pop();
                for(int nex = vis_bound+1; nex <= cur+nums[cur]; nex ++) //当前节点可以到达的下一个节点，并且没有到达过
                {
                    if(nex >= n)
                        break;

                    q.push(nex); //必定没有访问过
                    if(nex == n-1) //入队的时候立马检查
                        return res+1;
                }
                //更新到达的最远边界
                vis_bound = max(vis_bound,cur+nums[cur]);
            }
            res ++; //下一层
        }
        return 0; //保底返回
    }
};


//上面代码其实对内层的循环进行了优化（使用vis_bound而不是vis[]）
//没有优化的朴素 BFS 实现如下：
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        vector<bool> vis(n,false);
        queue<int> q;

        int res = 0; //当前的层数
        q.push(0);
        vis[0] = true;
        //起点这里无需检查是否为终点，因为if(n==1)已经判断过了

        while(q.size())
        {
            int sz = q.size(); //当前层的节点个数
            for(int i = 0; i < sz; i ++) //出队、扩展当前层的每一个节点
            {
                int cur = q.front(); q.pop();
                for(int j = 1; j <= nums[cur]; j ++) //当前节点可以到达的下一个节点
                {
                    int nex = cur+j;
                    if(nex >= n) //越界了，没有必要继续
                        break;
                    if(vis[nex] == false)
                    {
                        q.push(nex);
                        vis[nex] = true;

                        //NOTE:入队的时候立马检查
                        if(nex == n-1)
                            return res+1;
                    }
                }
            }
            res ++; //下一层
        }
        return 0; //保底返回
    }
};