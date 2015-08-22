#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXM 200005

using namespace std;
int a[MAXM];
int b[MAXM];
int dp[MAXM];
int n,m;

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for( int i = 0 ; i < n ; i++ )
        {
            memset(dp,0,sizeof(dp));
            for( int j = 0 ; j < m ; j++ )
                scanf("%d",&a[j]);
            dp[0] = a[0];
            dp[1] = a[1];
            for( int k = 2 ; k < m ; k++ )
                dp[k] = max(dp[k-2]+a[k],dp[k-1]);
            b[i] = dp[m-1];
        }
        memset( dp , 0 , sizeof(dp) );
        dp[0] = b[0];
        dp[1] = b[1];
        for( int i = 2 ; i < n ; i++ )
            dp[i] = max(dp[i-2]+b[i],dp[i-1]);
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
