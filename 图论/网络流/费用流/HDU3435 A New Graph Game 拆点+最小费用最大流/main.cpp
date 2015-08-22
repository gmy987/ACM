#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 0x7fffffff
#define MAX 2139062143
using namespace std;
struct Edge
{
    int to,from,next,w,cap;
}edge[100000];
int head[5000],dis[5000],pp[5000],cnt,t,n,m,N,mincost,maxflow;
bool vis[5000];
void addEdge( int u , int v , int w , int cap )
{
    edge[cnt].from = u , edge[cnt].to = v , edge[cnt].w = w;
    edge[cnt].next = head[u] , edge[cnt].cap = cap;
    head[u] = cnt++;
    edge[cnt].from = v , edge[cnt].to = u , edge[cnt].w = -w;
    edge[cnt].cap = 0 , edge[cnt].next = head[v];
    head[v] = cnt++;
}

bool spfa()
{
    memset( pp , 0xff , sizeof(pp));
    memset( vis , 0 , sizeof(vis));
    memset( dis , 0x7f , sizeof(dis));
    dis[0] = 0 , vis[0] = 1;
    queue<int> q;
    q.push(0);
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
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[N] != MAX ;
}

void mcmf()
{
    mincost = 0 , maxflow = 0;
    int i , minflow;
    while(spfa())
    {
        minflow = MAX;
        for( i = pp[N] ; ~i ; i = pp[edge[i].from])
            minflow = min( minflow , edge[i].cap );
        maxflow += minflow;
        for( i = pp[N] ; ~i ; i = pp[edge[i].from])
        {
            edge[i].cap -= minflow;
            edge[i^1].cap += minflow;
        }
        mincost += minflow * dis[N];
    }
}
int main()
{
    scanf("%d",&t);
    int num = 1;
    while(t--)
    {
        memset( head , 0xff , sizeof(head));
        scanf("%d%d",&n,&m);
        cnt = 0 , N = 2*n+1;
        int i , a , b , c;
        for( i = 1 ; i <= n ; i++ )
        {
            addEdge( 0 , i , 0 , 1 );
            addEdge( i + n , N , 0 , 1 );
        }
        for( i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge( a , b + n , c , 1 );
            addEdge( b , a + n , c , 1 );
        }
        mcmf();
        printf("Case %d: ",num++);
        if( maxflow == n )
            printf("%d\n",mincost);
        else
            printf("NO\n");
    }
}
