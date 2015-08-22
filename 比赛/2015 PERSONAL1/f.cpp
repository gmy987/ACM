#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAXM 250005
#define MAXN 505
#define INF 0x7fffffff

using namespace std;
int s,t,n;
int dis[MAXN];
int board[MAXN][MAXN];
int vis[MAXN];
int head[MAXN];
int cnt;
struct Edge{
    int to,next,cap;
}edge[MAXM];
void addedge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].cap = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].cap = 0;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
bool bfs()
{
    memset( dis, 0xff , sizeof(dis) );
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , cap = edge[i].cap;
            if( dis[v] < 0 && cap > 0 )
            {
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis[t]>0;
}
int dfs( int x , int low )
{
    if( x == t || low == 0 )
        return low;
    int flow = 0 , a;
    for( int i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap > 0 )
        {
            a = dfs( v , min(low,cap));
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
void init()
{
    memset( head , 0xff,sizeof(head));
    cnt = 0;
  
    for( int i = 1 ; i <= n ; i++ )
        if( i != s && i != t && !vis[i] ) addedge( i , i+n , 1 );
    for( int i = 1 ; i <= n ; i++ )
    {
        if( i != s && board[s][i] && !vis[i]) addedge( s , i , INF );
        if( i != t && board[t][i] && !vis[i]) addedge( i+n , t , INF );
    }
    for( int i = 1 ; i <= n ; i++ )
    {
        if( i == s || i == t ) continue;
        for( int j = 1 ; j <= n ; j++ )
            if( i!=j&&board[i][j]&&j!=s&&j!=t ) addedge( i+n , j , INF );
    }
}
int dinic()
{
    int ans = 0;
    while(bfs())
        ans+=dfs(s,0x7fffffff);
    return ans;
}

int main()
{
    while(~scanf("%d%d%d",&n,&s,&t))
    {
        memset( vis, 0 , sizeof(vis));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= n ; j++ )
                scanf("%d",&board[i][j]);
        if( board[s][t] )
        {
            printf("NO ANSWER!\n");
            continue;
        }
        init();
        int ans = dinic();
        printf("%d\n",ans);
        if( ans == 0 ) continue;
        queue<int> q;
        int tmp = ans;
        for( int i = 1 ; i <= n ; i++ )
        {
                vis[i] = 1;
                init();
                if( dinic() < ans )
                {
                    ans--;
                    q.push(i);
                    continue;
                }
                else vis[i] = 0;
            if( ans == 0 )
                break;
        }
        printf("%d",q.front());
        q.pop();
        while(!q.empty())
        {
            printf(" %d",q.front());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}


