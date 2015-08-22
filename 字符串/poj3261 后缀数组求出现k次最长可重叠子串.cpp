/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-18 08:49
*
* Filename: poj3261.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 20005

using namespace std;
int sa[maxn],height[maxn],a[maxn],b[maxn],c[1000015];
int rr[maxn];
int s[maxn];

void findSa( int m , int n ){
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
            if(sa[i]-k>=0) y[p++] = sa[i]-k;
        for( i = 0 ; i < m ; i++ ) c[i] = 0;
        for( i = 0 ; i < n ; i++ ) c[x[y[i]]]++;
        for( i = 1 ; i < m ; i++ ) c[i] += c[i-1];
        for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        x[sa[0]] = 0,p = 1;
        for( i = 1 ; i < n ; i++ )
            x[sa[i]] = (y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
        if( p >= n ) break;
        m = p;
    }
}
void findHeight(int n){
    int i,j,k=0;
    for( i = 1 ; i <= n ; i++ ) rr[sa[i]] = i;
    for( i = 0 ; i < n ; height[rr[i++]]=k)
        for(k?k--:0,j=sa[rr[i]-1];s[i+k]==s[j+k];k++);
}
int n,k;
bool judge( int m ){
    int num = 1;
    for( int i = 2 ; i <= n ; i++ ){
        if(height[i]>=m) num++;
        else{
            if(num>=k) return true;
            num = 1;
        }
    }
    return num>=k;
}
int main(){
    while(~scanf("%d%d",&n,&k)){
        int mm = -1;
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d",&s[i]);
            s[i]++;
            mm = max(mm,s[i]);
        }
        s[n] = 0;
        findSa(mm+9,n+1);
        findHeight(n);
        int low = 0,high = n , mid;
        int ans = 0;
        while(low<=high){
            mid = low+high>>1;
            if(judge(mid)){
                ans = max(ans,mid);
                low = mid+1;
            }
            else high = mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
