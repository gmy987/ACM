#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int value[20],energy[20];
struct Node{
    int num;
    int need[20];
}node[20];
struct DP{
    int sume,sumv;
}dp[1<<16];

int main()
{
    int t,n,e;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&e);
        memset( dp , 0xff , sizeof(dp) );
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&value[i]);
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&energy[i]);
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d",&node[i].num);
            for( int j = 0 ; j < node[i].num ; j++ ) 
                scanf("%d",&node[i].need[j]);
        }
        dp[0].sumv = dp[0].sume = 0;
        for( int i = 0 ; i < (1<<n) ; i++ )
        {
            if( dp[i].sume == -1 )
                continue;
            for( int j = 0 ; j < n ; j++ )
            {
                if( i&(1<<j) )
                    continue;
                bool flag = true;
                for( int k = 0 ; k < node[j].num ; k++ )
                    if( !(i&(1<<(node[j].need[k]-1))))
                    {
                        flag = false;
                        break;
                    }
                if(flag)
                {
                    dp[i|(1<<j)].sume = dp[i].sume+energy[j];
                    dp[i|(1<<j)].sumv = dp[i].sumv+value[j];
                }
            }
        }
        int ans = 0;
        for( int i = 0 ; i < ( 1 << n ) ; i++ )
            if( dp[i].sume <= e )
                ans = max( ans , dp[i].sumv );
        printf("%d\n",ans);
    }
    return 0;
}
