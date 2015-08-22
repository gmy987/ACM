//此题要求恰好等于背包容量时的最小值，因此，初始化dp的时候，出了0位置以外
//其他位置要给dp赋上一个足够大的值，以表示不能达到恰好状态。
//要注意这个值的大小，要比题中给的可能的范围大。

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int dp[10000],p[502],w[502];
int e,f,n;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(p,0,sizeof(p));
        memset(w,0,sizeof(w));
        for( int i = 0 ; i < 10000 ; i++ )
            dp[i] = 99999999;
        dp[0] = 0;
        scanf("%d%d%d",&e,&f,&n);
        int sumOfWeight = f-e;
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d%d",&p[i],&w[i]);
        for( int i = 1 ; i<= n ;i++)
            for( int j = w[i] ; j<= sumOfWeight ; j++ )
                dp[j] = min(dp[j],dp[j-w[i]]+p[i]);
        if(dp[sumOfWeight]==99999999)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[sumOfWeight]);
    }
    return 0;
}
