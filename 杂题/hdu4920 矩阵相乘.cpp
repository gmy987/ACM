/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-17 15:55
*
* Filename: hdu4920.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 900

using namespace std;
struct Mat{
    int m[maxn][maxn];
};
int n;
Mat a,b,c;

int main(){
    while(~scanf("%d",&n)){
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0  ; j < n ; j++ ){
                scanf("%d",&a.m[i][j]);
                a.m[i][j]%=3;
                c.m[i][j]=0;
            } 
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ){
                scanf("%d",&b.m[i][j]);
                b.m[i][j]%=3;
            }
        for( int i = 0 ;i < n ; i++ )
            for( int k = 0 ; k < n ; k++ ){
                if(a.m[i][k]==0) continue;
                for( int j = 0 ; j < n ; j++ )
                    c.m[i][j] += a.m[i][k]*b.m[k][j];
            }
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ )
                if(!j) printf("%d",c.m[i][j]%3);
                else printf(" %d",c.m[i][j]%3);
            puts("");
        }
    }
    return 0;
}
