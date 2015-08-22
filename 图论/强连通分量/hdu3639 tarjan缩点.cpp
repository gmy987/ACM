/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-08 12:57
*
* Filename: h.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#define maxm 35000
#define maxn 6000

using namespace std;
struct Edge{
    int to,from,next;
}edge[maxm];
int head[maxn],vis[maxn],dfn[maxn],low[maxn],cnt,ans,deep;
int in[maxn];
int mark[maxn];
int num[maxn];
int n,m,u,v;
void addedge( int u , int v )
{
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
stack<int> st;
vector<int> e[maxn],res[maxn],s[maxn];
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
            if( low[x] > low[v] ) low[x] = low[v];
        }
        else if(vis[v]&&low[x]>dfn[v])
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
            s[ans].push_back(i);
            num[ans]++;
            if( i == x ) break;
        }
    }
}
int tmp;
void dfs( int x )
{
    for( int i = 0 ; i < e[x].size() ; i++ )
    {
        int v = e[x][i];
        if(!vis[v])
        {
            tmp += num[v];
            vis[v] = 1;
            dfs(v);
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(head,0xff,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(dfn,0xff,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(mark,0,sizeof(mark));
        memset(num,0,sizeof(num));
        cnt = 0,deep=0,ans=0;
        memset(in,0,sizeof(in));
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        for( int i = 0 ; i < n+4 ; i++ )
            s[i].clear(),e[i].clear(),res[i].clear();
        for(int i = 0 ; i < n ; i++ )
            if(dfn[i]==-1) tarjan(i);
        for( int i = 0 ; i < cnt ; i++ )
        {
            int u = mark[edge[i].from],v = mark[edge[i].to];
            if(u==v) continue;
            e[v].push_back(u);
            in[u]++;
        }
        int mmaxn=0;
        for( int i = 1 ; i <= ans ; i++ )
        {
            if(in[i]==0)
            {
                memset(vis,0,sizeof(vis));
                vis[i] = 1;
                tmp = num[i]-1;
                dfs(i);
                res[tmp].push_back(i);
                mmaxn = max(mmaxn,tmp);
            }
        }
        printf("Case %d: %d\n",cas++,mmaxn);
        set<int> ss;
        for( int i = 0 ; i < res[mmaxn].size() ; i++ )
        {
            int j = res[mmaxn][i];
            for( int k = 0 ; k < s[j].size() ; k++  )
                ss.insert(s[j][k]);
        }
        set<int>::iterator it;
        for( it = ss.begin() ; it!=ss.end() ; it++ )
            if(it==ss.begin()) printf("%d",*it);
            else printf(" %d",*it);
        printf("\n");
    }
    return 0;
}

