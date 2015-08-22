#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
struct Edge{
    int to,next,w;
}edge[1000005];

int head[1005],h[1005],n,m,cnt;
bool vis[1005];
void addEdge ( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

struct cmp{
    bool operator()(int a,int b)
    {
        return h[a] < h[b];
    }
};

void Dijkstra()
{
    memset(h,0,sizeof(h));
    memset(vis,0,sizeof(vis));
    h[1] = 0x7fffffff;
    priority_queue<int,vector<int>,cmp> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        vis[u] = 1;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to,w = edge[i].w;
            if( h[v] < min( w , h[u]))
            {
                h[v] = min( w , h[u] );
                q.push(v);
            }
        }
    }
}
/*
void spfa()
{
    memset(h,0,sizeof(h));
    memset(vis,0,sizeof(vis));
    h[1] = 1<<29;
    queue<int> q;
    vis[1] = 1;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        //if(vis[u]) continue;
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] < min( h[u] , w ))
            {
                h[v] = min(h[u],w);
                if( !vis[v] )
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}*/
int main()
{
    int t,a,b,c,num = 1;
    scanf("%d",&t);
    while(t--)
    {
        memset( head , -1 , sizeof(head));
        cnt = 1;
        scanf("%d%d",&n,&m);
        if( n == 1 )
        {
            printf("Scenario #%d:\n",num++);
            printf("0\n\n");
            continue;
        }
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        Dijkstra();
        printf("Scenario #%d:\n",num++);
        printf("%d\n\n",h[n]);
    }
    return 0;
}
