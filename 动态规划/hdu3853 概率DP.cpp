/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-06 10:44
*
* Filename: hdu3853.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eps 1e-6
#define maxn 1500

using namespace std;
int n,m;
double dp[maxn][maxn];
double p1[maxn][maxn],p2[maxn][maxn],p3[maxn][maxn];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                scanf("%lf%lf%lf",&p1[i][j],&p2[i][j],&p3[i][j] );
        memset(dp,0,sizeof(dp));
        for( int i = n ; i >= 1 ; i-- )
            for( int j = m ; j >= 1 ; j-- )
            {
                if(i==n&&j==m) continue;
                if(1.00-p1[i][j]<eps) continue;
                dp[i][j] = (p2[i][j]*dp[i][j+1]+p3[i][j]*dp[i+1][j]+2)/(1-p1[i][j]);
            }
        printf("%.3f\n",dp[1][1]);
    }
    return 0;
}
