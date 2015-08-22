/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-04 20:01
*
* Filename: hdu2435.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxm 30000
#define INF 0x7fffffff
#define maxn 300

using namespace std;

struct Edge{
    int to,next,from,cap;
}edge[maxm];
int n,m;
int u,v,c;
int t;
int dis[maxn],cur[maxn],head[maxn],gap[maxn],q[maxn],st[maxn],front,rear,cnt;
void addedge( int u , int v, int cap )
{
    edge[cnt].to = v;
    edge[cnt].from = u;
    edge[cnt].next = head[u];
    edge[cnt].cap = cap;
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].from = v;
    edge[cnt].cap = 0;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
void bfs( int t )
{
    memset(dis,0xff,sizeof(dis));
    memset(gap,0,sizeof(gap));
    dis[t] = 0;
    gap[0] = 1;
    front = rear = 0;
    q[rear++] = t;
    while( front != rear )
    {
        int u = q[front++];
       for( int i = head[u] ; ~i ; i = edge[i].next ) 
       {
           int v = edge[i].to;
           if(~dis[v]) continue;
           dis[v] = dis[u] + 1;
           gap[dis[v]] ++;
           q[rear++] = v;
       }
    }
}
int isap( int s , int t, int n )
{
    bfs(t);
    memcpy(cur,head,sizeof(head));
    int flow = 0 , i , u = s , top = 0;
    while(dis[s]<n)
    {
        if( u == t )
        {
            int f = INF;
            int inser = n;
            for( i = 0 ; i < top ; i++ )
            {
                if( f > edge[st[i]].cap )
                {
                    f = edge[st[i]].cap;
                    inser = i;
                }
            }
            for( i = 0 ; i < top ; i++ )
            {
                edge[st[i]].cap -= f;
                edge[st[i]^1].cap += f;
            }
            flow += f;
            top = inser;
            u = edge[st[top]].from;
            continue;
        }
        if( u != t && gap[dis[u]-1]== 0 ) break;
        for( i = cur[u] ; ~i ; i = edge[i].next )
            if( edge[i].cap && dis[u] == dis[edge[i].to]+1 ) break;
        if(~i)
        {
            cur[u] = i;
            st[top++] = i;
            u = edge[i].to;
        }
        else
        {
            int f = n;
            for( i = head[u] ; ~i ; i = edge[i].next )
            {
                if(!edge[i].cap) continue;
                if( f > dis[edge[i].to])
                {
                    f = dis[edge[i].to];
                    cur[u] = i;
                }
            }
            --gap[dis[u]];
            ++gap[dis[u]=f+1];
            if( u != s ) u = edge[st[--top]].from;
        }
    }
    return flow;
}
int vis[maxn];
void find()
{
    front = rear = 0;
    q[rear++] = 1;
    vis[1] = 1;
    while(front!=rear)
    {
        int u = q[front++];
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            if(edge[i].cap&&!vis[v])
            {
                vis[v] = 1;
                q[rear++] = v;
            }
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(head,0xff,sizeof(head));
        cnt = 0;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
        }
        memset(vis,0,sizeof(vis));
        int ans = isap(1,n,n);
        int tmp = 0;
        find();
        Edge e[maxm];
        memcpy(e,edge,sizeof(edge));
        int tmp1,tmp2;
        for( int i = 2; i <= n-1 ; i++  )
        {
            if(vis[i])
            {
                for( int j = 2 ; j <= n-1 ; j++ )
                {
                    if(!vis[j])
                    {
                        tmp1 = head[i] , tmp2 = head[j];
                        addedge(i,j,INF);
                        tmp = max(tmp,isap(1,n,n+1));
                        cnt-=2;
                        head[i] = tmp1,head[j] = tmp2;
                        memcpy(edge,e,sizeof(e));
                    }
                }
            }
        }
        printf("%d\n",ans+tmp);
    }
    return 0;
} 
