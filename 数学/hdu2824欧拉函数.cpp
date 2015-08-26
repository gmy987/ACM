/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-25 19:06
*
* Filename: hdu2824.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 3000003
#define LL long long

using namespace std;
LL phi[maxn],prime[maxn];
int cnt;
void phi_prime(){
    cnt = 0,phi[1] = 1;
    for( LL i = 2 ; i < 3000000 ; i++ ){
        if(!phi[i]){
            prime[cnt++] = i;
            phi[i] = i-1;
        }
        for( int k = 0 ; k < cnt && prime[k]*i < 3000000 ; k++ )
            if(i%prime[k]) phi[i*prime[k]] = phi[i]*(prime[k]-1);
            else {
                phi[i*prime[k]] = phi[i]*prime[k];
                break;
            }
    }
    for( int i = 2 ; i < 3000000 ; i++ ) phi[i] += phi[i-1];
}

int main(){
    int a,b;
    phi_prime();
    while(~scanf("%d%d",&a,&b)){
        printf("%I64d\n",phi[b]-phi[a-1]);
    }
    return 0;
}
