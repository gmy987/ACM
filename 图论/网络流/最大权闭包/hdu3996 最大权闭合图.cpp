/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-03 19:42
*
* Filename: hdu3996.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 5000
#define maxm 9000000
#define INF 13216546513113211ll 

using namespace std;
struct Edge{
    int to,from,next;
    long long cap;
}edge[maxm];
int head[maxn],cur[maxn],dis[maxn],q[maxn],st[maxn],gap[maxn];
int front,rear,n,cas,cnt;
int S,T;
void addedge( int u , int v , long long cap )
{
    edge[cnt].to = v;
    edge[cnt].from = u;
    edge[cnt].cap = cap;
    edge[cnt].next = head[u];
    head[u] = cnt++;

    edge[cnt].to = u;
    edge[cnt].from = v;
    edge[cnt].cap = 0LL;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
int c,d,e;
long long a,b;
int num;
void bfs( int t )
{
    memset(dis,0xff,sizeof(dis));
    memset(gap,0,sizeof(gap));
    dis[t] = 0;
    gap[0] = 1;
    front = rear = 0;
    q[rear++] =t;
    while(front!=rear)
    {
        int u = q[front++];
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            if(~dis[v]) continue;
            dis[v] = dis[u] + 1;
            q[rear++] = v;
            gap[dis[v]]++;
        }
    }
}
long long isap( int s ,int t, int n )
{
    bfs(t);
    memcpy( cur , head , sizeof(head) );
    int i,top = 0,u = s;
    long long flow = 0LL;
    while(dis[s]<n)
    {
        if( u == t )
        {
            long long f = INF;
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
        if( u != t && gap[dis[u]-1]==0 ) break;
        for( i = cur[u] ; ~i ; i = edge[i].next )
            if( edge[i].cap && dis[u] == dis[edge[i].to]+1 ) break;
        if(~i)
        {
            cur[u] = i;
            st[top++] = i;
            u = edge[i].to;
        }
        else{
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

int main()
{
    scanf("%d",&cas);
    for( int tt = 1 ; tt <= cas ; tt++ )
    {
        memset(head,0xff,sizeof(head));
        cnt = 0;
        printf("Case #%d: ",tt);
        scanf("%d",&n);
        S = 0;
        T = 3000;
        long long sum = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d",&num);
            for( int k = 1 ; k <= num ; k++ )
            {
                scanf("%lld%lld%d",&a,&b,&c);
                if( b - a < 0 ) addedge(26*i+k,T,a-b);
                else if( b - a > 0 )
                {
                    sum += (b-a);
                    addedge(S,26*i+k,b-a);
                }
                for( int j = 0 ; j < c ; j++ )
                {
                    scanf("%d%d",&d,&e);
                    addedge((d-1)*26+e,i*26+k,INF);
                }
            }
        }
        printf("%I64d\n",sum-isap(S,T,T+1));
    }
    return 0;
}
