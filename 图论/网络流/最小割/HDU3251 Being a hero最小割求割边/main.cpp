#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 50000
#define MAXM 500000
#define INF 0x7fffffff
using namespace std;
struct Edge
{
    int to,next,cap;
}edge[MAXM];
struct Node
{
    int from,to;
}road[MAXM];
int head[MAXN],dis[MAXN],vis[MAXN],cnt,n,m,k,t,T,vr[100005];
void addedge( int u , int v , int cap )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].cap = cap;
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].next = head[v];
    edge[cnt].cap = 0;
    head[v] = cnt++;
}/*
bool bfs()
{
    memset( dis , 0xff , sizeof(dis));
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , cap = edge[i].cap;
            if( dis[v] < 0 && cap )
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[T] > 0;
}
int dfs( int x , int low )
{
    if( x == T )
        return low;
    int a,i;
    for( i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap && ( a = dfs( v , min( cap , low ))))
        {
            edge[i].cap -= a;
            edge[i^1].cap += a;
            return a;
        }
    }
    dis[x] = -1;
    return 0;
}
int dinic()
{
    int ans = 0;
    while(bfs())
        ans += dfs( 1 , INF );
    return ans;
}*/
int gap[MAXN],cur[MAXN],aug[MAXN],pre[MAXN];
int sap( int x , int T , int S )// x = T + 1
{
    int maxflow = 0 , u = S , v;
    int id , mindis;
    aug[S] = INF;
    pre[S] = -1;
    memset( dis , 0 , sizeof(dis));
    memset( gap , 0 , sizeof(gap));
    gap[S] = x;
    for( int i = S ; i <= n ; i++ )
        cur[i] = head[i];
    while(dis[S] < x )
    {
        int flag = 0;
        if( u == T )
        {
            maxflow += aug[T];
            for( v = pre[T] ; ~v ; v = pre[v])
            {
                id = cur[v];
                edge[id].cap -= aug[T];
                edge[id^1].cap += aug[T];
                aug[v] -= aug[T];
                if( edge[id].cap == 0)
                    u = v;
            }
        }
        for( int i = cur[u] ; ~i ; i = edge[i].next )
        {
            v = edge[i].to;
            if( edge[i].cap > 0 && dis[u] == dis[v] + 1)
            {
                flag = 1;
                pre[v] = u;
                cur[u] = i;
                aug[v] = min( aug[u] , edge[i].cap );
                u = v;
                break;
            }
        }
        if( !flag )
        {
            if(--gap[dis[u]] == 0 )
                break;
            mindis = x;
            cur[u] = head[u];
            for( int i = head[u] ; ~i ; i = edge[i].next )
            {
                v = edge[i].to;
                if( edge[i].cap > 0 && dis[v] < mindis )
                {
                    mindis = dis[v];
                    cur[u] = i;
                }
            }
            dis[u] = mindis+1;
            gap[dis[u]]++;
            if( u != S )
                u = pre[u];
        }
    }
    return maxflow;
}
void dfs2( int u )
{
    vis[u] = 1;
    for( int i = head[u] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( !vis[v] && cap )
            dfs2(v);
    }
}
int main()
{
    scanf("%d",&t);
    for( int q = 1 ; q <= t ; q++)
    {
        int i , j , a , b , c , sum = 0 , num = 0 ;
        memset( head , 0xff , sizeof(head));
        memset( vis , 0 , sizeof(vis));
        memset( vr , 0 , sizeof(vr));
        scanf("%d%d%d",&n,&m,&k);
        cnt = 0 , T = n + 1;
        for( i = 0 ; i < m ; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            addedge( a , b , c );
            road[i+1].from = a;
            road[i+1].to = b;
        }
        for( i = 0 ; i < k ; i++ )
        {
            scanf("%d%d",&a,&b);
            sum += b;
            addedge( a , T , b );
        }
        int ans = sum - sap( T+1 , T , 1 );
        printf("Case %d: %d\n",q,ans);
        dfs2(1);
        for( i = 1 ; i <= m ; i++ )
            if( vis[road[i].from] && !vis[road[i].to])
                vr[num++] = i;
        printf("%d",num);
        for( i = 0 ; i < num ; i++ )
                printf(" %d",vr[i]);
        printf("\n");

    }
    return 0;
}
