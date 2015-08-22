//此题为有负权的完全背包，所以做完全背包的循环时应该做两次。
//1. 完全背包的变型，因为涉及到找零，所以有状态转移 ： dp[v] = min(dp[v - w[i]] + 1, dp[v + w[i]] + 1)
//2. 我们可以采取两步走的方法避免深度搜索，首先利用完全背包求的不找零的情况下，容量 v 的最优策略：dp[v] = min(dp[v], dp[v - w[i]] + 1)
//3. 然后在上面的结果下再利用一次完全背包：dp[v] = min(dp[v], dp[v + w[i]] + 1)
//4. 数组要记得开大，比如下面的case： 1 95 96 97 98 99 结果应该是：12.29 25，可以想象：dp[48] = 12 * 2，即 (99 - 95) * 12.
//   上届很大了 : 99 * 12

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int dp[5010];
int a[7];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int sum = 0 , m = 0;
        for( int i = 1 ; i<= 6 ; i++ ){
            scanf("%d",&a[i]);
        }
        for(int i = 0 ; i < 5010 ; i++ )
            dp[i] = 9999999;
        dp[0] = 0;
        for( int  i = 1 ; i <= 6 ; i++ )
            for( int j = a[i] ; j <= 5010 ; j++ )
                dp[j] = min(dp[j],dp[j-a[i]]+1);
        for( int i = 1 ; i <= 6 ; i++ )
            for( int j = 5010 - a[i] ; j>= 0 ; j--)
                dp[j] = min(dp[j],dp[j+a[i]]+1);

        for( int j = 1 ; j <= 100 ; j++ ){
            sum+=dp[j];
            m = max(dp[j],m);
        }
        printf("%.2lf %d\n",(double)sum/100,m);

    }
}
