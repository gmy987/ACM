#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;
int dp[3000005];
int temp[30];
int sum[35];
bool flag[35];
double q;
int n;

int main()
{
    while(~scanf("%lf%d",&q,&n))
    {
        if( n == 0 )
            break;
        int m = q*100;
        memset( dp , 0 , sizeof(dp) );
        memset( flag , 0 , sizeof(flag));
        memset( sum , 0 , sizeof(sum));
        dp[0] = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            memset( temp , 0 , sizeof(temp) );
            int a;
            char b,d;
            double c;
            scanf("%d",&a);
            for( int j = 0 ; j < a ; j++ )
            {
                cin >> b;
                cin >> d;
                scanf("%lf",&c);
                temp[b-'A']+=c*100;
                sum[i]+=c*100;
                if( sum[i] > 100000 || temp[b-'A'] > 60000 || (b-'A')>2 )
                    flag[i] = 1;
            }
        }
        for( int i = 0 ; i < n ; i++ )
            if(!flag[i])
                for( int j = m ; j >= sum[i] ; j-- )
                    dp[j] = max( dp[j] , dp[j-sum[i]]+sum[i]);
        printf("%.2lf\n",dp[m]/100.0);
    }
    return 0;
}
