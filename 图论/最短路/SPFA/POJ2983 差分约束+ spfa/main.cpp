#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct Edge
{
    int to,next,w;
}edge[210000];
int head[1005],h[1005],n,m,cnt,c[1005];
bool vis[1005];
void addEdge( int u , int v , int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
bool spfa()
{
    memset( vis , 0 , sizeof(vis));
    memset( h , -1 , sizeof(h) );
    memset( c , 0 , sizeof(c));
    c[0]++;
    vis[0] = 1;
    h[0] = 0;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] < w + h[u])
            {
                h[v] = w + h[u];
                if( !vis[v] )
                {
                    vis[v] = 1;
                    q.push(v);
                }
                c[v]++;
                if(c[v] > n) return true;
            }
        }
    }
    return false;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        char a;
        int b,c,d;
        cnt = 1;
        memset( head , -1 , sizeof(head));
        for( int i = 0 ; i < m ; i++ )
        {
            cin >> a;
            if( a == 'P' )
            {
                scanf("%d%d%d",&b,&c,&d);
                addEdge( b , c , d);
                addEdge( c , b , -d);
            }
            else
            {
                scanf("%d%d",&b,&c);
                addEdge( b , c , 1 );// b - c >= 1
            }
        }
        for( int i = 1 ; i <= n ; i++ )
            addEdge( 0 , i , 0);
        if(spfa())
            printf("Unreliable\n");
        else
            printf("Reliable\n");
    }
}
