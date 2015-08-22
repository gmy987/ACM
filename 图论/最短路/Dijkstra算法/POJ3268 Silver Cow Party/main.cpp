#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge{
    int to,next,w;
}edge[100005];

int head[1005],h[1005],n,m,x,cnt;
bool vis[1005];
void addEdge( int u , int v , int w)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}
struct cmp
{
    bool operator() ( int a , int b )
    {
        return h[a] > h[b] ;
    }
};
struct Node
{
    int x,y;
}node[1005];
void Dijkstra(int i)
{
    memset( h , 0x7f , sizeof(h));
    memset(vis,0,sizeof(vis));
    h[i] = 0;
    priority_queue<int,vector<int>,cmp> q;
    q.push(i);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        vis[u] = 1;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] > h[u] + w )
            {
                h[v] = h[u] + w;
                q.push(v);
            }
        }
    }
}
bool cmp2 ( Node a , Node b)
{
    return a.x + a.y > b.x + b.y;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&x))
    {
        cnt = 1;
        int a,b,c;
        memset( head , -1 , sizeof( head ));
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge( b , a , c );
        }
        int m1 = 0 , m2 = 0;
        for( int i = 1 ; i <= n ; i++ )
        {
            Dijkstra(i);
            if( i == x )
                for( int j = 1 ; j <= n ; j++ )
                    node[j].y = h[j];
            node[i].x = h[x];
        }
        sort( node + 1 , node + n + 1 , cmp2);
        printf("%d\n",node[1].x + node[1].y);
    }
}
