#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x7fffffff
using namespace std;
int head[500],h[500],s,d,cnt,n,m;
struct Edge
{
    int to,cap,next;
}edge[250000];

void addEdge( int u , int v , int cap )
{
    edge[cnt].to = v ;
    edge[cnt].cap = cap , edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].cap = 0 , edge[cnt].next = head[v];
    head[v] = cnt++;
}
bool bfs()
{
    memset( h , 0xff , sizeof(h));
    queue<int> q;
    q.push(s);
    h[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            if( edge[i].cap > 0 && h[v] == -1 )
            {
                h[v] = h[u] + 1;
                q.push(v);
            }
        }
    }
    return h[d] > 0;
}

int dfs( int x , int low )
{
    if( x == d || low == 0 )
        return low;
    int flow = 0 , a;
    for( int i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to;
        if( h[v] == h[x] + 1 && edge[i].cap > 0 )
        {
            a = dfs( v , min( edge[i].cap , low ));
            edge[i].cap -= a;
            edge[i^1].cap += a;
            flow += a;
            low -= a;
            if( low == 0 )
                break;
        }
    }
    return flow;
}

int dinic()
{
    int ans = 0;
    while(bfs()){
        ans+=dfs(s,INF);
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(head , 0xff , sizeof(head));
        scanf("%d%d",&s,&d);
        cnt = 0;
        int i,a,b;
        for( i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&a);
            addEdge( i , i + n , a);
        }
        for( i = 1 ; i <= m ; i++ )
        {
            scanf("%d%d",&a,&b);
            addEdge( n+a , b , INF );
            addEdge( n+b , a , INF );
        }
        d = d + n;
        printf("%d\n",dinic());
    }
    return 0;
}
