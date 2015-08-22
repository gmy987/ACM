/*n个整数中间填上+或者-，运算结果能否被k整除。1<=n<=10000, 2<=k<=100
思路：虽然不是最优化问题，但确实是DP，刚开始我也没想起了怎么DP。可以把结果mod k看作状态，
这样虽然n个数有2^n-1种运算方式，但结果只有k种，所以只需枚举这k个数即可。
f(i, j) 表示 前i个数运算结果mod k是否存在余数j，转移方程就简单了：如果f( i-1, j)为true，
那么把f(i, (j+a[i])mod k)和f(i, (j-a[i])mod k)置真。
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool dp[10002][102];

int mod( int n , int k)
{
    if( n >= 0 || n%k==0)
        return n%k;
    else
        return n%k+k;
}

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        int num;
        memset(dp,0,sizeof(dp));
        scanf("%d",&num);
        dp[0][mod(num,k)] = true;
        for( int i = 1 ; i < n ; i++ )
        {
            scanf("%d",&num);
            for( int j = 0 ; j< k ; j++ )
                if(dp[i-1][j])
                {
                    dp[i][mod(j+num,k)] = true;
                    dp[i][mod(j-num,k)] = true;
                }
        }
        if(dp[n-1][0])
            printf("Divisible\n");
        else
        printf("Not divisible\n");
    }
}
