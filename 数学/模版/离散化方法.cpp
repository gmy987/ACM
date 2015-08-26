/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-25 09:03
*
* Filename: a.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 100000

using namespace std;
int h[maxn];
int a[maxn];
int n;
void hashtable(){
    sort(a,a+n);
    int len = unique(a,a+n)-a;
    for( int i = 0 ; i < n ; i++ ) h[i] = lower_bound(a,a+len,a[i])-a+1;
}

int main(){
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
    hashtable();
    for( int i = 0 ; i < n ; i++ ) printf("%d ",h[i]);
}
