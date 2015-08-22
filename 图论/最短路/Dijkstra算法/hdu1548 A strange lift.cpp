#include <cstring>
#include <iostream>
#include <queue>
#include <cstdio>
#define MAXN 300
#define MAXM 90000
#define INF 2139062143

using namespace std;
struct Edge{
    int to,from,next,w;
}edge[MAXM];
int head[MAXN],dis[MAXN];
bool vis[MAXN];
int cnt;
int n,a,b;
void addedge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}
void dijkstra()
{
    int k;
    dis[a] = 0;
    for( int i = 1 ; i <= n ; i++ )
    {
        k = 0;
        for( int j = 1 ; j <= n ; j++ )
            if( !vis[j] && (!k||dis[j]<dis[k]))
                k = j;
        vis[k] = 1;
        for( int i = head[k] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            dis[v] = min(dis[v],dis[k]+w);
        }
    }
}
int main()
{
    while(~scanf("%d",&n) && n )
    {
        scanf("%d%d",&a,&b);
        int c;
        cnt = 0 ; 
        memset( head , 0xff , sizeof(head));
        memset( dis , 0x7f , sizeof(dis));
        memset( vis , 0 , sizeof(vis));
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&c);
            if( i-c>=1)
                addedge( i , i-c , 1 );
            if( i+c <= n )
                addedge( i , i+c , 1 );
        }
        dijkstra();
        if( dis[b] == INF )
            printf("-1\n");
        else
            printf("%d\n",dis[b]);
    }
    return 0;
}
