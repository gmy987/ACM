#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 2139062143
using namespace std;
struct Edge
{
    int from,to,cap,w,next;
}edge[50000];
int head[400],dis[400],pp[400],n,m,S,T,cnt,maxflow,mincost;
bool vis[400];
void addEdge( int u , int v , int w , int cap )
{
    edge[cnt].from = u , edge[cnt].to = v , edge[cnt].w = w;
    edge[cnt].cap = cap , edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].from = v , edge[cnt].to = u , edge[cnt].w = -w;
    edge[cnt].cap = 0 , edge[cnt].next = head[v];
    head[v] = cnt++;
}
bool spfa()
{
    queue<int> q;
    memset( pp , 0xff , sizeof(pp));
    memset( dis , 0x7f , sizeof(dis));
    memset( vis , 0 , sizeof(vis));
    dis[S] = 0 , vis[S] = 1;
    q.push( S );
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w , cap = edge[i].cap;
            if( cap > 0 && dis[v] > dis[u] + w )
            {
                dis[v] = dis[u] + w;
                pp[v] = i;
                if( !vis[v] )
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[T] != INF;
}
void mcmf()
{
    int minflow,i;
    mincost = 0 , maxflow = 0;
    while(spfa())
    {
        minflow = INF;
        for( i = pp[T] ; ~i ; i = pp[edge[i].from])
            minflow = min( minflow , edge[i].cap );
        maxflow += minflow;
        for( i = pp[T] ; ~i ; i = pp[edge[i].from])
        {
            edge[i].cap -= minflow;
            edge[i^1].cap += minflow;
        }
        mincost += dis[T]*minflow;
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( head , 0xff , sizeof(head));
        T = 2*n+1,cnt = 0,S = 0;
        int i,a,b,c;
        for( i = 1 ; i<= n ; i++ )
        {
            addEdge( 0 , i , 0 , 1 );
            addEdge( i + n , T , 0 , 1 );
        }
        for( i = 1 ; i <= m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge( a , b + n , c , 1 );
        }
        mcmf();
        if( maxflow == n )
            printf("%d\n",mincost);
        else
            printf("-1\n");
    }
    return 0;
}
