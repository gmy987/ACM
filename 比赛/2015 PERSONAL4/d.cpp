#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100025

using namespace std;
int n,m;
double dp[MAXN];
int path[MAXN];
int u,v;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if( n == 0 && m == 0 )
            break;
        memset( path , 0xff , sizeof(path) );
        memset( dp , 0 , sizeof(dp) );
        dp[n] = -1;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&u,&v);
            path[u] = v;
        }
        for( int i = n ; i >= 0 ; i-- )
        {
            if(path[i]!=-1)
                dp[i] = dp[path[i]];
            else
            {
                double tmp = 0;
                for( int k = 1 ; k <= 6 ; k++ )
                    tmp += dp[i+k];
                tmp/=6;
                dp[i] += tmp;
                dp[i] += 1;
            }
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
