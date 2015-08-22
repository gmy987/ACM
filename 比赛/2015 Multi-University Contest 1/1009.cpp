#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#define MAXN 20 
#define MAXM 100005

using namespace std;
int d[MAXM],p[MAXM][20],dfn[MAXM],dis[MAXM],low[MAXM];
vector<int> edge[MAXM],weight[MAXM];
set<int> s;
int u,v,w,n,q,op,x;
int cnt,sum;
void dfs(int u,int pre)
{
    dfn[++cnt] = u;
    low[u] = cnt;
    d[u] = d[pre]+1;
    //p[u][0] = pre;
    for( int i = 1 ; i < MAXN ; i++ ) p[u][i] = p[p[u][i-1]][i-1];
    for( int i = 0 ; i < edge[u].size() ; i++ )
    {
        int v = edge[u][i];
        if( v == pre ) continue;
        dis[v] = dis[u]+weight[u][i];
        p[v][0] = u; 
        dfs( v , u );
    }
}
int lca( int a , int b )
{
    if(d[a]>d[b]) a^=b,b^=a,a^=b;
    if(d[a]<d[b])
    {
        int del = d[b]-d[a];
        for( int i = 0 ; i < MAXN ; i++ )
            if( del&(1<<i)) b = p[b][i];
    }
    if( a!=b )
    {
        for( int i = MAXN-1 ; i >= 0 ; i-- )
            if( p[a][i] != p[b][i] )
                a = p[a][i] , b = p[b][i];
        a = p[a][0],b = p[b][0];
    }
    return a;
}
bool vis[MAXM];
int cal( int x )
{
    if(s.empty())
        return 0;
    int a,b;
    set<int>::iterator it = s.lower_bound(low[x]), itx = it;
    if( it == s.end() || it == s.begin())
    {
        it = s.begin();
        itx = s.end();
        itx--;
    }
    else itx--;
    return dis[x]-dis[lca(x,dfn[(*it)])]-dis[lca(x,dfn[(*itx)])]+dis[lca(dfn[(*it)],dfn[(*itx)])];
}


int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        scanf("%d%d",&n,&q);
        memset( vis , 0 , sizeof(vis) );
        memset( dfn , 0 , sizeof(dfn) );
        memset( low , 0 , sizeof(low) );
        memset( d , 0 , sizeof(d) );
        memset( dis , 0 , sizeof(dis) );
        for( int i = 0 ; i <= n ; i++ )
        {
            edge[i].clear();
            weight[i].clear();
        }
        s.clear();
        for( int i = 0 ; i < n-1 ; i++ )
        {
            scanf("%d%d%d",&u,&v,&w);
            edge[u].push_back(v);
            edge[v].push_back(u);
            weight[u].push_back(w);
            weight[v].push_back(w);
        }
        cnt = 0;
        p[1][0] = 1;
        d[1] = 1;
        dis[1] = 0;
        dfs(1,-1);
        sum = 0;
        printf("Case #%d:\n",cas++);
        for( int i = 0 ; i < q ; i++ )
        {
            scanf("%d%d",&op,&x);
            if( op == 1 )
            {
                if(s.size()==0)
                {
                    s.insert(low[x]);
                    vis[x] = 1;
                }
                else
                {
                    if(!vis[x])
                    {
                        vis[x] = 1;
                        int tmp = cal(x);
                        s.insert(low[x]);
                        sum += tmp;
                    }
                }
            }
            else
            {
                if(vis[x])
                {
                    vis[x] = 0;
                    s.erase(low[x]);
                    if(!s.empty())
                        sum-=cal(x);
                }
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
