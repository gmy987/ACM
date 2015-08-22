#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#define MAXN 10005
using namespace std;
int head[MAXN],dfn[MAXN],vis[MAXN],cnt,low[MAXN],mark[MAXN],ans;
struct Edge{
    int to,next;
}edge[MAXN];
void addedge( int u , int v )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
stack<int> st;
int deep;
void tarjan( int x )
{
    int i;
    dfn[x] = low[x] = ++deep;
    vis[x] = 1;
    st.push(x);
    for( int i = head[x] ; ~i ; i = edge[i].next )
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
        while(!st.empty())
        {
            i = st.top();
            st.pop();
            vis[i] = 0;
            mark[i] = ans;
            if( i == x )
                break;
        }
    }
}

int n,m;
int out[MAXN];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( head , 0xff , sizeof(head) );
        memset( vis , 0 , sizeof(vis));
        memset( dfn , 0xff,sizeof(dfn) );
        memset( low , 0xff , sizeof(low) );
        memset( out , 0 , sizeof(out) );
        memset( mark , 0 , sizeof(mark) );
        cnt = 0 , deep = 0 , ans = 0;
        int a,b;
        while( m-- )
        {
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        for( int i = 1 ; i <= n ; i++ )
            if(dfn[i] == -1) tarjan(i);
        for( int i = 1 ; i <= n ; i++ )
        {
            for( int k = head[i] ; ~k ; k = edge[k].next )
            {
                int v = edge[k].to;
                if(mark[i]!= mark[v])
                    out[mark[i]]++;
            }
        }
        int num = 0,tmp,result = 0;;
        for( int i = 1 ; i <= ans ; i++ )
            if(!out[i])
            {
                num++;
                tmp = i;
            }
        if( num == 1 )
        {
            for( int i = 1 ; i <= n ; i++ )
                if( mark[i] == tmp )
                    result++;
            printf("%d\n",result);
        }
        else printf("0\n");
    }
    return 0;
}

