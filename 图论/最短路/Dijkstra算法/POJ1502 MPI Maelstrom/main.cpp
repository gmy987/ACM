#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
struct Edge
{
    int to,next,w;
}edge[10005];

int head[105],h[105],n,cnt;
bool vis[105];
char a;
void addEdge( int u , int v , int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
struct cmp{
    bool operator()( int a , int b )
    {
        return h[a] > h[b];
    }
};
void Dijkstra()
{
    memset( vis , 0 , sizeof( vis ));
    memset( h , 0x7f , sizeof( h ));
    h[1] = 0;
    priority_queue<int,vector<int>,cmp> q;
    q.push(1);
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
int main()
{
    while(~scanf("%d",&n))
    {
        cnt = 1;
        int num;
        memset( head , -1 , sizeof( head ));
        for( int i = 1 ; i < n ; i++ )
        {
            for( int j = 1 ; j < i + 1 ; j++ )
            {
                cin >> a;
                if( a != 'x')
                {
                    ungetwc( a , stdin );
                    scanf("%d",&num);
                    addEdge( i + 1 , j , num);
                    addEdge( j , i + 1 , num);
                }
            }
        }
        Dijkstra();
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
            ans = max( h[i] , ans );
        printf("%d\n",ans);
    }
}
