#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAXM 100000
#define MAXN 400
#define INF 0x7fffffff
using namespace std;
int head[MAXN],dis[MAXN],n,m,s,h,T,cnt;
struct Edge{
    int to,next,cap;
}edge[MAXM];
void addEdge( int u , int v , int cap )
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
    memset( dis , 0xff , sizeof(dis));
    queue<int> q;
    q.push(s);
    dis[s] = 0;
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
    int a , i ;
    for( i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap && ( a = dfs( v , min( low , cap ))))
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
        ans += dfs(s,INF);
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset( head , 0xff , sizeof( head ));
        cnt = 0;
        scanf("%d%d%d%d",&n,&m,&s,&h);
        int a,i,j,b;
        T = h+n;
        for( i = 1 ; i <= n ; i++)
        {
            scanf("%d",&a);
            if( i == s )
            {
                addEdge( s , s+n , INF );
                addEdge( s+n , s , INF );
            }
            else if( i == h )
            {
                addEdge( h , h+n , INF );
                addEdge( h+n , h , INF );
            }
            else
            {
                addEdge( i , i+n , a );
                addEdge( i+n , i , a );
            }
        }
        for( i = 1 ; i <= m ; i++ )
        {
            scanf("%d%d",&a,&b);
            addEdge( a+n,b,INF );
            addEdge( b+n,a, INF );
        }
        printf("%d\n",dinic());
    }
    return 0;
}
