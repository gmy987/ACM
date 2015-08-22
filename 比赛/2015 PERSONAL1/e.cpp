#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 12900


using namespace std;
int n,m;
int dp[MAXN];
int a[MAXN],b[MAXN];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( dp , 0 , sizeof(dp));
        for( int i = 0 ; i < n ; i++ )
            scanf("%d%d",&a[i],&b[i]);
        for( int i = 0 ; i < n ; i++ )
            for( int j = m ; j >= a[i] ; j-- )
            {
                dp[j] = max( dp[j] , dp[j-a[i]]+b[i] );
            }
        printf("%d\n",dp[m]);
    }
    return 0;
}
