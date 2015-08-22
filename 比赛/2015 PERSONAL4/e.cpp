#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 105

using namespace std;

int x[MAXN][MAXN],y[MAXN][MAXN];
int num[MAXN];
double dp[MAXN][MAXN];
double cal( int x1 , int y1 , int x2 , int y2 )
{
    double xx = x[x1][y1]-x[x2][y2];
    double yy = y[x1][y1]-y[x2][y2];
    return sqrt(xx*xx+yy*yy);
}
int n;

int main()
{
    while(~scanf("%d",&n))
    {
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&num[i]);
            for( int j = 1 ; j <= num[i] ; j++ )
                scanf("%d%d",&x[i][j],&y[i][j]);
        }
        double ans = 0x7fffffff;
        for( int i = 1 ; i <= num[1] ; i++ )
        {
            memset( dp , 0x7f ,sizeof(dp) );
            dp[1][i] = 0;
            for( int k = 1 ; k < n ; k++ )
                for( int l = 1 ; l <= num[k] ; l++ )
                    for( int m = 1 ; m <= num[k+1] ; m++ )
                        dp[k+1][m] = min( dp[k+1][m] , dp[k][l]+cal(k,l,k+1,m));
            for( int k = 1 ; k <= num[n] ; k++ )
                ans = min( ans , dp[n][k] + cal(1,i,n,k));
        }
        printf("%d\n",(int)(ans*100));
    }
    return 0;
}
