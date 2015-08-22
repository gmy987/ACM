#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAXN 150
/*
 最小点覆盖
 用最少的点覆盖所有的边
 最小点覆盖＝最大匹配
 */

using namespace std;
vector<int> vect[MAXN];
int n,m,k;
int vis[MAXN],match[MAXN];
bool dfs( int x )
{
    int t;
    for( int i = 0 ; i < vect[x].size() ; i++ )
    {
        int v = vect[x][i];
        if(!vis[v])
        {
            t = match[v];
            match[v] = x;
            vis[v] = 1;
            if( t == -1 || dfs(t)) return true;
            match[v] = t;
        }
    }
    return false;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d%d",&m,&k);
        int a,b,c;
        for( int i = 0 ; i < k ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            if(!b||!c) continue;
            vect[b].push_back(c);
        }
        memset( match , 0xff , sizeof(match) );
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ans++;
        }
        printf("%d\n",ans);
        for( int i = 0 ; i < n+1 ; i++ )
            vect[i].clear();
    }
    return 0;
}
