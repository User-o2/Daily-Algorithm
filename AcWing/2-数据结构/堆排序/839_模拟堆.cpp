/*
https://www.acwing.com/problem/content/description/841/

使用数组模拟[堆]
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int N = 100010;
int h[N],sz; //维护[堆]所需要的变量
int cnt; //第几个插入
int order2idx[N], idx2order[N]; //双向映射
int n;

void heap_swap(int idx1, int idx2) //交换映射
{
	int order1 = idx2order[idx1], order2 = idx2order[idx2];
	//这三行swap的顺序是无所谓的，相互独立
	swap(order2idx[order1], order2idx[order2]); //理解：原来第order1插入的数换到索引idx2了，原来order2插入的数换到索引idx1了
	swap(idx2order[idx1],idx2order[idx2]);
	swap(h[idx1],h[idx2]);
}

void down(int x) //下沉操作
{
	//下沉操作要和左右子节点比较
	int t = x; //小根堆，寻找节点x、节点x的左子节点、节点x的右子节点这三者中最小的节点
	if(2*x<=sz && h[2*x]<h[t])
		t = 2*x;
	if(2*x+1<=sz && h[2*x+1]<h[t])
		t = 2*x+1;
	if(t != x)
	{
		heap_swap(t,x);
		down(t);
	}
}

void up(int x) //上浮操作
{
	//上浮操作只和父节点比较即可
	if(x/2>0 && h[x/2]>h[x]) //小根堆，父节点更大当前节点上浮
	{
		heap_swap(x/2,x);
		up(x/2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	while(n --)
	{
		string opt;
		cin >> opt;
		if(opt == "I")
		{
			//插入一个数：插入到堆尾然后上浮
			int x;
			cin >> x;
			sz ++;
			cnt ++;
			idx2order[sz] = cnt;
			order2idx[cnt] = sz;
			h[sz] = x;
			up(sz);
		}
		else if(opt == "PM") //输出最小值
			cout << h[1] << "\n";
		else if(opt == "DM")
		{
			//删除最小值
			//移到堆尾
			heap_swap(1,sz);
			sz --;
			down(1);
		}
		else if(opt == "D")
		{
			//删除第k个插入的数：将该数与堆尾进行交换
			int k;
			cin >> k;
			int idx = order2idx[k];
			heap_swap(idx,sz);
			sz --;
			down(idx);
			up(idx);
		}
		else if(opt == "C")
		{
			int k,x;
			cin >> k >> x;
			int idx = order2idx[k];
			h[idx] = x;
			down(idx);
			up(idx);
		}
	}
	return 0;
}