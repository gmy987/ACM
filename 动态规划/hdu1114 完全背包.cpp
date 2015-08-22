#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int p,w;
    int n;
    int value[505],weight[505];
    int dp[10005];
    while(t--)
    {
        scanf("%d%d",&p,&w);
        w = w-p;
        scanf("%d",&n);
        for( int i = 0  ; i < n ; i++ )
            scanf("%d%d",&value[i],&weight[i]);
        memset( dp , 0x7f  , sizeof(dp) );
        dp[0] = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = weight[i] ; j <= w ; j++ )
                dp[j] = min(dp[j],dp[j-weight[i]]+value[i] );
        if( dp[w] == 2139062143 )
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
    }
    return 0;
}
