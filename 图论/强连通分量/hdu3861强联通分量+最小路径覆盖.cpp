#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAXN 5005
#define MAXM 100005

using namespace std;
struct Edge{
    int from,to,next;
}edge[MAXM];
int head[MAXN],dfn[MAXN],low[MAXN];
int mark[MAXN];
bool vis[MAXN];
int n,m,cnt,num,deep;
void addedge( int u , int v )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].from = u;
    head[u] = cnt++;
}
stack<int> st;
vector<int> board[MAXN];
void tarjan( int x )
{
    vis[x] = 1;
    st.push(x);
    dfn[x] = low[x] = ++deep;
    for( int i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[x] = min(low[x],low[v]);
        }
        else if(vis[v])
            low[x] = min(low[x],dfn[v]);
    }
    if( dfn[x] == low[x] )
    {
        num++;
        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            vis[u] = 0;
            mark[u] = num;
            if( u == x )
                break;
        }
    }
}
bool dfs( int x )
{
    for( int i = 0 ; i<board[x].size() ; i++ )
    {
        int v = board[x][i];
        if( !vis[v] )
        {
            vis[v] = true;
            int t = mark[v];
            mark[v] = x;
            if( t == -1 || dfs(t) )
                 return true;
            mark[v] = t;
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset( head , 0xff, sizeof(head) );
        memset( vis , 0 , sizeof(vis) );
        memset( dfn , 0 , sizeof(dfn) );
        memset( low , 0 , sizeof(low) );
        memset( mark , 0 , sizeof(mark) );
        cnt = 0,num = 0,deep = 0;
        int u,v;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        for( int i = 1 ; i <= n ; i++  )
            if(!dfn[i])
                tarjan(i);
        for( int i = 0 ; i <= num + 6 ; i++ )
            board[i].clear();
        for( int i = 0 ; i < cnt ; i++ )
        {
            int u = mark[edge[i].from] , v = mark[edge[i].to];
            if( u == v ) continue;
            board[u].push_back(v);
        }
        memset( mark , 0xff , sizeof(mark));
        int ans = 0;
        for( int i = 1 ; i <= num ; i++ )
        {
            memset( vis , 0 , sizeof(vis) );
            if(dfs(i))
                ans++;
        }
        printf("%d\n",num-ans);
    }
    return 0;
}
