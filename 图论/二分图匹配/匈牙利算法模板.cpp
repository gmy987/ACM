#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN n
#define MAXM m

using namespace std;
int match[MAXN];
int map[MAXN][MAXM];
bool vis[MAXM];
bool dfs( int x )
{
    int t;
    for( int i = 0 ; i < m ; i++ )
    {
        if( map[x][i] && !vis[i] )
        {
            vis[i] = true;
            t = match[i];
            match[i] = x;
            if( t==-1 || dfs(t) )
                return true;
            match[i] = t;
        }
    }
    return false;
}
int find()
{
    int ans=0;
    memset( match , -1 , sizeof(match) );
    for( int i = 0  ; i < n ; i++ )
    {
        memset( vis , 0 , sizeof(vis) );
        if( dfs(i) )
            ans++;
    }
    return ans;
}


int main()
{
    return 0;
}
