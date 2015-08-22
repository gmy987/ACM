#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 500005

using namespace std;
int dp[MAXN];
int a[MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for( int i = 0 ; i < n ; i++ )
        {
            dp[i] = 1;
            scanf("%d",&a[i]);
        }
        for( int i = 1 ; i < n ; i++ )
        {
            for( int j = 0 ; j < i ; j++ )
                if( a[i] > a[j] )
                    dp[i] = max( dp[i] , dp[j]+1 );
        }
        int ans = dp[0];
        for( int i = 0 ; i < n ; i++ )
            ans = max( ans , dp[i] );
        printf("%d\n",ans);
    }
    return 0;
}
