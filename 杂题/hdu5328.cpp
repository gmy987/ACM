/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-20 08:40
*
* Filename: hdu5328.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 1000005

using namespace std;
long long a[maxn];

int main(){
    int t;
    scanf("%d",&t);
    int n;
    while(t--){
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ )
            scanf("%lld",&a[i]);
        if( n == 1 ){
            printf("1\n");
            continue;
        }
        int ans = 2;
        bool flag = false;
        int cnt = 0;
        for( int i = 1 ; i < n-1 ; i++ ){ 
            if(a[i]*2==a[i-1]+a[i+1]&&flag == false){
                flag = true;
                cnt = 3;
            }
            else if(a[i]*2==a[i+1]+a[i-1]&&flag == true) cnt++;
            else{
                flag = false;
                ans = max(ans,cnt);
                cnt = 2;
            } 
        }
        ans = max(ans,cnt);
        flag = false;
        for( int i = 1 ; i < n-1 ; i++ ){
            if(a[i]*a[i]==a[i-1]*a[i+1]&&flag==false){
                cnt = 3;
                flag = true;
            }
            else if(a[i]*a[i]==a[i-1]*a[i+1]&&flag){
                cnt++;
            }
            else{
                flag = false;
                ans = max(ans,cnt);
                cnt = 2;
            }
        }
        ans = max(ans,cnt);
        printf("%d\n",ans);
    } 
    return 0;
} 
