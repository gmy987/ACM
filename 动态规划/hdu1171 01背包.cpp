#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;
int n;
int a[5005];
int dp[250005];

int main()
{
    while(~scanf("%d",&n)&&n>0)
    {
        memset( dp , 0 , sizeof(dp) );
        int sum = 0;
        int c,b;
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d%d",&c,&b);
            sum+=c*b;
            for( int k = 0 ; k < b ; k++ )
                a[cnt++] = c;
        }
        for( int i = 0 ; i < cnt ; i++ )
            for( int j = sum/2 ; j >= a[i] ; j-- )
                dp[j] = max( dp[j] , dp[j-a[i]]+a[i] );
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }
    return 0;
}
