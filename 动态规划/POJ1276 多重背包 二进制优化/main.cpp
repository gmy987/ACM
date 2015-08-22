/*#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int cash,num;
    int dp[100005];
    while(scanf("%d%d",&cash,&num)!=EOF)
    {
        int n[15] = {0},d[15] = {0};
        if( num == 0 )
        {
            printf("0\n");
            continue;
        }
        for( int i = 1 ; i <= num ; i++ )
            scanf("%d%d",&n[i],&d[i]);
        if( cash == 0 )
        {
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for( int i = 1 ; i <= num ; i++  )
        {
            for( int k = 1 ; k <= n[i] ; k++ )
            {
                for ( int j = 100000 ; j >= d[i] ; j--)
                    dp[j] = max( dp[j] , dp[j-d[i]]+d[i]);
            }
        }
        printf("%d\n",dp[cash]);
    }
    return 0;
}*/

//以上方法是最直观的，但是复杂度没有优化，必然会超时，对于多重背包，采用二进制压缩的思想来优化

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int cash,num;
    int dp[100005];
    int value[5000];
    while(scanf("%d%d",&cash,&num)!=EOF)
    {
        int cnt = 0;
        if( num == 0 )
        {
            printf("0\n");
            continue;
        }

        memset(value,0,sizeof(value));
        //读入数据的同时进行二进制压缩，将处理过的数据保存在value[i]中，将数据处理成1 2 4 ...倍的单个cash数值
        for( int i = 1 ; i <= num ; i++ ){
            int a,b;
            scanf("%d%d",&a,&b);
            for( int j = 1 ; j<= a ; j*=2)
            {
                value[++cnt] = b*j;
                a-=j;
            }
            if(a>0)
                value[++cnt] = a*b;
        }

        if( cash == 0 )
        {
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));


        //之后采用01背包求解
        for( int i = 1 ; i <= cnt ; i++  )
        {
            for ( int j = 100000 ; j >= value[i] ; j--)
                    dp[j] = max( dp[j] , dp[j-value[i]]+value[i]);
        }
        printf("%d\n",dp[cash]);
    }
    return 0;
}
