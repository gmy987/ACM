#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
int a[10005];
int dp[10005];

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        memset( dp , 0 , sizeof(dp));
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        dp[0] = a[0];
        int s=0,t=0;
        int ans=a[0];
        for( int i = 1 ; i < n ; i++ )
        {
            dp[i] = max( dp[i-1]+a[i] , a[i] );
            if( ans < dp[i] )
            {
                ans = dp[i];
                t = i;
            }
        }
        int temp = 0;
        if( ans < 0 )
        {
            printf("0 %d %d\n",a[0],a[n-1]);
            continue;
        }
        for( int i = t ; i >= 0 ; i-- )
        {
            temp+=a[i];
            if( temp == ans )
            {
                s = i;
                break;
            }
        }
        printf("%d %d %d\n",ans,a[s],a[t]);
    }
    return 0;
}
