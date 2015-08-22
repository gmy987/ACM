#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 2139062143
using namespace std;
struct Edge
{
    int to,from,next,cap,w;
}edge[50000];
int head[200],dis[500],pp[500],N,m,k,cnt,mincost,maxflow;
bool vis[500];
void addEdge( int u , int v , int w , int cap )
{
    edge[cnt].from = u  , edge[cnt].to = v , edge[cnt].w = w;
    edge[cnt].cap = cap , edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].from = v , edge[cnt].to = u , edge[cnt].w = -w;
    edge[cnt].cap = 0 , edge[cnt].next = head[v];
    head[v] = cnt++;
}
bool spfa()
{
    memset( pp , 0xff , sizeof(pp));
    memset( dis , 0x7f , sizeof(dis));
    memset( vis , 0 , sizeof(vis));
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( edge[i].cap > 0 && dis[v] > dis[u] + w )
            {
                dis[v] = dis[u] + w;
                pp[v] = i;
                if( !vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[N] != INF;
}

void mcmf()
{
    mincost = 0 , maxflow = 0;
    int i , minflow;
    while( spfa() )
    {
        minflow = INF;
        for( i = pp[N] ; ~i ; i = pp[edge[i].from])
            minflow = min( minflow , edge[i].cap );
        maxflow += minflow;
        for( i = pp[N] ; ~i ; i = pp[edge[i].from])
        {
            edge[i].cap -= minflow;
            edge[i^1].cap += minflow;
        }
        mincost += dis[N] * minflow;
    }
}
int main()
{
    while(~scanf("%d%d%d",&N,&m,&k))
    {
        memset( head , -1 , sizeof(head));
        cnt = 0;
        int i,j,a,b,c,d;
        for( i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            for( j = 1 ; j <= d ; j++ )
                addEdge( a , b , (2*j-1)*c , 1);
        }
        addEdge( 0 , 1 , 0 , k);
        mcmf();
        if( maxflow == k )
            printf("%d\n",mincost);
        else
            printf("-1\n");
    }
    return 0;
}
