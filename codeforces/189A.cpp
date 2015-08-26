/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-26 15:45
*
* Filename: 189A.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 5000

using namespace std;
int dp[maxn];
int n,a,b,c;

int main(){
    while(~scanf("%d%d%d%d",&n,&a,&b,&c)){
        memset(dp,0,sizeof(dp));
        dp[a] = 1;
        dp[b] = 1;
        dp[c] = 1;
        for( int i = min(a,min(b,c)) ; i <= n ; i++ ){
            if(i>=a&&dp[i-a]!=0) dp[i] = max(dp[i],dp[i-a]+1);
            if(i>=b&&dp[i-b]!=0) dp[i] = max(dp[i],dp[i-b]+1);
            if(i>=c&&dp[i-c]!=0) dp[i] = max(dp[i],dp[i-c]+1);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
