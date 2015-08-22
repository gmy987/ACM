#include <iostream>

using namespace std;
long long power( long long a , long long b , long long mod )
{
    long long acc = 1 ,q;
    for( q = b ; q ; q >>=1 )
    {
        if(q&1)
            acc = acc*a%mod;
        a = a*a%mod;
    }
    return acc;
}

//用于求a^b%mod.

