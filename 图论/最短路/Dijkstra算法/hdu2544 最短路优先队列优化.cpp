#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAXM 10005
#define MAXN 120

using namespace std;

struct Edge{
    int to,w,next;
}edge[MAXM];
int dis[MAXN];
int cnt;
int head[MAXN];
void addedge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}
int n,m;
struct cmp
{
    bool operator()( int a , int b )
    {
        return dis[a]>dis[b];
    }
};
int vis[MAXN];
void Dijkstra( int t )
{
    priority_queue<int,vector<int>,cmp> q;
    memset( dis , 0x7f , sizeof(dis) );
    memset( vis , 0 , sizeof(vis) );
    dis[t] = 0;
    q.push(t);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        if(vis[u]) continue;
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
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if( !n && !m )
            break;
        cnt=0;
        int a,b,c;
        memset( head , 0xff , sizeof(head));
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addedge( a , b , c );
            addedge( b , a , c );
        }
        Dijkstra(1);
        printf("%d\n",dis[n]);
    }
    return 0;
}
