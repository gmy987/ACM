/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-05 16:32
*
* Filename: hdu3652.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int dp[15][15][2][2];
int num[15];
int len;
void cal( int n )
{
    len = 0;
    while(n>0)
    {
        num[++len] = n%10;
        n/=10;
    }
}
int dfs( int pos , bool is1 , bool has13 , int mod , bool isBound )
{
    if( pos == 0 ) return has13&&(!mod);
    if(!isBound&&dp[pos][mod][is1][has13]!=-1) return dp[pos][mod][is1][has13];
    int ans = 0;
    int limit = isBound?num[pos]:9;
    for( int i = 0 ; i <= limit ; i++ )
        ans += dfs( pos-1 , i==1 , has13||(is1&&i==3) , (mod*10+i)%13 , isBound&&i==limit);
    if(!isBound) dp[pos][mod][is1][has13] = ans;
    return ans;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(dp,0xff,sizeof(dp));
        cal(n);
        printf("%d\n",dfs(len,false,false,0,true));
    }
    return 0;
}
