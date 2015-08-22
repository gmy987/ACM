#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 0x7fffffff
#define MAXN 1000
#define MAXM 100000
using namespace std;
int k,n,m,head[MAXN],h[MAXN],path[MAXN],cnt,s,t,maxFlow,minCost;
bool vis[MAXN];
struct Edge
{
    int u,v,w,cap,next;
}edge[MAXM];
void addEdge( int u , int v , int cap , int w)
{
    edge[cnt].v = v , edge[cnt].u = u , edge[cnt].cap = cap;
    edge[cnt].w = w , edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].v = u , edge[cnt].u = v , edge[cnt].cap = 0;
    edge[cnt].w = -w , edge[cnt].next = head[v];
    head[v] = cnt++;
}
bool spfa()
{
    memset( vis , 0 , sizeof(vis));
    memset( h , 0x7f , sizeof(h));
    memset( path , 0xff , sizeof(path));
    h[s] = 0,vis[s] = 1;
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
            if( h[v] > w + h[u] && cap )
            {
                h[v] = w + h[u];
                path[v] = i;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    if( h[t] > k )
        return false;
    return true;
}

void MCMF()
{
    int i,minflow;
    maxFlow = 0 , minCost = 0;
    while(spfa())
    {
        minflow = INF;
        for( i = path[t] ; ~i ; i = path[edge[i].u] )
            minflow = min( minflow , edge[i].cap );
        maxFlow += minflow;
        for( i = path[t] ; ~i ; i = path[edge[i].u])
        {
            edge[i].cap -= minflow;
            edge[i^1].cap += minflow;
        }
        minCost += h[t]*minflow;
    }
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        if( !n && !m && !k ) break;
        memset( head , 0xff , sizeof(head));
        cnt = 0;
        s = 1 , t = n;
        int a,b,i;
        for( i = 2 ; i <= n - 1  ; i++ )
            addEdge( i , n + i , 1 , 0 );
        for( i = 1 ; i <= m ; i++ )
        {
            scanf("%d%d",&a,&b);
            if( a == 1 )
                addEdge( 1 , b , 1 , 1 );
            else
                addEdge( a+n , b , 1 , 1 );
        }
        MCMF();
        printf("%d\n",maxFlow);
    }
}
