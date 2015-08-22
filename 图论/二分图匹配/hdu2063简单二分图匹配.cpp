#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 600

using namespace std;
int k,m,n;
int map[MAXN][MAXN];
int vis[MAXN];
int match[MAXN];
bool dfs( int x )
{
    int t;
    for( int i = 1 ; i <= m ; i++ )
    {
        if( map[x][i] && !vis[i] )
        {
            vis[i] = true;
            t = match[i];
            match[i] = x;
            if( t == -1 || dfs(t) )
                return true;
            match[i] = t;
        }
    }
    return false;
}
int findans()
{
    int ans = 0;
    for( int i = 1 ; i <= n ; i++ )
    {
        memset(vis, 0 , sizeof(vis));
        if( dfs(i) )
            ans++;
    }
    return ans;
}

int main()
{
    while(~scanf("%d",&k)&&k)
    {
        scanf("%d%d",&n,&m);
        memset( map , 0 , sizeof(map) );
        memset( match , -1 , sizeof(match) );
        int a,b;
        while(k--)
        {
            scanf("%d%d",&a,&b);
            map[a][b] = 1;
        }
        printf("%d\n",findans());
    }
    return 0;
}
