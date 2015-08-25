/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-24 19:10
*
* Filename: hdu3501.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
#define LL long long
using namespace std;
long long n;
LL Eular(LL n) {
    LL cnt=1;
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            cnt*=(i-1);
            n/=i;
            while(n%i==0) {
                n/=i;
                cnt*=i;
            }
        }
    }
    if(n>1)cnt*=(n-1);
    return cnt;
}

int main(){
    while(~scanf("%lld",&n)&&n){
        long long sum = (n)*(long long)(n-1)/2;
        printf("%lld\n",(sum-n*Eular(n)/2+MOD)%MOD);
    }
    return 0;
}
