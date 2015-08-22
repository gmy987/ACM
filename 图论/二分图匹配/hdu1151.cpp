#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAXN 240

using namespace std;
int n,m;
vector<int> edge[MAXN];
int match[MAXN],vis[MAXN];
bool dfs( int x )
{
    int t;
    for( int i = 0 ; i < edge[x].size() ; i++ )
    {
        int v = edge[x][i];
        if(!vis[v])
        {
            t = match[v];
            match[v] = x;
            vis[v] = 1;
            if( t == -1 || dfs(t) ) return true;
            match[v] = t;
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
        int u,v;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        memset(match ,0xff,sizeof(match));
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
                ans++;
        }
        printf("%d\n",n-ans);
        for( int i = 0 ; i<n+5 ; i++ )
            edge[i].clear();
    }
    return 0;
}
