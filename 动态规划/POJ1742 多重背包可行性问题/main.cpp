//此题是多重背包可行性问题，若使用优化的多重背包，则会TLE
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
//dp用来记录当前值有没有被组成过，f用来计算每种面值选取不同个数时的情况
int dp[100005],f[100005],a[105],c[105];

int main()
{
    int n,m;
    while( scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d",&a[i]);
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d",&c[i]);
        for( int i = 1 ; i <= n ; i++ ){
            memset(f,0,sizeof(f));
            for( int j = a[i] ; j <= m ; j++)
            {
                //dp[j]未被记录，dp[j-a[i]]已经被记录，当前面值使用的硬币数小于等于c[i]
                if( !dp[j]&&dp[j-a[i]]&&f[j-a[i]]+1<=c[i])
                {
                    ans++;
                    dp[j] = 1;//设置为1代表当前状态已经存在，以后不再计算。
                    f[j] = f[j-a[i]]+1;
                }
            }
        }
        printf("%d\n",ans);
    }
}
