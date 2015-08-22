#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 205
#define MOD 10000
using namespace std;
int n,m;
int board[MAXN][MAXN];
int dp[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for( int i = 0 ; i<n ; i++ )
            for( int j = 0 ; j<m ; j++ )
                scanf("%d",&board[i][j]);
        memset( dp , 0 , sizeof(dp));
        dp[n-1][m-1] = 1;
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = m - 1 ; j >= 0 ; j-- )
                for( int ii = 0 ; ii <= board[i][j] ; ii++ )
                    for( int kk = 0 ; kk <= board[i][j]-ii ; kk++ )
                        if(!(ii==0&&kk==0)&&(ii+i<n)&&j+kk<m)
                            dp[i][j] = ( dp[i][j]%MOD+dp[i+ii][j+kk]%MOD)%MOD;
        printf("%d\n",dp[0][0]);
    }
    return 0;
}
