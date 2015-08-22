/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-12 17:12
*
* Filename: hdu3519.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MOD 10007 
using namespace std;
struct Mat{
    int m[2][2];
};
Mat init(Mat a , int c ){
    for( int i = 0 ; i < 2 ; i++ )
        for( int j = 0 ; j < 2 ; j++ )
            a.m[i][j] = c;
    return a;
}
Mat mul( Mat a , Mat b ){
    Mat c;
    c = init(c,0);
    for( int i = 0 ; i < 2 ; i++ )
        for( int j = 0 ; j < 2 ; j++ )
            for( int k = 0 ; k < 2 ; k++ )
                c.m[i][j] = (c.m[i][j]+(a.m[i][k]*b.m[k][j]))%MOD;
    return c;
}
Mat fast_mul(int n){
    Mat ans;
    ans = init(ans,0);
    for( int i = 0 ; i < 2 ; i++ ) ans.m[i][i] = 1;
    Mat tmp;
    tmp.m[0][0] = tmp.m[0][1] = tmp.m[1][0] = 1;
    tmp.m[1][1] = 0;
    while(n){
        if(n&1) ans = mul(ans,tmp);
        tmp = mul(tmp,tmp);
        n>>=1;
    }
    return ans;
}
int fast_mod( int n ){
    int ans = 1;
    int a = 2;
    while(n){
        if(n&1) ans = ans*a%MOD;
        a = a*a%MOD;
        n >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    while(~scanf("%d",&n)){
        if( n == 1 ){
            printf("0\n");
            continue;
        }
        Mat ans = fast_mul(n-2);
        int res = ans.m[0][0]*4+ans.m[0][1]*2;
        printf("%d\n",(fast_mod(n)%MOD-res%MOD+MOD)%MOD);
    }
    return 0;
}
