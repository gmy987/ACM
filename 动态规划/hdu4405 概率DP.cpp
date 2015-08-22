#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int n,m,cnt;
double dp[100015];
int path[100005];
struct Node{
    int to,from,next;
}edge[1005];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if( n == 0 && m == 0 )
            break;
        cnt = 0;
        memset(dp,0,sizeof(dp));
        memset( path , -1 , sizeof(path) );
        int u,v;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&u,&v);
            path[u] = v;
        }
        dp[n] = -1;
        for( int i = n ; i >= 0 ; i-- )
        {
            if( path[i] != -1 )
            {
                dp[i] = dp[path[i]];
            }
            else
            {
                double temp = 0;
                for( int k = 1 ; k <= 6 ; k++ )
                     temp += dp[i+k];
                temp /= 6;
                dp[i] += temp;
                dp[i] += 1;
            }
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
