#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 2004

using namespace std;
int n,k;
int a[MAXN];
int dp[MAXN][MAXN];

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d",&a[i]);
        sort( a+1 , a+n+1 );
        memset( dp , 0 , sizeof(dp) );
        for( int i = 2 ; i <= n ; i++ )
            for( int j = 1 ; j <= k ; j++ )
            {
                if( i == j*2 )
                    dp[i][j] = dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]);
                else if( i > j*2 )
                {
                    dp[i][j] = min( dp[i-1][j] , dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
                }
            }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
