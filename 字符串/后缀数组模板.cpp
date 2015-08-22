/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-11 09:44
*
* Filename: sa.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
//s为要计算的字符串,长度为n,为了计算方便,在结尾添一个字符,且比数组中任一个字符都要小
char s[maxn];
int sa[maxn],a[maxn],b[maxn],c[maxn];
int height[maxn],rank[maxn];
int n;
//n为要求数组元素个数＋1(因为在结尾添加了一个字符)
void findSA(int m,int n)
{
    int i,k;
    //x纪录过程中的rank,y[i]保存排在第i位的第二关键字的第一关键字的位置
    int *x = a,*y = b;
    for( i = 0 ; i < m ; i++ ) c[i] = 0;
    for( i = 0 ; i < n ; i++ ) c[x[i]=s[i]]++;
    for( i = 1 ; i < m ; i++ ) c[i] += c[i-1];
    for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[i]]] = i;
    for( k = 1 ; k <= n ; k<<=1 )
    {
        int p = 0;
        //每次结尾的k位的第二关键字不存在,即最小
        for( i = n-k ; i < n ; i++ ) y[p++] = i;
        //由于要保存第一关键字的位置,所以sa[i]-k
        for( i = 0 ; i < n ; i++ )
            if(sa[i]>=k) y[p++] = sa[i]-k;
        for( i = 0 ; i < m ; i++ ) c[i] = 0;
        for( i = 0 ; i < n ; i++ ) c[x[y[i]]]++;
        for( i = 1 ; i < m ; i++ ) c[i]+=c[i-1];
        for( i = n-1 ; i >= 0 ; i-- ) sa[--c[x[y[i]]]] = y[i];
        //计算此时的rank,先将上一级的rank保存到y,通过上一级的rank计算本级的rank
        swap(x,y);
        x[sa[0]] = 0,p=1;
        for( i = 1 ; i < n ; i++ )
            x[sa[i]] = (y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
        if( p >= n ) break;
        m = p;
    }
}
//n为数组元素个数,此处不用＋1！
void findHeight(int n){
    int i,j,k=0;
    //sa数组从1-n(0位置为我们在字符串末尾自行添加的字符)
    for( i = 1 ; i <= n ; i++ ) rank[sa[i]] = i;
    // k中保存h[i-1]
    // h[i]>=h[i-1]-1,所以每次计算h[i]时,只要k不等于0,则可以从h[i-1]-1开始往后比较
    for( i = 0  ; i < n ; height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
}

int main()
{
    return 0;
}
