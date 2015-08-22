/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-15 09:19
*
* Filename: hdu1024.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 1000005
#define INF 0x7fffffff

using namespace std;
int pre[maxn],now[maxn];
int a[maxn];
int n,m;

int main(){
    while(~scanf("%d%d",&n,&m)){
        for( int i = 1 ; i <= m ; i++ )
            scanf("%d",&a[i]);
        memset(pre,0,sizeof(pre));
        memset(now,0,sizeof(now));
        long long mm;
        for( int i = 1 ; i <= n ; i++ ){
            mm = -INF;
            for( int j = i ; j <= m ; j++ ){
                now[j] = max(now[j-1]+a[j],pre[j-1]+a[j]);
                pre[j-1] = mm;
                if(now[j]>mm) mm = now[j];
            }
        }
        printf("%lld\n",mm);
    }
    return 0;
}
