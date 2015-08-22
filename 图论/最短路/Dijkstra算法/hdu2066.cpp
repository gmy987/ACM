#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define MAXM 1000006
#define MAXN 300
#define INF 0x7fffffff

using namespace std;
struct Edge{
    int to,w,next;
}edge[MAXM];
int dis[MAXN],vis[MAXN],head[MAXN];
int cnt;
void addedge( int u , int v, int w )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}
struct cmp
{
    bool operator()( int a, int b )
    {
        return dis[a]>dis[b];
    }
};
void Dijkstra( int t )
{
    priority_queue<int,vector<int>,cmp> q;
    dis[t] = 0;
    q.push(t);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        if( vis[u] ) continue;
        vis[u] = 1;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( dis[v] > dis[u] + w )
            {
                dis[v] = dis[u] + w;
                q.push(v);
            }
        }
    }
}
int t,s,d;

int main()
{
    while(~scanf("%d%d%d",&t,&s,&d))
    {
        cnt = 0;
        memset( head , 0xff, sizeof(head) );
        memset( vis , 0 , sizeof(vis) );
        memset( dis , 0x7f , sizeof(dis) );
        int a,b,c;
        for( int i = 0 ; i < t ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
        }
        for( int i = 0 ; i < s ; i++ )
        {
            scanf("%d",&a);
            addedge( 0 , a , 0 );
            addedge( a , 0 , 0 );
        }
        int ans = INF;
        Dijkstra(0);
        for( int i = 0 ; i < d ; i++ )
        {
            scanf("%d",&a);
            ans = min( ans , dis[a] );
        }
        printf("%d\n",ans);
    }
    return 0;
}
