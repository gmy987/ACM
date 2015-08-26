/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-26 13:52
*
* Filename: 455A.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100005
#define LL long long

using namespace std;
int cnt[maxn];
LL dp[maxn];

int main(){
    int n,a,m;
    while(~scanf("%d",&n)){
        m = 0;
        memset(cnt,0,sizeof(cnt));
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&a);
            cnt[a]++;
            m = max(m,a);
        }
        memset(dp,0,sizeof(dp));
        dp[0] = 0;
        dp[1] = cnt[1];
        for( int i = 2 ; i <= m ; i++ ) dp[i] = max(dp[i-1],dp[i-2]+(((LL)cnt[i])*i));
        printf("%lld\n",dp[m]);
    }
    return 0;
}
