#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x7fffffff
#define MAXN 150

using namespace std;
int vis[MAXN] , map[MAXN][MAXN] , low[MAXN];
int n;

int prim()
{
    int i , j , min , pos , result = 0;
    memset( vis , 0 , sizeof(vis));
    vis[1] = 1 , pos = 1;
    for( i = 1 ; i <= n ; i++ )
        if( i != pos )
            low[i] = map[pos][i];
    for( i = 1 ; i < n ; i++ )
    {
        min = INF;
        for( j = 1 ; j <= n ; j++ )
        {
            if(!vis[j] && min > low[j])
            {
                min = low[j];
                pos = j;
            }
        }
        result += min;
        vis[pos] = 1;
        for( j = 1 ; j <= n ; j++ )
            if( !vis[j] && low[j] > map[pos][j])
            {
               low[j] = map[pos][j]; 
            }
    }
    return result;
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset( map , 0x7f , sizeof(map));
        int a;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= n ; j++ )
            {
                scanf("%d",&a);
                map[i][j] = a;
            }
        int ans = prim();
        printf("%d\n",ans);
    }
    return 0;
}
