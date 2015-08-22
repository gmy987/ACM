#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
int dp[100005];
int a[100005];

int main()
{
    int m;
    scanf("%d",&m);
    for( int k = 1 ; k <= m ; k++ )
    {
        int n;
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        memset( dp , 0 , sizeof(dp) );
        int ans = a[0];
        dp[0] = a[0];
        int t=0,s=0;
        for( int i = 1 ; i < n ; i++ )
        {
            dp[i] = max( dp[i-1]+a[i] , a[i] );
            if( ans < dp[i] )
            {
                ans = dp[i];
                t = i;
            }
        }
        printf("Case %d:\n%d ",k,ans);
        for( int i = t ; i>=0 ; i-- )
        {
            ans-=a[i];
            if( ans==0 )
                s = i;
        }
        if( k!=m )
        printf("%d %d\n\n",s+1,t+1);
        else
            printf("%d %d\n",s+1,t+1);
    }
    return 0;
}
