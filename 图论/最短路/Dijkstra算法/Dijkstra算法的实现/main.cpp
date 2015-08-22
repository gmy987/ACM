#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

//dijkstra算法用于求源点到图中各点的最短路径
void Dijkstra( int t , int n )//t表示源点,n表示点的个数
{
    int k;//用于记录当前未访问过的点中当前距离远点最近的点
    bool vis[MAXN];//MAXN代表点的个数；
    int h[MAXN];//h[i]用于储存i点到源点的距离
    memset( vis , 0 , sizeof( vis ));
    memset( h , 0x7F , sizeof(h));//将h中的值初始为最大
    h[t] = 0;//源点到它自己的距离为0
    for( int i = 1 ; i <= n ; i++ )
    {
        k = 0;
        for( i = 1 ; i<= n ; i++ )
            if(!vis[i]&&(!k||h[i]<h[k]))
                k = i;
        vis[k] = 1;
        for( i = head[k] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to;
            h[v] = min( h[v] , h[k] + edge[i].w );
        }
    }
}

/////////////////////////////////////////////////////////////////////
//dijkstra算法的优先队列优化
struct cmp
{
    bool operator() ( int a , int b )
    {
        return h[a]>h[b];
    }
};//使h值小的优先级较高

void Dijkstra(int t, int n)//t表示源点
{
    priority_queue<int,vector<int>,cmp> q;
    memset(h,0x7f,sizeof(h));
    memset(vis,0,sizeof(vis));
    h[t] = 0;
    q.push(t);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if(h[v]>h[u]+w)
            {
                h[v] = h[u] + w;
                q.push(v);
            }
        }
    }
}
