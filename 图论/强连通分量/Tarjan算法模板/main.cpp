#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

struct Edge
{
    int to,from,next;
}edge[MAXM];
int head[MAXN],vis[MAXN],dfn[MAXN],low[MAXN],cnt,ans,deep;
void addEdge( int u , int v )
{
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
stack<int> st;
void tarjan( int x )
{
    int i;
    dfn[x] = low[x] = ++deep;
    vis[x] = 1;
    st.push(x);
    for( i = head[x] ; ~i ; i = edge[i].next )
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
        while(!st.empty())//循环中取出的为一个强连通分量
        {
            i = st.top();
            st.pop();
            vis[i] = 0;
            if( i == x )
                break;
        }
    }
}
int main()
{
    memset(head,0xff,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(dfn,0xff,sizeof(dfn));
    memset(low,0,sizeof(low));
    cnt = 0 , deep = 0 ,ans = 0;
    for( i = 1 ; i <= n ; i++ )
        if(dfn[i] == -1)
            tarjan(i);
    //ans为强连通分量的个数；
}
