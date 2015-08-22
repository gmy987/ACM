
---------------------------------------------------------------------------
//邻接表模板
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN
#define MAXM
#define INF 0x7fffffff
#define M 2139062143
using namespace std;

struct Edge
{
    int u,v,w,next,cap;
}edge[MAXM<<2];
int cnt,maxFlow,minCost,head[MAXN],dis[MAXN],path[MAXN];
bool vis[MAXN];

void addEdge( int u , int v , int cap , int w)
{
    edge[cnt].v = v , edge[cnt].u = u , edge[cnt].cap = cap;
    edge[cnt].w = w , edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].u = v , edge[cnt].v = u , edge[cnt].w = -w;
    edge[cnt].cap = 0 , edge[cnt].next = head[v];
    head[v] = cnt++;
}

bool spfa( int s , int t , int n )
{
    memset( vis , 0 , sizeof(vis));
    memset( dis , 0x7f , sizeof(dis));
    memset( path , 0xff , sizeof(pp));
    dis[s] = 0 , vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].v , w = edge[i].w , cap = edge[i].cap;
            if( dis[v] > dis[u] + w && cap )
            {
                dis[v] = w + dis[u];
                path[v] = i;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    if( dis[t] == M )
        return false;
    return true;
}

void mcmf( int s , int t , int n )
{
    int i , minflow ;
    maxFlow = 0 , minCost = 0;
    while( spfa( s , t , n ))
    {
        minflow = INF;
        for( i = path[t] ; ~i ; i = path[edge[i].u])
                minflow = min ( edge[i].cap , minflow );
        maxFlow += minflow;
        for( i = path[t] ; ~i ; i = path[edge[i].u])
        {
            edge[i].cap -= minflow;
            edge[i^1].cap += minflow;
        }
        minCost += dis[t]*minflow;
    }
}
int main()
{
    //输入数据
    memset( head , -1 , sizeof(head));
    cnt = 0;//必须为0！！

    /*
    ......建图
    */

    int S , T ; //S为源点，T为汇点
    mcmf( S , T , T + 1 );
    //输出数据，最大流为maxFlow,最小费用为minCost
    return 0;
}
