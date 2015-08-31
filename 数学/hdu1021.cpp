/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-31 20:23
*
* Filename: hdu1021.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int f[1000005];

int main(){
    f[0] = 7%3;
    f[1] = 11%3;
    for( int i = 2 ; i < 1000000 ; i++ ){
        f[i] = (f[i-1]+f[i-2])%3; 
    }
    int n;
    while(~scanf("%d",&n)){
        printf(f[n]==0?"yes\n":"no\n");
    }
    return 0;
}
