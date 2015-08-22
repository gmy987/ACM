/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-17 08:52
*
* Filename: hdu4974.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int a[100005];

int main(){
    int t;
    int n;
    scanf("%d",&t);
    for( int i = 1 ; i <= t ; i++ ){
        scanf("%d",&n);
        for( int k = 0 ; k < n ; k++ )
            scanf("%d",&a[k]);
        sort(a,a+n);
        long long ans = a[n-1];
        long long tmp = a[n-1];
        for( int k = n-2 ; k>=0 ; ){
            while(tmp-a[k]>=0){
                tmp-=a[k];
                k--;
                if(k<0) break;
            }
            if(k<0) break;
            ans+=a[k]-tmp;
            tmp = a[k]-tmp;
            k--;
        } 
        printf("Case #%d: ",i);
        printf("%lld\n",ans);
    }
    return 0;
}
