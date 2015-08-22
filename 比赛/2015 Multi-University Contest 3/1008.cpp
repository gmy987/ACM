/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-28 19:37
*
* Filename: 1008.cpp
*
* Description: 
*
=============================================================================*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 0x7fffffff

using namespace std;
int ll,rr;

int dfs( int l , int r )
{
    if( l < 0 || r > 2*ll || l > r )
        return INF;
    if( l == r || l == 0 )
        return r;
    return min(dfs(l,r+r-l+1),min(dfs(l,r+r-l),min(dfs(l-(r-l+1),r),dfs(l-(r-l+2),r)))); 
}

int main()
{
    while(~scanf("%d%d",&ll,&rr))
    {
        if( ll == 0 ){
            printf("%d\n",rr);
            continue;
        }
        int ans = dfs(ll,rr);
        if( ans == INF )
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
