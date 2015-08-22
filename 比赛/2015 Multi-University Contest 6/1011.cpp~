/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-06 12:30
*
* Filename: 1011.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
long long fast_mod(  long long a, long long b , long long mod)
{
    long long acc = 1;
    for( long long q = b ; q ; q >>= 1)
    {
        if(q&1)
            acc = a*acc%mod;
        a = a*a%mod;
    }
    return acc;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%I64d\n",fast_mod(2,n-1,1000000007)-1);
    }
    return 0;
}


