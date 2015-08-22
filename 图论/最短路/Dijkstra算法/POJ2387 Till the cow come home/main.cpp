#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 1<<29
using namespace std;
struct Edge{
    int to,next,w;
}edge[400000];
int t,n,k,head[400000],h[400000];
bool vis[400000];
struct cmp
{
    bool operator()(const int a , const int b)
    {
        return h[a]>h[b];
    }
};
void Dijkstra()//dijkstra的heap优化
{
    priority_queue<int,vector<int>,cmp>q;
    memset(h,0x7f,sizeof(h));
    h[1] = 0;
    memset(vis,0,sizeof(vis));
    q.push(1);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if(!vis[v] && h[v] > h[u] + w)
            {
                h[v] = h[u]+w;
                q.push(v);
            }
        }
    }
}

void addEdge( int u , int v , int w)
{
    edge[k].to = v;
    edge[k].w = w;
    edge[k].next = head[u];
    head[u] = k++;
}
int main()
{
    while(~scanf("%d%d",&t,&n))
    {
        int a,b,c;
        memset(head,-1,sizeof(head));
        memset(edge , 0 , sizeof(edge));
        k = 1;
        for( int i = 1 ; i <= t ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            //构造无向图
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        Dijkstra();
        printf("%d\n",h[n]);
    }
}
