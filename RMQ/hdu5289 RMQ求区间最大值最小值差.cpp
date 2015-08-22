#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#define MAXN 100005

using namespace std;
int a[MAXN];
int maxsum[MAXN][18],minsum[MAXN][18];
int n,k;
void rmq()
{
    for( int j = 1 ; j <= 17 ; j++ )
        for( int i = 1 ; i <= n ; i++ )
            if( i + (1<<j)-1 <= n)
            {
                maxsum[i][j] = max(maxsum[i][j-1],maxsum[i+(1<<(j-1))][j-1]);
                minsum[i][j] = min(minsum[i][j-1],minsum[i+(1<<(j-1))][j-1]);
            }
} 
int query(int l,int r)
{
    int k = log((double)(r-l+1))/log(2.0);
    return max(maxsum[l][k],maxsum[r-(1<<k)+1][k])-min(minsum[l][k],minsum[r-(1<<k)+1][k]);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d",&a[i]);
        for( int i = 1 ; i <= n ; i++ )
            maxsum[i][0] = minsum[i][0] = a[i];
        rmq();
        int l,r,mid;
        long long ans = 0;
        for( int i = 1 ; i <= n ; i++ )
        {
            l = i,r = n;
            while( l <= r )
            {
                mid = l + r >> 1;
                if( query(i,mid) >= k )
                    r = mid-1;
                else l = mid+1;
            }
            ans+=(long long)(r-i+1);
        }
        printf("%lld\n",ans);

    }
    return 0;
}
