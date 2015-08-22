#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;
int n,m;
int value[3500],weight[3500];
int dp[13000];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( dp , 0 , sizeof(dp) );
        for( int i = 0 ;  i < n ; i++ )
            scanf("%d%d",&weight[i],&value[i]);
        for( int i = 0 ; i < n ; i++ )
            for( int j = m ; j >= weight[i] ;j-- )
                dp[j] = max( dp[j] , dp[j-weight[i]] + value[i] );
        printf("%d\n",dp[m]);
    }
    return 0;
}
    
