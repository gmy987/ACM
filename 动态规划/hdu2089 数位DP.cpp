/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-05 15:43
*
* Filename: hdu2089.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int num[10];
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
int dp[10][2][2];
int dfs( int pos , bool hasNum , bool is6 , bool isBound )
{
    if(!pos) return hasNum;
    if(!isBound&&dp[pos][hasNum][is6]!=-1) return dp[pos][hasNum][is6];
    int limit = isBound?num[pos]:9;
    int ans = 0;
    for( int i = 0 ; i <= limit ; i++ )
        ans += dfs(pos-1,hasNum||i==4||(is6&&i==2),i==6,isBound&&i==limit);
    if(!isBound) dp[pos][hasNum][is6] = ans;
    return ans;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if( !n && !m ) break;
        memset(dp,0xff,sizeof(dp));
        cal(n-1);
        int tmp = dfs(len,false,false,true);
        memset(dp,0xff,sizeof(dp));
        cal(m);
        printf("%d\n",m-n+1-dfs(len,false,false,true)+tmp);
    }
    return 0;
}
