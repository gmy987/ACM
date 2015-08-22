/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-09 13:26
*
* Filename: hdu4811.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
long long a,b,c;

int main()
{
    long long x,y,ans=0;
    while(~scanf("%lld%lld%lld",&a,&b,&c))
    {
        x = 0;
        if(a>2) x+=(a-2),a=2;
        if(b>2) x+=(b-2),b=2;
        if(c>2) x+=(c-2),c=2;
        if(a+b+c==0) y=0,ans=0;
        if(a+b+c==1) y=0,ans=0;
        if(a+b+c==2) y=2,ans=1;
        if(a+b+c==3) y=3,ans=3;
        if(a+b+c==4) y=4,ans=6;
        if(a+b+c==5) y=5,ans=10;
        if(a+b+c==6) y=6,ans=15;
        ans+=x*y;
        printf("%I64d\n",ans);
    }
    return 0;
}
