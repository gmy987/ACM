/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-09-01 14:05
*
* Filename: spoj705.cpp
*
* Description: 要求不重复的子串个数，相当于对于每个后缀求不重复的前缀的个数,每个后缀有
*              n-sa[k]个前缀(即此后缀的长度),sa[k]和sa[k-1]有height[k]个重复前缀
*              则每个sa[k],对答案的贡献为n-sa[k]-height[k],最终答案即为从sa[1]...sa[k]
*              将n-sa[k]-height[k]累加
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 50005

using namespace std;
int a[maxn],b[maxn],c[maxn];
int sa[maxn],rr[maxn];
int height[maxn];
char s[maxn];
void findSa( int n , int m ){
    int i,k;
    int *x = a,*y = b;
    for( i = 0 ; i < m ; i++ ) c[i] = 0;
    for( i = 0 ; i < n ; i++ ) c[x[i]=s[i]]++;
    for( i = 1 ; i < m ; i++ ) c[i] += c[i-1];
    for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[i]]] = i;
    for( k = 1 ; k <= n ; k<<=1 ){
        int p = 0;
        for( i = n-k ; i < n ; i++ ) y[p++] = i;
        for( i = 0 ;  i < n ; i++ ) 
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

void findHeight(int n){
    int i,j,k=0;
    for( i = 1 ; i <= n ; i++ ) rr[sa[i]] = i;
    for( i = 0 ; i < n ; height[rr[i++]]=k)
        for(k?k--:0,j=sa[rr[i]-1];s[i+k]==s[j+k];k++);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int n = strlen(s);
        s[n] = '$';
        findSa(n+1,'Z'+1);
        findHeight(n);
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ ){
            ans += n-sa[i]-height[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
