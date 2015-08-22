#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Edge
{
    int to,next ,w;
}edge[1000];

int head[300],h[300],m,n,cnt,c[300];
bool vis[300];

void addEdge( int u , int v , int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
bool spfa()
{
    memset( h , 0 , sizeof(h));
    memset( vis , 0 , sizeof( vis ));
    memset( c , 0 ,sizeof(c));
    queue<int> q;
    for ( int i = 0 ; i <= n ; i++ )
    {
        q.push(i);
        vis[i] = 1;
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        if ( c[u] > n ) return false;
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
                    c[v]++;
                }
            }
        }
    }
    return true;
}

int main()
{
    while(~scanf("%d",&n))
    {
        if(!n) break;
        scanf("%d",&m);
        int a,b,d;
        char c[3];
        cnt = 1;
        memset( head , -1 , sizeof(head));
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d %d",&a,&b);
            scanf("%s",c);
            scanf("%d",&d);

            if( c[0] == 'g' )
                addEdge( a + b , a - 1 , - d - 1);
            else
                addEdge( a - 1 , a + b , d - 1 );
        }
        if( spfa() )
            printf("lamentable kingdom\n");
        else
            printf("successful conspiracy\n");
    }
}
