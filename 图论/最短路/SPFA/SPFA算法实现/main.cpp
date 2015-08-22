#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge{
    int to,w,next;
}edge[maxn];

addEdge(int u , int v , int w)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}
int vis[maxn],h[maxn];
void spfa( int t )//t为源点
{
    memset(vis,0,sizeof(vis));
    memset(h,0x7f,sizeof(h));
    queue<int> q;
    h[t] = 0;
    q.push(t);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if ( h[v] > h[u] + w )
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
