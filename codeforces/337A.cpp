/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-26 13:24
*
* Filename: 337A.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100

using namespace std;
int a[maxn];

int main(){
    int n,m;
    while(~scanf("%d%d",&m,&n)){
        for( int i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
        sort(a,a+n);
        int ans = a[m-1]-a[0];
        for( int i = m ; i < n ; i++ )
            ans = min(ans,a[i]-a[i-m+1]);
        printf("%d\n",ans);
    }
    return 0;
}
