/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-03 15:00
*
* Filename: hdu3572.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x7fffffff 
#define maxm 600000 
#define maxn 2000

using namespace std;
struct Edge{
    int to,from,cap,next;
}edge[maxm];
int head[maxn],dis[maxn],q[maxn],cur[maxn],stack[maxn],gap[maxn],cnt,front,rear;
int n,m;
int s,t;
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
void bfs(int s, int t)
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
            dis[v] = dis[u] + 1;
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
    while(dis[s] < n)
    {
        if(u==t)
        {
            int f = INF;
            int inser = n;
            for( i = 0 ; i < top ; i++ )
            {
                if( f > edge[stack[i]].cap )
                {
                    f = edge[stack[i]].cap ;
                    inser = i;
                }
            }
            for( i = 0 ; i < top ; i++ )
            {
                edge[stack[i]].cap -= f;
                edge[stack[i]^1].cap += f;
            }
            flow += f;
            top = inser;
            u = edge[stack[top]].from;
            continue;
        }
        if(u!=t&&gap[dis[u]-1]==0) break;
        for( i = cur[u] ;~i ; i = edge[i].next )
            if(edge[i].cap!=0&&dis[u]==dis[edge[i].to]+1) break;
        if(~i)
        {
            cur[u] = i;
            stack[top++] = i;
            u = edge[i].to;
        }
        else
        {
            int f = n;
            for( i = head[u] ; ~i ; i = edge[i].next )
            {
                if(!edge[i].cap)
                    continue;
                if( f > dis[edge[i].to] )
                {
                    f = dis[edge[i].to];
                    cur[u] = i;
                }
            }
            --gap[dis[u]];
            ++gap[dis[u]=f+1];
            if(u!=s)
                u = edge[stack[--top]].from;
        }
    }
    return flow;
}

int main()
{
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--)
    {
        printf("Case %d: ",cas++);
        scanf("%d%d",&n,&m);
        cnt = 0;
        memset(head,0xff,sizeof(head));
        s = 0;
        int mm = 0;
        t = 600+n;
        int a,b,c;
        int mmax = -1;
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            mm+=a;
            addedge(s,i,a);
            mmax = max(mmax,c);
            for( int k = n + b ; k <= n + c ; k++ )
                addedge(i,k,1);
        }
        for( int i = n+1 ; i <= n + mmax ; i++ )
            addedge(i,t,m);
        puts(mm==isap(s,t,t)?"Yes":"No");
        puts("");
    }
    return 0;
}
