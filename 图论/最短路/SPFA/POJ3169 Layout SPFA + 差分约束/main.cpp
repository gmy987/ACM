#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Edge
{
    int to , next , w;
}edge[20005];

int head[1005] , h[1005] , c[1005] , cnt , n , ml , md;
bool vis[1005];
void addEdge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool spfa()
{
    memset( h , 0x7f , sizeof(h));
    memset( vis , 0 , sizeof(vis));
    memset( c , 0 , sizeof(c));
    vis[1] = 1;
    c[1]++;
    h[1] = 0;
    queue<int>q;
    q.push(1);
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
                    q.push( v );
                }
                if( ++c[v] > n)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    while(~scanf("%d%d%d",&n,&ml,&md))
    {
        cnt = 1;
        memset( head , -1 , sizeof(head));
        int a , b, d;
        for( int i = 0 ; i < ml ; i++ )
        {
            scanf("%d%d%d",&a,&b,&d);
            addEdge( a , b , d );
        }
        for( int j = 0 ; j < md ; j++ )
        {
            scanf("%d%d%d",&a,&b,&d);
            addEdge( b , a , -d );
        }
        if(!spfa())
            printf("-1\n");
        else if( h[n] == 2139062143 )
            printf("-2\n");
        else
            printf("%d\n",h[n]);
    }
    return 0;
}
