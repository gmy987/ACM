//差分约束系统
//卡时间，如果用spfa会超时，改成dij+heap可过

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge
{
    int to,next,w;
}edge[150005];

int head[30005],h[30005],n,m,cnt;
bool vis[30005];

void addEdge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
struct cmp
{
    bool operator()( int a , int b )
    {
        return h[a] > h[b];
    }
};
void Dijkstra()
{
    memset( h , 0x7f , sizeof( h ));
    h[1] = 0;
    priority_queue<int,vector<int>,cmp> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] > w + h[u] )
            {
                h[v] = w + h[u];
                q.push(v);
            }
        }
    }
}
/*
void spfa()
{
    memset( vis , 0 , sizeof(vis));
    memset( h , 0x7f , sizeof(h));
    h[1] = 0;
    vis[1] = 1;
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] > w + h[u])
            {
                h[v] = w + h[u];
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
*/
int main()
{
    scanf("%d%d",&n,&m);
    cnt = 1;
    memset( head , - 1 , sizeof(head));
    int a,b,c;
    for( int i = 0 ; i < m ; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        addEdge( a , b , c );
    }
    Dijkstra();
    printf("%d\n",h[n]);
}
