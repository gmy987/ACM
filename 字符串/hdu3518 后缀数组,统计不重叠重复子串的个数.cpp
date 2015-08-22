/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-12 15:19
*
* Filename: hdu3518.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 3005
using namespace std;
int rr[maxn],sa[maxn],a[maxn],b[maxn],c[maxn];
char s[maxn];
int height[maxn];
void findSa(int m,int n){
   int i,k;
    int *x = a,*y = b;
    for( i = 0 ; i < m ; i++ ) c[i] = 0;
    for( i = 0 ; i < n ; i++ ) c[x[i]=s[i]]++;
    for( i = 1 ; i < m ; i++ ) c[i] += c[i-1];
    for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[i]]] = i;
    for( k = 1 ; k <= n ; k <<= 1 ){
        int p = 0;
        for( i = n-k ; i < n ; i++ ) y[p++] = i;
        for( i = 0 ; i < n ; i++ )
            if(sa[i]>=k) y[p++] = sa[i]-k;
        for( i = 0 ; i < m ; i++ ) c[i] = 0;
        for( i = 0 ; i < n ; i++ ) c[x[y[i]]]++;
        for( i = 1 ; i < m ; i++ ) c[i] += c[i-1];
        for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        x[sa[0]] = 0 , p = 1;
        for( i = 1 ; i < n ; i++ )
            x[sa[i]] = (y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
        if( p >= n ) break;
        m = p;
    } 
}
void findHeight(int n){
    int i,j,k=0;
    for( i = 1 ; i <= n ; i++ ) rr[sa[i]] = i;
    for( i = 0 ; i < n ; height[rr[i++]]=k )
        for(k?k--:0,j=sa[rr[i]-1];s[i+k]==s[j+k];k++);
}

int main()
{
    while(~scanf("%s",s))
    {
        if(!strcmp(s,"#")) break;
        int n = strlen(s);
        s[n] = '0';
        findSa('z'+1,n+1);
        findHeight(n);
        long long ans = 0;
        int mmin,mmax;
        for( int i = 1 ; i <= n/2 ; i++ ){
            mmin = mmax = sa[1];
            for( int j = 2 ; j <= n ; j++ ){
                if(height[j]>=i){
                    mmin = min(mmin,sa[j]);
                    mmax = max(mmax,sa[j]);
                }
                else{
                    if(mmax-mmin>=i) ans++;
                    mmax = mmin = sa[j];
                }
            }
            if(mmax-mmin>=i) ans++;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
