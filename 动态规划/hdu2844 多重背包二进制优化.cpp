#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 105
#define MAXM 100005

using namespace std;
int a[MAXN],b[MAXN];
int cnt[MAXM];
int dp[MAXM];

int main()
{
    int n,m;
    int sum = 0;
    while(~scanf("%d%d",&n,&m))
    {
        if( n == 0 && m == 0 )
            break;
        int num = 0;
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&b[i]);
        int cnt;
        for( int i = 0 ; i < n ; i++ )
        {
            cnt = b[i];
            for( int k = 1 ; k <= cnt ; k<<=1 )
            {
                for( int j = m ; j >= k*a[i] ;j-- )
                    dp[j] += dp[j-k*a[i]];
                cnt-=k;
            }
            if(cnt)
                for( int j = m ; j >= cnt*a[i] ; j-- )
                    dp[j] += dp[j-cnt*a[i]];
        }
        int ans = 0;
        for( int i = 1 ; i <= m ; i++ )
            if( dp[i] ) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
