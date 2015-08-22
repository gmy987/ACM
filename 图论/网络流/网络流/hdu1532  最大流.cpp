#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 500
#define MAXM 500
#define INF 0X7FFFFFFF

using namespace std;
int n,m;
int head[MAXN];
struct Edge{
    int to,next,cap,from;
}edge[MAXM];
int cnt;
void addedge( int u , int v , int cap )
{
    edge[cnt].to  = v;
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
int q[MAXN],dis[MAXN],cur[MAXN],gap[MAXN],front,rear;

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
            if(~dis[v] || edge[i].cap ) continue;
            q[rear++] = v;
            dis[v] = dis[u] + 1;
            gap[dis[v]]++;
        }
    }
}
int stack[MAXN];
int isap(int s,int t,int n)
{
    bfs(s,t);
    memcpy(cur,head,sizeof(head));
    int top = 0,u = s,flow = 0,i;
    while(dis[s]<n)
    {
        if(u==t)
        {
            int f = INF;
            int inser = n;
            for( i = 0 ; i < top ; i++ )
            {
                if( f > edge[stack[i]].cap )
                {
                    f = edge[stack[i]].cap;
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
        if( u != t && gap[dis[u]-1] == 0 ) break;
        for( i = cur[u] ; ~i ; i = edge[i].next )
            if(edge[i].cap&&dis[u]==dis[edge[i].to]+1) break;
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
                if(!edge[i].cap ) continue;
                if( f > dis[edge[i].to] )
                {
                    f = dis[edge[i].to];
                    cur[u] = i;
                }
            }
            --gap[dis[u]];
            ++gap[dis[u]=f+1];
            if(u!=s) u = edge[stack[--top]].from;
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
        int u,v,c;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
        }
        printf("%d\n",isap(1,m,m));
    }
    return 0;
}
