#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int t,n;
struct Edge{
    int to , next , w;
}edge[400000];
int head[200000],vis[200000],h[200000],k;

void addEdge( int u , int v , int w)
{
    edge[k].to = v;
    edge[k].w = w;
    edge[k].next = head[u];
    head[u] = k++;
}

void spfa()
{
    queue<int> q;
    h[1] = 0;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if( h[v] > h[u] + w )
            {
                h[v] = h[u] + w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&t,&n))
    {
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(h,0x7f,sizeof(h));
        memset(edge,0,sizeof(edge));
        k = 1;
        int a,b,c;
        for( int i = 0 ; i < t ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        spfa();
        printf("%d\n",h[n]);

    }
}
