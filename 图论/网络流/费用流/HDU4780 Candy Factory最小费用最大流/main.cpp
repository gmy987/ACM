/*
题意：给出m个机器，现在要生产n个糖果，每个糖果可以在任意一个机器上生产，
每个糖果的生产时间是一个区间[s,t]，必须在[s,t)时间内开始生产，
否则就无法生产了，生产的费用为(p-s)*k，p是开始生产的时间。
对于一个机器j来说，从最开始没生产的状态转化为生产第i个糖果的状态需要花费C[i][j]的时间
并花费D[i][j]，对于一个在生产第i个糖果的机器来说，将其转化为生产第j个糖果需要花费E[i][j]的时间并
花费F[i][j]，现在要生产这n个糖果并让所有花费最小。

思路：一看就是个网络流的问题，不过建图还是有些麻烦的，首先将n个糖果拆成两个点，
如果左边第i个糖果生产完，可以生产右边的j，那么连边，流量为1，费用为转换的费用+生产费用，
S向左边的点连边，流量为1，费用为0，右边的点向T连边，流量为1，费用为0。
添加点u，从S向u连边，流量为m，费用为0，再从u向m个点连边，流量为1，费用为0，
接下来m个点代表最开始这个机器生产哪个糖果，如果可以最开始生产某个糖果，向右边的对应点连边，流量为1，
费用为转换费用+生产费用。这样就能保证最后的费用流就是答案。
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXM 300000
#define MAXN 400
#define INF 2139062143
using namespace std;

struct Edge
{
    int to,from,next,w,cap;
}edge[MAXM];
int head[MAXN],dis[MAXN],pp[MAXN],n,m,k,S,T,cnt,mincost,maxflow;
bool vis[MAXN];
int ss[MAXN],tt[MAXN],startT[MAXN][MAXN],startC[MAXN][MAXN];
int changeT[MAXN][MAXN],changeC[MAXN][MAXN];
void addEdge( int u , int v , int cap , int w )
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
    memset( dis , 0x7f , sizeof(dis));
    memset( pp , 0xff , sizeof(pp));
    memset( vis , 0 , sizeof(vis));
    queue<int> q;
    dis[S] = 0;
    q.push(S);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( dis[v] > dis[u] + w && edge[i].cap > 0 )
            {
                dis[v] = dis[u] + w;
                pp[v] = i;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return dis[T] != INF;
}
void mcmf()
{
    mincost = 0 , maxflow = 0;
    int i,minflow;
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
    while(~scanf("%d%d%d",&n,&m,&k)&&n&&m&&k)
    {
        cnt = 0;
        memset( head , 0xff , sizeof(head));
        S = 0 , T = n * 2 + m + 2;
        int i,j;
        for( i = 1 ; i <= n ; i++ )
            scanf("%d%d",&ss[i],&tt[i]);
        for( i = 1 ; i <= n ; i++ )
            for( j = 1 ; j <= m ; j++ )
                scanf("%d",&startT[i][j]);
        for( i = 1 ; i <= n ; i++ )
            for( j = 1 ; j <= m ; j++ )
                scanf("%d",&startC[i][j]);
        for( i = 1 ; i <= n ; i++ )
            for( j = 1 ; j <= n ; j++ )
                scanf("%d",&changeT[i][j]);
        for( i = 1 ; i <= n ; i++ )
            for( j = 1 ; j <= n ; j++ )
                scanf("%d",&changeC[i][j]);
        for( i = 1 ; i <= n ; i++ )
        {
            addEdge( S , i , 1 , 0 );
            addEdge( i + n , T , 1 , 0 );
            for( j = 1 ; j <= n ; j++ )
            {
                if( i!= j && tt[i] + changeT[i][j] < tt[j])
                {
                    int c = max( tt[i] + changeT[i][j] , ss[j]) - ss[j];
                    c *= k;
                    addEdge( i , n + j , 1 , c + changeC[i][j] );
                }
            }
        }
        addEdge( S , n*2 + m + 1 , m , 0 );
        for( i = 1 ; i <= m ; i++ )
        {
            addEdge( n*2+m+1 , i+n*2 , 1 , 0 );
            for( j = 1 ; j <= n ; j++ )
            {
                if( startT[j][i] < tt[j] )
                {
                    int c = max(startT[j][i] , ss[j]) - ss[j];
                    c *= k;
                    addEdge( n*2 + i , j + n , 1 , c + startC[j][i]);
                }
            }
        }
        mcmf();
        if( maxflow == n )
            printf("%d\n",mincost);
        else
            printf("-1\n");
    }
    return 0;
}
