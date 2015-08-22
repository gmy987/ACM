#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct Edge
{
    int to,next,w;
}edge[6000];

int head[1000],h[1000],f,n,m,w,cnt,c[1000];
bool vis[1000];
void addEdge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
bool spfa( int i )
{
    memset( h , 0x7f , sizeof(h));
    memset( vis , 0 , sizeof(vis));
    memset( c , 0 , sizeof(c));
    h[i] = 0;
    vis[i] = 1;
    c[i]++;
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if( h[i] < 0 ) return true;
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] > h[u] + w )
            {
                h[v] = h[u] + w;
                if( !vis[v] )
                {
                    q.push(v);
                    vis[v] = 1;
                }
                if( ++c[v] > n )
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d",&f);
    while(f--)
    {
        cnt = 1;
        memset( head , -1 , sizeof(head));
        scanf("%d%d%d",&n,&m,&w);
        int a,b,c;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge( a , b , c);
            addEdge( b , a , c);
        }
        for( int i = 0 ; i < w ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge( a , b , -c );
        }
        bool flag = false;
        for( int i = 1 ; i <= n ; i++ )
        {
            if(spfa(i)){
                printf("YES\n");
                flag = true;
                break;
            }
        }
        if(!flag) printf("NO\n");
    }
}
