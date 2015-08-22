/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-04 19:17
*
* Filename: hdu3987.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 5000
#define maxm 400005
#define ll long long
#define INF 0x7fffffff

using namespace std;
struct Edge{
    int to,from,next;
    ll cap;
}edge[maxm];
int head[maxn],dis[maxn],gap[maxn],cur[maxn],q[maxn],st[maxn];
int cnt,n,m,u,v,c,d;
int t,front,rear;
void addedge( int u , int v, int cap )
{
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].cap = cap;
    head[u] = cnt++;

    edge[cnt].from = v;
    edge[cnt].to = u;
    edge[cnt].next = head[v];
    edge[cnt].cap = 0;
    head[v] = cnt++;
}
void bfs( int t )
{
    memset(dis,0xff,sizeof(dis));
    memset(gap,0,sizeof(gap));
    front = rear = 0;
    q[rear++] = t;
    dis[t] = 0;
    gap[0] = 1;
    while( front != rear )
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
ll isap( int s , int t, int n )
{
    int i,u=s,top=0;
    memcpy( cur,  head, sizeof(head));
    bfs(t);
    ll flow = 0;
    while(dis[s]<n)
    {
        if( u == t )
        {
            ll f = INF;
            int inser = n;
            for( i = 0 ; i < top ; i++ )
            {
                if( f > edge[st[i]].cap )
                {
                    f = edge[st[i]].cap;
                    inser = i;
                }
            }
            for( i = 0 ; i < top ; i ++ )
            {
                edge[st[i]].cap -= f;
                edge[st[i]^1].cap += f;
            }
            flow += f;
            top = inser;
            u = edge[st[top]].from;
            continue;
        }
        if( u != t && gap[dis[u]-1]==0 ) break;
        for( i = cur[u] ; ~i ; i = edge[i].next )
            if(edge[i].cap && dis[u] == dis[edge[i].to]+1) break;
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
            if( u != s ) u = edge[st[--top]].from;
        }
    }
    return flow;
}
int main()
{
    int t;
    scanf("%d",&t);
    for( int tt=1 ; tt<=t ; tt++ )
    {
        printf("Case %d: ",tt);
        scanf("%d%d",&n,&m);
        memset(head,0xff,sizeof(head));
        cnt = 0;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d%d",&u,&v,&c,&d);
            if(!d) addedge(u,v,c);
            else{
                addedge(u,v,c);
                addedge(v,u,c);
            }
        }
        isap(0,n-1,n);
        for( int i = 0 ; i < cnt ; i+=2 )
        {
            if(!edge[i].cap)
            {
                edge[i].cap = 1LL;
                edge[i^1].cap = 0LL;
            }
            else
            {
                edge[i].cap = INF;
                edge[i^1].cap = 0LL;
            }
        }

        printf("%lld\n",isap(0,n-1,n));
    }
    return 0;
}
