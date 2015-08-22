#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 125

using namespace std;
int dp[MAXN][MAXN];

int main()
{
    int n;
    for( int i = 1 ; i <= 123 ; i++ ) dp[i][1] = dp[1][i] = 1;
    for( int i = 1 ; i<= 123 ; i++ )
    {
        for( int j = 1 ; j <123  ; j++ )
        {
            if( i == j )
                dp[i][j] = dp[i][j-1] + 1;
            else if( i > j ) dp[i][j] = dp[i][j-1]+dp[i-j][j]; 
            else dp[i][j] = dp[i][i];
        }
    }
        
    while(~scanf("%d",&n))
    {
        printf("%d\n",dp[n][n]);
    }
    return 0;
}
