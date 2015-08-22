#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define INF 0x7fffffff
#define MAXN 100

using namespace std;
int map[MAXN][MAXN],low[MAXN],vis[MAXN];
int n;

int prim()
{
    int i , j , pos , min , result = 0;
    memset( vis , 0 , sizeof(vis));
    vis[1] = 1 , pos = 1;
    for( i = 1 ; i <= n ; i++ )
        if( i!= pos )
            low[i] = map[pos][i];
    for( i = 1 ; i < n ; i++ )
    {
        min = INF;
        for( j = 1 ; j <= n ; j++ )
            if( !vis[j] && min > low[j])
            {
                min = low[j];
                pos = j;
            }

        result += min;
        vis[pos] = 1;
        for( j = 1 ; j <= n ; j++ )
            if( !vis[j] && low[j] > map[pos][j])
                low[j] = map[pos][j];
    }
    return result;
}

int main()
{
    memset( map , 0x7f  , sizeof(map));//map中值初始化为无穷大
    return 0;
}
