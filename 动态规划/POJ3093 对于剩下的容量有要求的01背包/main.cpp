/*给n个物品，容量为V的包，要求这样的方案数：选中k个物品放入背包后，剩下的物品中，任意一个都放不进去

考虑什么情况下一个都放不进去，就是剩下物品中体积最小的那个（体积为v)都放不进去，即背包装载容量应为[V-v+1,V]
那么我们可以将物品按容量排序，从小到大枚举不放入背包的体积最小的，那么此时比它小的物品都应该放入背包中，
我们可以对剩下的i+1到n的物品做01背包，然后将可行的方案统计出来，这样，第i件物品考虑了i-1次，总复杂度为O(n^2*V)

n较大的话会超时，我们可以反过来做，每个物品只放入背包中一次，即枚举的时候从最大的开始，先统计此时的方案数，然后将
物品放入背包，这样一直下去，总复杂度O(n*V)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[1005];

int main()
{
    int t;
    scanf("%d",&t);
    for( int m = 1 ; m <= t ; m++)
    {
        int v,d,ans = 0,k;
        int a[35];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        scanf("%d%d",&v,&d);
        for( int i = 1 ; i <= v ; i++ )
            scanf("%d",&a[i]);
        sort(a+1,a+v+1);
        int sum[35];
        sum[0] = 0;
        for( int i = 1 ; i <= v ; i++ )
            sum[i] = sum[i-1]+a[i];
        for( int i = v ; i>=1 ; i-- )//从价值最大开始枚举，将当前价值i作为未选中的最小价值，即小于此价值的应该都在背包里
        {
            k = max(0,d-sum[i]+1);
            for( int j = d-sum[i-1] ; j>=k ; j--)//因为此时小于i的都在背包内，所以计算有多少种情况
                ans+=dp[j];
            for( int j = d ; j>=a[i] ; j-- )//对于i+1到v做01背包
                dp[j]+=dp[j-a[i]];
        }
        if(a[1]>d)
            ans = 0;
        printf("%d %d\n",m,ans);
    }
}
