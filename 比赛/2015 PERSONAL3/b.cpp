#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1005

using namespace std;
int n,k;
int map[MAXN][MAXN];
bool vis[MAXN];
int match[MAXN];
bool dfs( int x )
{
    int t;
    for( int i = 1 ; i <= n ; i++ )
    {
        if( map[x][i] && !vis[i] )
        {
            vis[i] = true;
            t = match[i];
            match[i] = x;
            if( t== -1 || dfs(t) )
                return true;
            match[i] = t;
        }
    }
    return false;
}
int find()
{
    int ans = 0;
    memset(match,0xff ,sizeof(match));
    for( int i = 1 ; i <= n ; i++ )
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i))
            ans++;
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        int a,b;
        for( int i = 0 ; i < k ; i++ )
        {
            scanf("%d%d",&a,&b);
            map[a][b] = 1;
        }
        printf("%d\n",find());
    }
    return 0;
}
