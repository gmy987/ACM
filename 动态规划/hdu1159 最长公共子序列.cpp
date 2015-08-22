#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 1100

using namespace std;
int dp[MAXN][MAXN];
char a[MAXN],b[MAXN];

int main()
{
    while(~scanf("%s%s",a,b))
    {
        int l1 = strlen(a) , l2 = strlen(b);
        int i;
        for( i = 0 ; i <= l1 ; i++ )
            dp[i][0] = 0;
        for( i = 0 ; i <= l2 ; i++ )
            dp[i][0] = 0;
        for( int i = 1 ; i <= l1 ; i++ )
            for( int j = 1 ; j <= l2 ; j++ )
            {
                if( a[i-1] == b[j-1] )
                    dp[i][j] = dp[i-1][j-1]+1;
                else{
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
                }
            }
        printf("%d\n",dp[l1][l2]);
    }
    return 0;
}
