/*
https://leetcode.cn/problems/word-search/?envType=study-plan-v2&envId=top-100-liked

【DFS】网格图模型（本质上还是N叉树）
思路就是DFS搜索去匹配word

注意事项：
- 不要在递归函数中按值传递大规模容器，必要时使用引用传递+恢复现场
- return之前如果已经破坏了现场，一定要恢复现场之后再return
- 某些容器的传递可以优化为使用数字去传递，比如(cur_string -> int u)
- 可以通过原地状态修改的方式代替掉vis数组
- 注意剪枝的细节
*/
class Solution {
public:
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
    bool sta = false;
    void dfs(vector<vector<char>>& board, string& word, int x, int y, int u) //x,y表示要搜索的坐标，u表示要搜word[u]
    {
        if(sta)
            return;
        if(board[x][y] != word[u])
            return;

        //运行到这里说明board[x][y]==word[u]
        if(u == word.size()-1) //完整匹配word
        {
            sta = true;
            return;
        }
        
        board[x][y] = '0';
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < 4; i ++)
        {
            int nex_x = x+dx[i], nex_y = y+dy[i];
            if(nex_x>=0 && nex_x<n && nex_y>=0 && nex_y<m && board[nex_x][nex_y]!='0')
                dfs(board,word,nex_x,nex_y,u+1);
            if(sta)
                break;
        }
        board[x][y] = word[u]; //恢复现场
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
            {
                if(board[i][j] == word[0])
                {
                    dfs(board,word,i,j,0);
                    if(sta)
                        return true;
                }
            }
        return false;
    }
};