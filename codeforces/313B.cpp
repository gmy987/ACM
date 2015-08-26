/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-26 18:14
*
* Filename: 313B.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100005

using namespace std;
char str[maxn];
int sum[maxn];

int main(){
    int n,a,b;
    scanf("%s",str);
    sum[0] = 0;
    int len = strlen(str);
    for( int i = 0 ; i < len-1 ; i++ ){
        if(i) sum[i] = sum[i-1];
        if(str[i]==str[i+1]) sum[i]++;
    } 
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d%d",&a,&b);
        if(a==1) printf("%d\n",sum[b-2]);
        else printf("%d\n",sum[b-2]-sum[a-2]);
    }
    return 0;
}
