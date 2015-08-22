#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXM 800000
#define MAXN 300000
#define INF 0x7fffffff
using namespace std;
struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],dis[MAXN],cnt,m,n,s,t,vis[MAXN],pre[MAXN];
void addedge( int u , int v )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void bfs()
{
    memset( pre , 0xff , sizeof(pre));
    memset( vis , 0 , sizeof(vis));
    memset( dis , 0xff , sizeof(dis));
    dis[s] = 0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            if( dis[v] < 0 )
            {
                dis[v] = dis[u] + 1;
                pre[v] = u;
                q.push(v);
            }
        }
    }
}
int bfs2()
{
    for( int i = t ; i != s ; i = pre[i] )
        vis[i] = -1;
    vis[s] = -1;
    int sum = 1;
    while(true)
    {
        int ans = -1 , maxdis = -1;
        queue<int>q;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for( int i = head[u] ; ~i ; i = edge[i].next )
            {
                int v = edge[i].to;
                if( vis[v] == -1 && dis[v] > maxdis )
                {
                    ans = v;
                    maxdis = dis[v];
                }
                else if( vis[v] == 0)
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        sum++;
        if( ans == t )
            return sum;
        s = ans;
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int i , j , a , b ;
        memset( head , 0xff , sizeof(head));
        cnt = 0;
        for( i = 1 ; i <= m ; i++ )
        {
            scanf("%d%d",&a,&b);
            addedge( a , b );
        }
        scanf("%d%d",&s,&t);
        bfs();
        if( dis[t] == -1 )
            printf("%d\n",n);
        else
            printf("%d\n",bfs2());
    }
}
