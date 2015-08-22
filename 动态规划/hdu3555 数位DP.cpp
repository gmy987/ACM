/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-05 15:13
*
* Filename: hdu3555.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long 
#define maxn 100

using namespace std;
LL number;
int num[maxn];
int len;
LL dp[maxn][2][2];
LL dfs( int pos , bool has49 , bool is4 , bool isBound )
{
    if(pos==0) return has49;
    if(!isBound&&dp[pos][has49][is4]!=-1) return dp[pos][has49][is4];
    int limit = isBound?num[pos]:9;
    LL ans = 0;
    for( int i = 0 ; i <= limit ; i++ )
        ans += dfs(pos-1,has49||(is4&&i==9),i==4,isBound&&i==limit);
    if(!isBound) dp[pos][has49][is4] = ans;
    return ans;
}

void cal()
{
    len = 0;
    while(number>0)
    {
        num[++len] = number%10;
        number/=10;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0xff,sizeof(dp));
        scanf("%lld",&number);
        cal();
        printf("%lld\n",dfs(len,false,false,true));
    }
}
