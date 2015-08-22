/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-20 19:26
*
* Filename: hdu5414.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100006

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    char str1[maxn];
    char str2[maxn];
    while(t--){
        scanf("%s",str1);
        scanf("%s",str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        if(len1>len2){
            puts("No");
            continue;
        }
        int i,j;
        if(str1[0]!=str2[0]){
            puts("No");
            continue;
        } 
        for( i = 1 ; i < len1 ; i++ ){
            if(str1[i]!=str1[0]) break;
        }
        for( j = 1 ; j < len2 ; j++ ){
            if(str2[j]!=str2[0]) break;
        }
        if(j>i){
            puts("No");
            continue;
        }
        i = 0;
        for( j = 0 ; j < len2 && i < len1 ; j++ ){
            if(str1[i]==str2[j]) i++;
        }
        if(i==len1) puts("Yes");
        else puts("No"); 
    }
    return 0; 
}
