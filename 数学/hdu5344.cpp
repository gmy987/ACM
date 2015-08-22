/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-06 08:59
*
* Filename: hdu5344.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int t ;
    scanf("%d",&t);
    while(t--)
    {
        long long n,m,z,l;
        scanf("%lld%lld%lld%lld",&n,&m,&z,&l);
        long long ans = 0;
        long long tmp = 0;
        for( int i = 2 ; i <= n ; i++ )
        {
            tmp = (tmp*m+z)%l;
            ans ^= tmp*2;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
