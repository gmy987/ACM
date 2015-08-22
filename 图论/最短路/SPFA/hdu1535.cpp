#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAXN 2000005

using namespace std;

int dis1[MAXN],dis2[MAXN],head[MAXN];
bool vis[MAXN];
int p,q,t,cnt;
struct Edge{
    int to,next,w;
}edge[MAXN],e[MAXN];
int head2[MAXN];
void addedge( int u , int v , int w )
{
    e[cnt].to = u;
    e[cnt].w = w;
    e[cnt].next = head2[v];
    head2[v] = cnt;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void spfa()
{
    queue<int> q;
    q.push(1);
    memset(dis1,0x7f,sizeof(dis1));
    memset(vis,0,sizeof(vis));
    dis1[1] = 0;
    vis[1] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( dis1[v] > dis1[u] + w )
            {
                dis1[v] = dis1[u] + w;
                if( !vis[v] )
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}


void spfa2()
{
    queue<int> q;
    q.push(1);
    memset(dis2,0x7f,sizeof(dis2));
    memset(vis,0,sizeof(vis));
    dis2[1] = 0;
    vis[1] = 1;
    while(!q.empty())
    { 
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head2[u] ; ~i ; i = e[i].next )
        {
            int v = e[i].to , w = e[i].w;
            if( dis2[v] > dis2[u] + w )
            {
                dis2[v] = dis2[u] + w;
                if( !vis[v] )
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int a,b,c;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&p,&q);
        memset( head , 0xff , sizeof(head) );
        memset( head2 , 0xff , sizeof(head2) );
        cnt = 0;
        while(q--)
        {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
        }
        spfa();
        spfa2();
        int ans = 0;
        for( int i = 2 ; i <= p ; i++ )
            ans += dis1[i]+dis2[i];
        printf("%d\n",ans);
    }
    return 0;
}


