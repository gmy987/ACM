#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 105

using namespace std;
int n,m,k,s;
int a[MAXN],b[MAXN];
int dp[MAXN][MAXN];

int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&k,&s))
    {
        for( int i = 0 ; i < k ; i++ )
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        memset( dp , 0 , sizeof(dp) );
        for( int i = 0 ; i < k ; i++ )
        {
            for( int j = b[i] ; j <= m ; j++ )
            {
                for( int l = 1 ; l <= s ; l++ )
                {
                    dp[j][l] = max( dp[j][l] , dp[j-b[i]][l-1]+a[i] );
                }
            }
        }
        int i;
        int ans = -1;
        for( i = 1 ; i <= m ; i++ )
        {
            if( dp[i][s] >= n )
            {
                ans = i;
                break;
            }
        }
        if( ans != -1 )
            printf("%d\n",m-ans);
        else printf("%d\n",ans);
    }
    return 0;
}
