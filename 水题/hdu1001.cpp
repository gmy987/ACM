/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-07 13:13
*
* Filename: hdu1001.cpp
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
    int n;
    while(~scanf("%d",&n))
    {
        if(n&1) printf("%d\n",(n+1)/2*n);
        else printf("%d\n",n/2*(n+1));
    }
    return 0;
}

