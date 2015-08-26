/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-25 19:29
*
* Filename: hdu5417.cpp
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
    int x,y,w,n;
    while(~scanf("%d%d%d%d",&x,&y,&w,&n)){
        if(n==1){ puts("0"); continue; }
        int cnt = 0;
        int time = x+y;
        if(x<w){ printf("%d\n",(n-1)*time); continue; }
        n--;
        cnt = x/w+1;
        if(n%cnt==0) printf("%d\n",n/cnt*time);
        else printf("%d\n",n/cnt*time+(n%cnt)*w);
    }
    return 0;
}
