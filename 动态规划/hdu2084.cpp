#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define MAXN 105

using namespace std;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < i+1 ; j++ )
                scanf("%d",&a[i][j]);
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = 0 ; j < i+1 ; j++ )
            {
                if( i == n-1 )
                    dp[i][j] = a[i][j];
                else
                {
                    dp[i][j] = max( dp[i+1][j]+a[i][j] , dp[i+1][j+1]+a[i][j] );
                }
            }
        printf("%d\n",dp[0][0]);
    }
    return 0;
}
