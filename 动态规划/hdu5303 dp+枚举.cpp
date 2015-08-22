#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100005

using namespace std;
int l,n,k;
int cnt;
int dis[MAXN];
long long dp[MAXN][2];
int sum;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&l,&n,&k);
        int a,b;
        cnt = 1;
        sum = 0;
        memset(dp,0,sizeof(dp));
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d%d",&a,&b);
            sum+=b;
            for( int k = 0 ; k < b ; k++ )
                dis[cnt++] = a;
        }
        sort( dis+1 , dis+sum+1 );
        for( int i = 1 ; i <= sum ; i++ )
            dp[i][0] = dp[max(i-k,0)][0]+(long long)2*dis[i];
        for( int i = sum ; i >= 1 ; i-- )
            dp[i][1] = dp[min(i+k,sum+1)][1]+(long long)2*(l-dis[i]);
        long long ans = min(dp[sum][0],dp[1][1]);
        for( int i = 1 ; i <= sum ; i++ )
        {
            ans = min(ans,dp[i][0]+dp[i+1][1]);
            ans = min(ans,dp[max(i-k,0)][0]+dp[i+1][1]+l);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
