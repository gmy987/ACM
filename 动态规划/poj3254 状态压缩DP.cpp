#include <cstdio>
#include <cstring>
#include <iostream>
#define MOD 100000000
#define MAXN 1<<13

using namespace std;
int dp[15][MAXN];
int state[MAXN];
int cur[15];

bool judge( int a ,int k )
{
    return !(cur[k]&a);
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        memset(state,0,sizeof(state));
        memset(dp,0,sizeof(dp));
        memset(cur,0,sizeof(cur));
        int i,j,k=0;
        for( i = 0 ; i < (1<<n) ; i++ )
            if(!(i&(i<<1))) state[k++] = i;
        int x;
        for( i = 0 ; i < m ; i++ )
            for( int j = 1 ; j <= n ; j++ )
            {
                scanf("%d",&x);
                if(!x)
                    cur[i]+=1<<(n-j);
            }
        for( i = 0 ; i < k ; i++ )
            if( judge(state[i],0))
                dp[0][i] = 1;
        for( i = 1 ; i < m ; i++ )
            for( j = 0 ; j < k ; j++ )
            {
                if(!judge(state[j],i))
                    continue;
                for( int f = 0 ; f < k ; f++ )
                    if(judge(state[f],i-1)&&(!(state[f]&state[j])))
                        dp[i][j] = (dp[i][j]+dp[i-1][f])%MOD;
            }
        int ans = 0;
        for( i = 0 ; i < k ; i++ )
            ans = (ans+dp[m-1][i])%MOD;
        printf("%d\n",ans);
    }
}
