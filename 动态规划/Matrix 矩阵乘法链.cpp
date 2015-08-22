#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN INF

using namespace std;
int dp[MAXN][MAXN];
void Matrix()
{
    for( int i = 1 ; i <= n ; i++ )
        dp[i][i] = 0;
    for( int r = 2 ; r <= n ; r++ ){
        for( int i = 1 ; i <= n-i+1 ; i++ ){
            int j = i+r-1;
            dp[i][j] = dp[i+1][j] + mult[i-1]*mult[i]*mult[j];
            for( int k = i+1 ; k < j ; k++ ){
                dp[i][j] = min( dp[i][j] , dp[i][k]+dp[k+1][j]+mult[i-1]*mult[k]*mult[j] );
            }
        }
    }
}

int main()
{
}
