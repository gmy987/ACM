/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-21 12:02
*
* Filename: codeforces11A
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int n,d;
    int a;
    while(~scanf("%d%d",&n,&d)){
        long long ans = 0;
        scanf("%d",&a);
        int tmp = a;
        int tmp2;
        for( int i = 1 ; i < n ; i++ ){
            scanf("%d",&a);
            if(tmp>=a){
                tmp2 = (tmp-a)/d+1;
                ans+=tmp2;
                a += tmp2*d;
            }
            tmp = a;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


