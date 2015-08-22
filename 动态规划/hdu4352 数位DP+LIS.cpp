/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-05 19:39
*
* Filename: hdu4352.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

LL s,st;
int k;
int num[100];
int len;
LL dp[25][1<<10][11];
int getNum( int s )
{
    int ans = 0;
    while(s)
    {
        if(s&1) ans++;
        s>>=1;
    }
    return ans;
}
int getNews(int x,int s)
{
    for( int i = x ; i < 10 ; i++ )
    {
        if(s&(1<<i))
            return (s^(1<<i))|(1<<x);
    }
    return s|(1<<x);
}

LL dfs( int pos , int s , bool is0  , bool isBound )
{
    if( pos == 0 ) return getNum(s)==k;
    if(!isBound&&dp[pos][s][k]!=-1) return dp[pos][s][k];
    int limit = isBound?num[pos]:9;
    LL ans = 0LL;
    for( int i = 0 ; i <= limit ; i++ )
        ans += dfs(pos-1,(is0&&i==0)?0:getNews(i,s),is0&&i==0,isBound&&i==limit);
    if(!isBound) dp[pos][s][k] = ans;
    return ans;
}
void cal( LL n )
{
    len = 0;
    while(n>0)
    {
        num[++len] = n%10;
        n/=10;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    int cas = 1;
    memset(dp,0xff,sizeof(dp));
    while(t--)
    {
        printf("Case #%d: ",cas++);
        scanf("%I64d%I64d%d",&s,&st,&k);
        cal(s-1);
        LL tmp = dfs(len,0,true,true);
        cal(st);
        printf("%I64d\n",dfs(len,0,true,true)-tmp);
    }
    return 0;
}
