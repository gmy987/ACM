#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int t;
int n,m;
int value[35];
int dp[550][2];

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset( dp , 0 , sizeof(dp) );
        scanf("%d%d",&n,&m);
        for( int i = 0 ;  i < n ; i++ )
            scanf("%d",&value[i]);
        for( int i = 0 ; i <= m ; i++ )
            dp[i][1] = 1;
        for( int i = 0 ; i < n ; i++ )
            for( int j = m ; j >= value[i] ; j-- )
            {
                if( dp[j][0]== dp[j-value[i]][0]+1 )
                    dp[j][1] = dp[j-value[i]][1]+dp[j][1];
                else if( dp[j][0] < dp[j-value[i]][0]+1 )
                {
                    dp[j][1] = dp[j-value[i]][1];
                    dp[j][0] = dp[j-value[i]][0]+1;
                }
            }
        if( dp[m][0] == 0 )
            printf("Sorry, you can't buy anything.\n");
        else
            printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",dp[m][1],dp[m][0]);
    }
    return 0;
}
