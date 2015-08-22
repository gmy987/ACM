#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000

using namespace std;
int n,m;
int map[MAXN][MAXN] , in[MAXN];
int ans[MAXN];
int topsort()
{
    int cnt = 0;
    for( int i = 1 ; i <= n ; i++ )
        for( int j = 1 ; j <= n ; j++ )
        {
            if( in[j] == 0 )
            {
                in[j]--;
                ans[cnt++]=j;
                for( int l = 1 ; l <= n ; l++ )
                    if( map[j][l] )
                        in[l]--;
                break;
            }
            if( j > n )
                return 0; //存在环
        }
    return 1;
}

int main(){
    while(~scanf("%d%d",&n,&m))
    {
        memset( map , 0 , sizeof(map));
        memset( in , 0 , sizeof(in));
        int a,b;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&a,&b);
            if( !map[a][b] )
            {
                map[a][b] = 1;
                in[b]++;
            }
        }
        topsort();
        for( int i = 0 ; i < n ; i++ )
            if( i == 0 )
                printf("%d",ans[i]);
            else
                printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
