#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define INF 2139062143
#define MAXN 500
#define MAXM 3005

using namespace std;
int head[MAXN],dis[MAXN],vis[MAXN];
int cnt,n,m,a,b,x;
struct Edge{
    int to,w,next;
}edge[MAXM];
void addedge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}
int s,t;
void spfa()
{
    memset(dis,0x7f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    vis[s] = 1;
    dis[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( dis[v] > dis[u] + w )
            {
                dis[v] = dis[u]+w;
                if( !vis[v] )
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(head,0xff,sizeof(head));
        cnt = 0;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&x);
            addedge(a,b,x);
            addedge(b,a,x);
        }
        scanf("%d%d",&s,&t);
        spfa();
        if(dis[t]==INF) printf("-1\n");
        else printf("%d\n",dis[t]);
    }
    return 0;
}

