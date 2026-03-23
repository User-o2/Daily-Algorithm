/*
https://www.acwing.com/problem/content/description/1240/

双指针-滑动窗口

这是一道很好的滑动窗口类题目
这道题滑动窗口比较抽象，因为这个滑动窗口不是“定长数组（一个窗口里框了多少个数）”这一类，在脑海中不容易画出一个固定大小的“框”
这道题的指针l,r只是表象，它真正在滑动的，是一根无形的“时间块”

1. 新的点赞事件记录
r可以理解为“当前时刻”。数组里的每一个元素，都是一个在时间节点发生的点赞事件。
当向r右移动一步，意味着时间线向前推进到了logs[r].ts。
这一时间点，无条件把当前时刻发生的新事件（某个帖子id被点赞）记录到cnt[]。

2. 删除过期的点赞记录
l的作用是删除时间跨度d之外的旧的点赞信息，当前时刻logs[r].ts不断推进，那些曾经的点赞事件就会过期。
一旦logs[r].ts-logs[l].ts>=d，说明第l个点赞事件（由于按时间点排序，所以是第l个）就已经过期了，不属于当前的有效时间窗口
此时，l++，删除过期的点赞记录即可

3. 最后if(cnt[cur_id] >= k)：为什么只检查 cur_id，而不去遍历所有 id？
因为用同一个时间窗口，同时维护了上万个 id 的状态！
经过前两步的记录和清理，此时cnt[]中记录的就是 (log[r].ts-d, log[r].ts] 左开右闭这一时间区间（因为距离当前时刻log[r].ts的跨度不超过d）内**所有帖子**的真实点赞数。
能导致某个帖子在新的事件发生后突然变成热帖的唯一诱因，只能是刚刚发生的这个点赞事件（cur_id）！
所以只检查这个刚刚获得加分的 cur_id 是否突破了 k 的阈值即可。

滑动窗口的思维是一致的（记录新来的、只检查新来的（唯一可能得触发诱因）等等
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 100010;
struct Log{
	int ts,id;
};
int n,d,k;
int cnt[N]; //记录时间跨度为d的滑动窗口内的帖子id对应的点赞数
bool sta[N]; //记录热帖，即满足在任意时间跨度为d的窗口内点数>=k

int main()
{
	scanf("%d%d%d",&n,&d,&k);
	
	vector<Log> logs(n); //无论在全局还是在main内，vector内部的元素都会初始化
	for(int i = 0; i < n; i ++)
		scanf("%d%d",&logs[i].ts, &logs[i].id);
	
	//按照点赞信息的时间点进行排序，后面双指针以时间窗口为判断条件
	sort(logs.begin(),logs.end(),[](Log& a, Log& b)
	{
		if(a.ts != b.ts)
			return a.ts < b.ts;
		else
			return false;
	});
	
    //双指针-滑动窗口
    int l = 0; //左指针，如果窗口内的点赞超过时间跨度d，就进行右移
    for(int r = 0; r < n; r ++) //右指针维护窗口右端，遍历所有的点赞信息
    {
        int cur_id = logs[r].id; //当前被点赞的帖子id
        cnt[cur_id] ++; //记录新的点赞信息
        while(l < r && logs[r].ts-logs[l].ts>=d) //因为是按时间排好序的，维护一个时间跨度为d的滑动窗口
        {
            cnt[logs[l].id] --;
            l ++;
        }
        //while退出之后的滑动窗口[logs[l].ts,logs[r].ts]一定是满足时间跨度为d的，那么检查点赞数即可
        if(cnt[cur_id] >= k) //对于遍历的当前id，检查在当前跨度为d的时间段内当前帖子的点赞数（因为触发点赞数>=k的一定是新加之后的点赞id）
            sta[cur_id] = true;
    }
	
	for(int id = 0; id < N; id ++)
		if(sta[id])
			printf("%d\n",id);
	return 0;
}