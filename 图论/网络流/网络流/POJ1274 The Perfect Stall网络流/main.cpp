#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 0x7fffffff
#define MAXM 500000
#define MAXN 10000
using namespace std;
struct Edge{
    int to,cap,next;
}edge[MAXM];
int head[MAXN],dis[MAXN],cnt,n,m,t;
void addedge( int u , int v , int cap )
{
    edge[cnt].to = v;
    edge[cnt].cap = cap;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].cap = 0;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
bool bfs()
{
    memset( dis , 0xff,sizeof(dis));
    dis[0] = 0;
    queue<int>q;
    q.push(0);
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
    return dis[t] > 0 ;
}
int dfs( int x , int low )
{
    if( x == t )
        return low;
    int a , i ;
    for( i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap && ( a = dfs( v , min(cap , low ))))
        {
            edge[i].cap -= a;
            edge[i^1].cap += a;
            return a;
        }

    }
    return 0;
}
int dinic()
{
    int ans = 0;
    while(bfs())
        ans += dfs( 0 , INF );
    return ans;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( head , 0xff , sizeof(head));
        cnt = 0 , t = n + m + 1;
        int i , j , a , b;
        for( i = 1 ; i <= n ; i++ )
        {
            addedge( 0 , i , 1 );
            scanf("%d",&a);
            for( j = 1 ; j <= a ; j++ )
            {
                scanf("%d",&b);
                addedge( i , b + n  , 1 );
            }
        }
        for( i = 1 ; i <= m ; i++ )
            addedge( i + n , t , 1 );
        printf("%d\n",dinic());


    }
}
