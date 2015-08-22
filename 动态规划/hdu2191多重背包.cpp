#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 150

using namespace std;
int p[MAXN],w[MAXN],cnt[MAXN];
int dp[MAXN];

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset( dp , 0 , sizeof(dp) );
        for( int i = 0 ; i < m ; i++ ) 
            scanf("%d%d%d",&p[i],&w[i],&cnt[i]);
        for( int i = 0 ; i < m ; i++ )
        {
            for( int k = 1 ; k <= cnt[i] ; k<<=1 )
            {
                for( int l = n ; l >= p[i]*k ; l-- )
                    dp[l] = max(dp[l],dp[l-k*p[i]]+k*w[i]);
                cnt[i]-=k;
            }
            if(cnt[i])
                for( int k = n ; k >= cnt[i]*p[i] ; k-- )
                    dp[k] = max(dp[k],dp[k-cnt[i]*p[i]]+cnt[i]*w[i]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
