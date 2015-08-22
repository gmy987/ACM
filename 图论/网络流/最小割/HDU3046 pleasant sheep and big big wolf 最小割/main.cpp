#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXM 1000000
#define MAXN 40050
#define INF 2139062143
using namespace std;
struct Edge
{
    int cap,to,next;
}edge[MAXM];
int head[MAXN],dis[MAXN],cnt,S,T,n,m;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void addEdge( int u , int v , int cap )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].cap = cap;
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].cap = 0;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
bool bfs()
{
    memset( dis , 0xff , sizeof(dis));
    dis[S] = 0;
    queue<int> q;
    q.push(S);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , cap = edge[i].cap ;
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
    if( x == T || low == 0 )
        return low;
    int flow = 0,a,i;
    for( i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to;
        if( dis[v] == dis[x] + 1 && edge[i].cap )
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
    while(bfs())
        ans += dfs( S , INF );
    return ans;
}
int main()
{
    int num = 1;
    while(~scanf("%d%d",&n,&m))
    {
        memset( head , 0xff , sizeof(head));
        S = 0 , T = n*m+1 , cnt = 0;
        int i,j,a;
        for( i = 1 ; i <= n ; i++ )
            for( j = 1 ; j <= m ; j++ )
            {
                scanf("%d",&a);
                if( a == 1 )
                    addEdge((i-1)*m+j,T,INF);
                else if( a == 2 )
                    addEdge( S , (i-1)*m+j,INF);
                for( int k = 0 ; k < 4 ; k++ )
                {
                    int ax = i+dir[k][0] , ay = j+dir[k][1];
                    if( ax > 0 && ay > 0 && ax <= n && ay <= m)
                        addEdge((i-1)*m+j,(ax-1)*m+ay,1);
                }
            }
        printf("Case %d:\n",num++);
        printf("%d\n",dinic());
    }
}
