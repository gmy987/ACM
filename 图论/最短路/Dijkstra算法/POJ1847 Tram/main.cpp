#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;
struct Edge
{
    int to,next,w;

}edge[10005];
int head[200],h[200],n,a,b,cnt,w;
bool vis[200];

void addEdge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}

/*
void spfa()
{
    memset( vis , 0 ,sizeof( vis ));
    memset( h , 0x7f , sizeof(h));
    vis[a] = 1;
    h[a] = 0;
    queue<int> q;
    q.push(a);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] > w + h[u])
            {
                h[v] = w + h[u];
                if( !vis[v] )
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}*/

struct cmp{
    bool operator()( int a , int b )
    {
        return h[a] > h[b];
    }
};
void Dijkstra()
{
    memset( vis , 0 , sizeof(vis));
    memset( h , 0x7f , sizeof(h));
    h[a] = 0;
    priority_queue<int,vector<int>,cmp> q;
    q.push(a);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        vis[u] = 1;
        for( int i = head[u] ; ~i ; i = edge[i].next )
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

int main()
{
    while(~scanf("%d%d%d",&n,&a,&b))
    {
        memset(head , -1 , sizeof(head));
        cnt = 1;
        int c;
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&w);
            for( int j = 0 ; j < w ; j++ )
            {
                scanf("%d",&c);
                if( j == 0 )
                    addEdge( i , c , 0 );
                else
                    addEdge( i , c , 1 );
            }
        }
        Dijkstra();
        int temp = h[b];
        if( temp == 2139062143)
            printf("-1\n");
        else
            printf("%d\n",temp);
    }
}
