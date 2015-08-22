#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 360

using namespace std;
int n;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];

int main()
{
    scanf("%d",&n);
    memset( dp , 0 , sizeof(dp) );
    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < i+1 ; j++ )
            scanf("%d",&a[i][j]);
    for( int i = 0 ; i < n ; i++ )
        dp[n-1][i] = a[n-1][i];
    for( int i = n-1 ; i >= 0 ; i-- )
        for( int j = 0 ; j < i+1 ; j++ )
            dp[i][j] = a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
    printf("%d\n",dp[0][0]);
    return 0;
}
