#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int n,l;
int dp[500];
int t[40],damage[40];

int main()
{
    while(~scanf("%d%d",&n,&l))
    {
        memset( dp , 0 , sizeof(dp) );
        for( int i = 0 ; i < n ; i++ )
            scanf("%d%d",&t[i],&damage[i]);
        for( int i = 0  ;i < n ; i++ )
            for( int j = t[i] ; j<=t[i]+l ; j++ )
                dp[j] = max( dp[j] , dp[j-t[i]] + (j-t[i])*damage[i] );
        int i = 0;
        while(true)
        {
            if( dp[i++] >= l )
                break;
        }
        printf("%d\n",i-1);
    }
    return 0;
}
