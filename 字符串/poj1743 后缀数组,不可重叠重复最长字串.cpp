
/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-12 13:09
*
* Filename: poj1743.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 30000

using namespace std;
int s[maxn];
int sa[maxn],a[maxn],b[maxn],c[maxn];
int height[maxn],rrank[maxn];
int n;
void findSA(int m,int n){
    int i,k;
    int *x = a,*y = b;
    for( i = 0 ; i < m ; i++ ) c[i] = 0;
    for( i = 0 ; i < n ; i++ ) c[x[i]=s[i]]++;
    for( i = 1 ; i < m ; i++ ) c[i] += c[i-1];
    for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[i]]] = i;
    for( k = 1 ; k <= n ; k<<=1 )
    {
        int p = 0;
        for( i = n-k ; i < n ; i++ ) y[p++] = i;
        for( i = 0 ; i < n ; i++ )
            if(sa[i]>=k) y[p++] = sa[i]-k;
        for( i = 0 ; i < m ; i++ ) c[i] = 0;
        for( i = 0 ; i < n ; i++ ) c[x[y[i]]]++;
        for( i = 1 ; i < m ; i++ ) c[i]+=c[i-1];
        for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        x[sa[0]] = 0 , p = 1;
        for( i = 1 ; i < n ; i++ )
            x[sa[i]] = (y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
        if(p>=n) break;
        m = p;
    }
}
void findHeight(int n)
{
    int i,j,k=0;
    for( i = 1 ; i <= n ; i++ ) rrank[sa[i]] = i;
    for( i = 0 ; i < n ; height[rrank[i++]]=k)
        for(k?k--:0,j=sa[rrank[i]-1];s[i+k]==s[j+k];k++);
}
int num[maxn];
bool judge(int k ){
    int mmin = sa[1],mmax = sa[1];
    for( int i = 2 ; i <= n ; i++ ){
        if(height[i]>=k){
            mmin = min(mmin,sa[i]);
            mmax = max(mmax,sa[i]);
            if(abs(mmax-mmin)>k) 
                return true;
        }
        else{
            mmin = mmax = sa[i];
        }
    }
    return false;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        for( int i = 0 ;i < n ; i++ ) scanf("%d",&num[i]);
        for( int i = 0 ; i < n-1 ; i++ ) s[i] = num[i+1]-num[i]+89;
        n--;
        s[n] = 0;
        findSA(200,n+1);
        findHeight(n);
        int low = 4 , high = (n-1)/2 , mid;
        int ans = -1;
        while(low<=high){
            mid = low + high>>1;
            if(judge(mid))
            {
                ans = max(ans,mid);
                low = mid+1;
            }
            else high = mid-1;
        }
        printf("%d\n",ans<4?0:ans+1);
    }
    return 0;
}
