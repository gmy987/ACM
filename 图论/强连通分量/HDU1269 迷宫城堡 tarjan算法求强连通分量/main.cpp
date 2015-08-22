#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#define MAXM 100005
#define MAXN 10004
using namespace std;
struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],vis[MAXN],ans,low[MAXN],dfn[MAXN],n,m,deep,cnt,a,b;
void addEdge( int u , int v )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
stack<int> s;
void tarjan( int x )
{
    int i;
    s.push(x);
    low[x] = dfn[x] = ++deep;
    vis[x] = 1;
    for( i = head[x] ; ~i  ; i = edge[i].next )
    {
        int v = edge[i].to;
        if( dfn[v] == -1 )
        {
            tarjan(v);
            if( low[x] > low[v] )
                low[x] = low[v];
        }
        else if( vis[v] && low[x] > dfn[v] )
            low[x] = dfn[v];
    }
    if( low[x] == dfn[x] )
    {
        ans++;
        while(!s.empty())
        {
            i = s.top();
            s.pop();
            vis[i] = 0;
            if( x == i )
                break;
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m)&&(n+m))
    {
        memset( head , 0xff , sizeof(head));
        memset( low , 0 , sizeof(low));
        memset( dfn , 0xff , sizeof(dfn));
        memset( vis , 0 , sizeof(vis));
        cnt = 0 , deep = 0,ans = 0;
        int i;
        for( i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&a,&b);
            addEdge( a , b );
        }
        for ( i = 1 ; i <= n ; i++ )
            if( dfn[i] == -1 )
                tarjan(i);
        if( ans == 1 )
            printf("Yes\n");
        else
            printf("No\n");
    }
}

