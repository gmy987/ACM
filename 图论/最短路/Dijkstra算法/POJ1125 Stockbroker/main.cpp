#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
struct Edge{
    int to,next,w;
}edge[10005];

int head[105],h[105],n,cnt;
bool vis[105];

void addEdge( int u , int v , int w)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}

struct cmp{
    bool operator() ( int a , int b )
    {
        return h[a] > h[b];
    }
};

void Dijkstra( int k )
{
    priority_queue<int,vector<int>,cmp> q;
    memset( h , 0x7f , sizeof(h));
    memset( vis , 0 , sizeof(vis));
    h[k] = 0;
    q.push(k);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        if( vis[u] ) continue;
        vis[u] = 1;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if( !vis[v] && h[v] > w + h[u] )
            {
                h[v] = w + h[u];
                q.push(v);
            }
        }
    }
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        cnt = 1;
        int a,b,m;
        memset( head , -1 ,sizeof(head));

        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&m);
            for( int j = 0 ; j < m ; j++ )
            {
                scanf("%d%d",&a,&b);
                addEdge( i , a , b );
            }
        }
        int M = 0,index = 1,ans = 0x7ffff,discon = 0;
        bool flag;
        for ( int i = 1 ; i <= n ; i++ )
        {
            Dijkstra( i );
            M = 0;
            flag = true;
            for ( int j = 1 ; j <= n ; j++ )
            {
                M = max( h[j] , M );
                if( M > 10000 )
                {
                    flag = false;
                    break;
                }
            }
            if( !flag )
                discon++;
            if( ans > M )
            {
                index = i;
                ans = M;
            }
        }
        if( discon == n ) printf("disjoint\n");
        else
            printf("%d %d\n",index,ans);
    }
    return 0;
}
