#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
__int64 fast_mod(  __int64 a, __int64 b , __int64 mod)
{
    __int64 acc = 1;
    for( __int64 q = b ; q ; q >>= 1)
    {
        if(q&1)
            acc = a*acc%mod;
        a = a*a%mod;

    return acc;
}

int main()
{
    __int64 n;
    while(~scanf("%I64d",&n)&&n)
    {
        printf("%I64d\n",(fast_mod(2,n-1,n)+1%n)%n);
    }
    return 0;
}
