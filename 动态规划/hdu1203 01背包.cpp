#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 10005

using namespace std;
int n,m;
int a[MAXN];
double b[MAXN];
double dp[MAXN];

int main()
{
    while(scanf("%d%d",&n,&m))
    {
        memset( dp , 0 , sizeof(dp));
        if(n==0&&m==0) break; 
        for( int i = 0 ; i < m ; i++ )
            scanf("%d%lf",&a[i],&b[i]);
        for( int i = 0 ; i <= n ; i++ )
            dp[i] = 1;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = n ; j >= a[i] ; j-- )
                dp[j] = min( dp[j] , dp[j-a[i]]*(1.0-b[i]));
        }
        printf("%.1lf%%\n",(1.0-dp[n])*100);
    }
    return 0;
}
