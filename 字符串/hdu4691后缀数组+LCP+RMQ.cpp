/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-14 18:36
*
* Filename: hdu4691.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100050

using namespace std;
char s[maxn];
int sa[maxn],a[maxn],b[maxn],c[maxn];
int height[maxn],rrank[maxn];
int n;
void findSa(int m,int n){
    int i,k;
    int *x = a,*y = b;
    for( i = 0 ; i < m ; i++ ) c[i] = 0;
    for( i = 0 ; i < n ; i++ ) c[x[i]=s[i]]++;
    for( i = 1 ; i < m ; i++ ) c[i] += c[i-1];
    for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[i]]] = i;
    for( k = 1 ; k <= n ; k<<=1 ){
        int p = 0;
        for( i = n-k ; i < n ; i++ ) y[p++] = i;
        for( i = 0 ; i < n ; i++ )
            if(sa[i]>=k) y[p++] = sa[i]-k;
        for( i = 0 ; i < m ; i++ ) c[i] = 0;
        for( i = 0 ; i < n ; i++ ) c[x[y[i]]]++;
        for( i = 1 ; i < m ; i++ ) c[i] += c[i-1];
        for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        x[sa[0]] = 0,p=1;
        for( i = 1 ; i < n ; i++ )
            x[sa[i]] = (y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
        if(p>=n) break;
        m = p;
    }
}
void findheight( int n ){
    int i,j,k=0;
    for( i = 1 ; i <= n ; i++ ) rrank[sa[i]] = i;
    for( i = 0 ; i < n ; height[rrank[i++]]=k )
        for(k?k--:0,j=sa[rrank[i]-1];s[i+k]==s[j+k];k++);
}
int dp[maxn][19];
void rmq( int n ){
    for( int i = 1 ; i <= n ; i++ )
        dp[i][0] = height[i];
    for( int j = 1 ; j <= 17 ; j++ )
        for( int i = 1 ; i <= n ; i++ )
            if( i + (1<<j) - 1 <= n )
                dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
    int k = log((double)(r-l+1))/log(2.0);
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int l[maxn],r[maxn];
int getNum(int n){
    int ans = 0;
    while(n){
        ans++;
        n/=10;
    }
    return ans;
}

int main(){
    int n;
    while(~scanf("%s",s)){
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ )
            scanf("%d%d",&l[i],&r[i]);
        int len = strlen(s);
        s[len] = '0';
        findSa('z'+1,len+1);
        findheight(len);
        rmq(len);
        int tmp;
        int tmp1,tmp2;
        long long ans1 = (long long)(r[0]-l[0]+1),ans2 =(long long)(3+r[0]-l[0]);
        for( int i = 1 ; i < n ; i++ ){
            ans1+=(long long)r[i]-l[i]+1;
            tmp1 = rrank[l[i]],tmp2 = rrank[l[i-1]];
            if(tmp1>tmp2) swap(tmp1,tmp2);
            if(tmp1==tmp2){
                tmp = (min(r[i],r[i-1])-l[i]);
            }
            else 
                tmp = query(tmp1+1,tmp2);
            int ll = r[i]-l[i];
            tmp = min(tmp,min(ll,r[i-1]-l[i-1]));
            int number = getNum(tmp);
            if(number==0) number++;
            if(tmp>=ll) ans2+=(long long)(2+number);
            else ans2+=(long long)(2+number+(ll-tmp));
        }
        printf("%I64d %I64d\n",ans1,ans2);

    }
    return 0;
}
