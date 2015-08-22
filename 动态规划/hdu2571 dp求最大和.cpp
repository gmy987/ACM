#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;
int n,m;
int dp[25][1005];
int a[25][1005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
            {
                scanf("%d",&a[i][j] );
                dp[i][j] = -0x7fffffff;
            }
        dp[1][1] = a[1][1];
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
            {
                if( i > 1 ) dp[i][j] = max( dp[i-1][j]+a[i][j] , dp[i][j] );
                if( j > 1 ) dp[i][j] = max( dp[i][j-1]+a[i][j] , dp[i][j] );
                for( int k = 1 ; k < j ; k++ )
                    if( j%k==0 )
                        dp[i][j] = max( dp[i][k]+a[i][j] , dp[i][j] );
            }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
