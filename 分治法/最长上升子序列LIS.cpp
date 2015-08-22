/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-05 14:30
*
* Filename: LIS.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 200

using namespace std;
int d[maxn],a[maxn];
int len;
int n;

int binarySearcn( int key , int l , int r )
{
    int mid;
    while( l <= r )
    {
        mid = l + r >> 1;
        if(d[mid]<key&&d[mid+1]>key) return mid;
        else if(d[mid]<key) l = mid+1;
        else r = mid-1;
    }
    return 0;
}
void LIS()
{
    int j;
    d[1] = a[1];
    len = 1;
    for( int i = 2 ; i<= n ; i++ )
    {
        //求最长不下降只需把此处改成d[len]<=a[i]
        if(d[len]<a[i]) j=++len;
        else j = binarySearcn(a[i],1,len)+1;
        d[j] = a[i];
    }
}
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ )
        scanf("%d",&a[i]);
    LIS();
    printf("%d\n",len);
    return 0;
}
