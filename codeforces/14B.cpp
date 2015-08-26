/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-21 13:58
*
* Filename: 14B.cpp
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
    int n,x,a,b;
    int prea,preb;
    while(~scanf("%d%d",&n,&x)){
        int ans = 0;
        bool flag = true;
        scanf("%d%d",&prea,&preb);
        if(prea>preb) swap(prea,preb);
        for( int i = 1 ; i < n ; i++ ){
            scanf("%d%d",&a,&b);
            if(a>b) swap(a,b);
            if(a>preb||b<prea) flag = false;
            prea = max(a,prea);
            preb = min(b,preb);
        }
        if(!flag) puts("-1");
        else {
            if(x<prea) ans += prea-x;
            else if(x > preb) ans += x-preb;
            printf("%d\n",ans);
        }
    }
    return 0;
}
