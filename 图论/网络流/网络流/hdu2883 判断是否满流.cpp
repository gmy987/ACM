/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-03 16:46
*
* Filename: hdu2883.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 50000
#define maxm 5555555
#define INF 0x3f3f3f3f

using namespace std;
struct Edge
{
    int to,from,next,cap;
}edge[maxm];
int head[maxn],dis[maxn],gap[maxn],q[maxn],cur[maxn],st[maxn];
int cnt,front,n,m,a,b,c,rear;
void addedge( int u , int v, int cap )
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
int s[500],t[500];
int ttime[500];
void bfs( int s , int t )
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
            q[rear++] = v;
            gap[dis[v]]++;
        }
    }
}
int isap( int s ,int t , int n )
{
    bfs(s,t);
    memcpy(cur,head,sizeof(head));
    int flow = 0 , i , u = s , top = 0;
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
        if( u!=t && gap[dis[u]-1]==0 ) break;
        for( i = cur[u] ; ~i ; i = edge[i].next )
            if(edge[i].cap && dis[u] == dis[edge[i].to] + 1 ) break;
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
                if( !edge[i].cap ) continue;
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
        int num = 0,c = 0;
        int S = 0,T;
        int sum = 0;
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d%d%d%d",&s[i],&a,&t[i],&b);
            addedge(0,i,a*b);
            sum += a*b;
            ttime[num++] = s[i];
            ttime[num++] = t[i];
        }
        sort(ttime,ttime+cnt);
        for( int i = 1 ; i < cnt ; i++ )
            if(ttime[c]!=ttime[i]) ttime[++c] = ttime[i];
        T = n + c + 3;
        for( int i = 1 ; i <= c ; i++ )
            addedge( i + n , T , (ttime[i]-ttime[i-1])*m );
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= c ; j++ )
                if(s[i]<=ttime[j-1]&&t[i]>=ttime[j]) addedge(i,j+n,INF);
        puts(sum==isap(S,T,T+1)?"Yes":"No");
    }
    return 0;
}
