/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-21 09:12
*
* Filename: poj2774.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 300000

using namespace std;
char str[maxn];
int sa[maxn],height[maxn],a[maxn],c[maxn],b[maxn],rr[maxn];
void findSa(int n,int m){
    int *x = a,*y = b;
    int i,k;
    for( i = 0 ; i < m ; i++ ) c[i] = 0;
    for( i = 0 ; i < n ; i++ ) c[x[i]=str[i]]++;
    for( i = 1 ; i < m ; i++ ) c[i] += c[i-1];
    for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[i]]] = i;
    for( k = 1 ; k <= n ; k <<= 1 ){
        int p = 0;
        for( i = n-k ; i < n ; i++ ) y[p++] = i;
        for( i = 0 ; i < n ; i++ )
            if(sa[i]>=k) y[p++] = sa[i]-k;
        for( i = 0 ; i < m ; i++ ) c[i] = 0;
        for( i = 0 ; i < n ; i++ ) c[x[y[i]]]++;
        for( i = 1 ; i < m ; i++ ) c[i]+=c[i-1];
        for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        x[sa[0]] = 0,p=1;
        for( i = 1 ; i < n ; i++ )
            x[sa[i]] = (y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
        if(p>=n) break;
        m = p;
    }
}
void findHeight(int n){
    int i,j,k=0;
    for( i = 1 ; i <= n ; i++ ) rr[sa[i]] = i;
    for( i = 0 ; i < n ; height[rr[i++]] = k) 
        for(k?k--:0,j=sa[rr[i]-1];str[i+k]==str[j+k];k++);
}

int main(){
        gets(str);
        int l1 = strlen(str);
        str[l1]='$';
        gets(str+l1+1);
        int l2 = strlen(str);
        str[l2] = '$';
        findSa(l2+1,'z'+1);
        findHeight(l2);
        int ans = 0;
        for( int i = 1 ; i <= l2 ; i++ )
            if((sa[i]<l1&&sa[i-1]>l1)||(sa[i]>l1&&sa[i-1]<l1))
                ans = max(height[i],ans);
        printf("%d\n",ans);
    return 0;
}
