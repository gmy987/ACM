#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int n,m;
int w[1200];
int dp[1200];

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&w[i]);
        scanf("%d",&m);
        memset( dp , 0 , sizeof(dp) );
        sort( w , w+n);
        if( m >= 5 )
        {
            for( int i = 0 ; i < n-1 ; i++ )
                for( int j = m-5 ; j >= w[i] ; j-- )
                    dp[j] = max( dp[j] , dp[j-w[i]]+w[i]);
            printf("%d\n",m-dp[m-5]-w[n-1]);
        }
        else
            printf("%d\n",m);
    }
    return 0;
}
