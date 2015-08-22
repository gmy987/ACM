/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-07 19:49
*
* Filename: hdu3917.cpp
* 
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 555
#define maxm 280000
#define INF 0x7fffffff

using namespace std;
int dis[maxn],gap[maxn],cur[maxn],q[maxn],st[maxn],cnt,head[maxn],front,rear;
int n,m;
int s,t;
struct Edge{
    int to,next,from,cap;
}edge[maxm];
void addedge( int u , int v , int cap )
{
    edge[cnt].to = v;
    edge[cnt].from = u;
    edge[cnt].next = head[u];
    edge[cnt].cap = cap;
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].from = v;
    edge[cnt].next = head[v];
    edge[cnt].cap = 0;
    head[v] = cnt++;
}
void bfs(int t)
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
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            if(~dis[v]) continue;
            dis[v] = dis[u] + 1;
            gap[dis[v]]++;
            q[rear++] = v;
        }
    }
}
int isap( int s , int t , int n )
{
    bfs(t);
    memcpy(cur,head,sizeof(head));
    int top=0,i,u=s,flow=0;
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
        if( u != t && gap[dis[u]-1] == 0 ) break;
        for( i = cur[u] ; ~i ; i = edge[i].next )
            if(edge[i].cap&&dis[u]==dis[edge[i].to]+1) break;
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
    while(~scanf("%d%d",&n,&m))
    {
        memset(head,0xff,sizeof(head));
        cnt = 0;
        int a,b;
        s = 0,t = n+1;
        int sum = 0;
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&a);
            if(a>0) addedge(s,i,a),sum+=a;
            else addedge(i,t,-a);
        }
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&a,&b);
            addedge(a,b,INF);
        }
        printf("%d\n",sum-isap(s,t,t));
    }
    return 0;
}
