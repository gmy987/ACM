/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-03 12:25
*
* Filename: hdu3549.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100
#define maxm 3000
#define INF 0x7fffffff
using namespace std;

struct Edge
{
    int from,to,cap,next;
}edge[maxm];
int cnt,head[maxn];
int n,m;
int q[maxn],dis[maxn],gap[maxn],cur[maxn],front,rear;
int st[maxn];
void addedge( int u , int v ,int c )
{
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].cap = c;
    head[u] = cnt++;
}
void bfs( int s , int t )
{
    memset(dis,0xff,sizeof(dis));
    memset(gap,0,sizeof(gap));
    gap[0] = 1;
    front = rear = 0;
    dis[t] = 0;
    q[rear++] = t;
    while(front!=rear)
    {
        int u = q[front++];
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            if(~dis[v]) continue;
            q[rear++] = v;
            dis[v] = dis[u]+1;
            gap[dis[v]]++;
        }
    }
}
int isap( int s , int t , int n )
{
    bfs(s,t);
    memcpy(cur,head,sizeof(head));
    int top = 0;
    int u = s;
    int flow = 0,i;
    while(dis[s]<n)
    {
        if(u==t)
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
        if(u!=t&&gap[dis[u]-1]==0) break;
        for( i = cur[u] ; ~i ; i = edge[i].next )
            if(edge[i].cap!=0&&dis[u]==dis[edge[i].to]+1) break;
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
                if( f > dis[edge[i].to] )
                {
                    f = dis[edge[i].to];
                    cur[u] = i;
                }
            }
            --gap[dis[u]];
            ++gap[dis[u]=f+1];
            if(u!=s)
                u = edge[st[--top]].from; 
        }
    }
    return flow;
}

int main()
{
    int t;
    scanf("%d",&t);
    int cas = 1;
    while(t--)
    {
        printf("Case %d: ",cas++);
        scanf("%d%d",&n,&m);
        memset(head,0xff,sizeof(head));
        cnt = 0;
        int u,v,c;
        for( int i = 0  ; i < m ; i++ )
        {
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
            addedge(v,u,0);
        }
        printf("%d\n",isap(1,n,n));
    }
    return 0;
}
