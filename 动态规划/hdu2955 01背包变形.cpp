#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int t;
double p;
int n,sum;
int value[120];
double dp[10010];
double w[120];

int main()
{
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%lf%d",&p,&n);
            sum = 0;
            memset( dp , 0 , sizeof(dp) );
            dp[0] = 1;
            for( int i = 0 ; i < n ; i++ )
            {
                scanf("%d%lf",&value[i],&w[i]);
                sum += value[i];
            }
            for( int i = 0; i < n ; i++ )
                for( int j = sum ; j >= value[i] ; j-- ){
                    dp[j] = max( dp[j] , (1.0-w[i])*dp[j-value[i]]);
                }
            p = 1.0-p;
            int i;
            for( i = sum ; i >= 0 ; i-- )
                if( dp[i] >= p )
                    break;
            printf("%d\n",i);
        }
    }
    return 0;
}
