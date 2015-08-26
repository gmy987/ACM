/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-26 14:39
*
* Filename: 327A.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 120
using namespace std;
int cnt[maxn];
int a;

int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(cnt,0,sizeof(cnt));
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%d",&a);
            cnt[i] = cnt[i-1];
            if(a==1) cnt[i]++;
        }
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = i ; j <= n ; j++ ){
                ans = max(ans,cnt[n]-2*(cnt[j]-cnt[i-1])+(j-i+1));
            }
        printf("%d\n",ans);

    }
    return 0;
}
