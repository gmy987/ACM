/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-26 09:08
*
* Filename: hdu5418.cpp
*
* Description: 旅行商问题，从点1出发，经过所有的点再回到点1的最短路径。此题由于每个点可以走多次，所以
*              需要先用floyd处理一下任意两点之间的最短路径,若每个点只可以走一次,则不需要floyd
*              状态转移方程 dp[s|(1<<(i-1))][i] = min{dp[s|(1<<(i-1))][i],dp[s][j]+dis[j][i]}
*              dp[s][i]表示从1点出发,经过s中的所有点,到达i点的最短路径,其中s包括1点和i点
*              最终结果为 min(dp[(1<<n)-1][i]+dis[i][1]),i为除了1点外的所有点
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
#define maxm 200005
#define N 17 

using namespace std;
int dp[1<<N][N];
int dis[N][N];
int n,m;
int u,v,w;
void floyd(){
    for( int i = 1 ; i <= n ; i++ )
        for( int j = 1 ; j <= n ; j++ )
            for( int k = 1 ; k <= n ; k++ )
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(dis,0x3f,sizeof(dis));
        memset(dp,0x7f,sizeof(dp));
        for( int i = 1 ; i <= n ; i++ ) dis[i][i] = 0;
        for( int i = 0 ; i < m ; i++ ){
            scanf("%d%d%d",&u,&v,&w);
            dis[u][v] = dis[v][u] = min(dis[u][v],w);
        }
        floyd();
        dp[1][1] = 0;
        for( int i = 1 ; i < (1<<n) ; i+=2 ){
            for( int j = 2 ; j <= n ; j++ ){
                if( 1<<(j-1)&i ) continue;
                for( int k = 1 ; k <= n ; k++ ){
                    if(i&(1<<(k-1))) dp[i|(1<<(j-1))][j] = min(dp[i|(1<<(j-1))][j],dp[i][k]+dis[k][j]);
                }
            }
        }
        int ans = INF;
        for( int i = 2 ; i <= n ; i++ )
            ans = min(ans,dp[(1<<n)-1][i]+dis[i][1]);
        printf("%d\n", ans == INF?0:ans);
    }
    return 0;
}
