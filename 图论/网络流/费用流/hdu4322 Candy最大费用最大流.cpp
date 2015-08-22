#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAXM 100000
#define MAXN 500
#define INF 2139062143

using namespace std;

struct Edge
{
    int from , to , cap , next , w ;
}edge[MAXM];

int head[MAXN],dis[MAXN],cnt,n,m,k,S,t,T,b[20],maxflow,mincost;
void addedge( int u , int v , int cap , int w  )
{
    edge[cnt].to = v , edge[cnt].w = w , edge[cnt].next = head[u];
    edge[cnt].cap = cap , edge[cnt].from = u;
    head[u] = cnt++;
    edge[cnt].to = u , edge[cnt].from = v , edge[cnt].w = -w;
    edge[cnt].cap = 0 , edge[cnt].next = head[v];
    head[v] = cnt++;
}
int vis[MAXN],pp[MAXN];
bool spfa( int s , int t , int n )
{
    memset( vis , 0 , sizeof(vis));
    memset( dis , 0x7f , sizeof(dis));
    memset( pp , 0xff , sizeof(pp));
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
            int v = edge[i].to , w = edge[i].w , cap = edge[i].cap;
            if( dis[v] > dis[u] + w && cap )
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
    return dis[t]!=INF;
}

void mcmf( int s , int t , int n )
{
    int i , minflow;
    maxflow = 0 , mincost = 0;
    while(spfa(s,t,n))
    {
        minflow = INF ;
        for( i = pp[t] ; ~i ; i = pp[edge[i].from])
            minflow = min( minflow , edge[i].cap );
        maxflow += minflow;
        for( i = pp[t] ; ~i ; i = pp[edge[i].from])
        {
            edge[i].cap -= minflow;
            edge[i^1].cap += minflow;
        }
        mincost += dis[t]*minflow;
    }
}
int like[50][50];

int main()
{
    scanf("%d",&t);
    int cas = 1;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        S = 0 , T = n+m+1 , cnt = 0;
        memset( head , 0xff , sizeof(head));
        int sum = 0;
        for( int i = 1 ; i <= m ; i++ )
        {
            scanf("%d",&b[i]);
            sum += b[i];
        }
        for( int i = 1 ; i <= n ; i++ )
            addedge( S , i , 1 , 0 );
        for( int i = 1 ; i <= m ; i++ ){
            for( int j = 1 ; j <= n ; j++)
            {
                scanf("%d",&like[i][j]);
                if( like[i][j] == 1 )
                    addedge( j , i + n , 1 , 0 );
            }
            addedge( i+n , T , b[i]/k , k );
            if( b[i]%k > 1 )
                addedge( i+n , T , 1 , b[i]%k );
        }
        printf("Case #%d: ",cas++);
        mcmf( S , T , T + 1 );
        if( n - maxflow >= sum - mincost )
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
