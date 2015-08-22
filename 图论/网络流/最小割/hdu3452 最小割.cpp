/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-04 09:53
*
* Filename: hdu3452.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 2000
#define maxm 10000
#define INF 0x7fffffff

using namespace std;
struct Edge{
    int to,from,next,cap;
}edge[maxm];
int dis[maxn],gap[maxn],cur[maxn],head[maxn],q[maxn],st[maxn],cnt,front,rear;
int n,S,T,u,v,w;
void addedge( int u , int v , int cap)
{
    edge[cnt].to = v;
    edge[cnt].from = u;
    edge[cnt].cap = cap;
    edge[cnt].next = head[u];
    head[u] = cnt++;

    edge[cnt].to = u;
    edge[cnt].from = v;
    edge[cnt].cap = 0;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
int mark[maxn];
void bfs( int t )
{
    memset(dis,0xff,sizeof(dis));
    memset(gap,0,sizeof(gap));
    dis[t] = 0;
    gap[0] = 1;
    front = rear = 0;
    q[rear++] = t;
    while(front!=rear)
    {
        int u = q[front++];
        for( int i = head[u]; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            if(~dis[v]) continue;
            dis[v] = dis[u] + 1;
            q[rear++] = v;
            gap[dis[v]]++;
        }
    }
}
int isap( int s, int t , int n )
{
    bfs(t);
    memcpy(cur,head,sizeof(head));
    int flow=0,i,u=s,top=0;
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
        if( u != t && gap[dis[u]-1] == 0 ) break;
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
            if(u!=s) u = edge[st[--top]].from;
        }
    }
    return flow;
}

int main()
{
    while(~scanf("%d%d",&n,&S))
    {
        if( n == 0 && S == 0 ) break;
        memset(head,0xff,sizeof(head));
        cnt = 0;
        T = 1500;
        memset(mark,0,sizeof(mark));
        for( int i = 1 ; i < n ; i++ )
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
            mark[u]++;
            mark[v]++;
        }
        for( int i = 1 ; i <= n ; i++ )
            if(mark[i]==1&&i!=S)
                addedge(i,T,INF);
        printf("%d\n",isap(S,T,T+1));
    }
    return 0;
}
