#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 13

using namespace std;
int n;
int dp[MAXN][MAXN];
int mul[MAXN];
int c[MAXN][MAXN];

int main()
{
    int t;
    long long ans[12];
    memset( ans , 0 , sizeof(ans) );
    memset( dp , 0 , sizeof(dp) );
    mul[0] = 1; 
    for( int i = 1 ; i <= 11 ; i++ )
        mul[i] = i*mul[i-1];
    for( int i = 1 ; i <= 11 ; i++ )
    {
        for( int j = 1 ; j <= i; j++  )
        {
            c[i][j] = 1;
            for( int k = i,l=1 ; l<=j ; k--,l++ )
                c[i][j]*=k;
            c[i][j]/=mul[j];
        }
    }
    for( int i = 0 ; i <= 11 ; i++ )
        dp[i][i] = 1;
    for( int i = 1 ; i <= 11 ; i++ )
        for( int j = 1 ; j <= i-1 ; j++ )
            dp[i][j] = j*dp[i-1][j]+dp[i-1][j-1];
    for( int i = 1 ; i <= 11 ; i++ )
        for( int j = 1 ; j <= i ; j++ )
            for( int k = 1 ; k <= j ; k++)
                ans[i]+=((long long)dp[j][k]*mul[k])*c[i][j];
    int a;
    scanf("%d",&t);
    for( int m = 1 ; m <= t ; m++ )
    {
        scanf("%d",&a);
        printf("%d %d %lld\n",m,a,ans[a]);
    }
    return 0;
}
