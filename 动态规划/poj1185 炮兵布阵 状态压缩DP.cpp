#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int n,m;
int dp[105][70][70],st[70],land[105];
int sum[70];
bool ok( int x )
{
    if(x&x<<1) return false;
    if(x&x<<2) return false;
    return true;
}
int findsum( int x )
{
    int sum = 0;
    while(x>0)
    {
        if(x&1) sum++;
        x >>= 1;
    }
    return sum;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        char a[20];
        memset(dp,0xff,sizeof(dp));
        memset(land,0,sizeof(land));
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%s",a);
            for( int j = 0 ; j < m ; j++ )
                if(a[j]=='H')
                    land[i]+=1<<(m-j-1);
        }
        int k = 0;
        for( int i = 0 ; i < (1<<m) ; i++ )
        {
            if(ok(i))
            {
                st[k] = i;
                sum[k++] = findsum(i);
            }
        }
        for( int i = 0 ; i < k ; i++ )
        {
            if( st[i]&land[0] )
                continue;
            dp[0][i][0] = sum[i];
        }
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < k ; j++ )
            {
                if( st[j]&land[i] )
                    continue;
                for( int p = 0 ; p < k ; p++ )
                {
                    if( st[p]&land[i-1] )
                        continue;
                    if( st[p]&st[j] )
                        continue;
                    for( int q = 0 ; q < k ; q++ )
                    {
                        if( st[q] & st[p] )
                            continue;
                        if( st[q] & st[j] )
                            continue;
                        if( dp[i-1][p][q] == -1 )
                            continue;
                        dp[i][j][p] = max( dp[i][j][p] , dp[i-1][p][q]+sum[j] );
                    }
                }
            }
        int ans = 0;
        for( int i = 0  ; i < k ; i++ )
            for( int j = 0 ; j < k ; j++ )
                ans = max(ans,dp[n-1][i][j] );
        printf("%d\n",ans);
    }
    return 0;
}
