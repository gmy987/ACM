∑#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1200

using namespace std;
int cost[MAXN],volume[MAXN];
int n,v;
int dp[MAXN];

int main()
{
    int t;
    while(~scanf("%d",&t))
    {
        for( int i = 0  ; i < t ; i++ )
        {
            scanf("%d%d",&n,&v);
            for( int k = 0 ; k < n ; k++ )
                scanf("%d",&cost[k]);
            for( int k = 0 ;  k < n ; k++ )
                scanf("%d",&volume[k]);
            memset( dp , 0  , sizeof(dp));
            for( int i = 0 ; i < n ; i++  )
                for( int j = v ; j >= volume[i] ; j--  )
                    dp[j] = max( dp[j] , dp[j-volume[i]] + cost[i] );
            printf("%d\n",dp[v]);
        }
    }
    return 0;
}
