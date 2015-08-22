#include <iostream>
#include <cstdio>
#include <algorithm>
#define LL long long

using namespace std;
const LL mod = 1000000007;

int n,t;

LL pow ( LL num , LL n )
{
    LL ret = 1;
    while ( n )
    {
        if ( n&1 )
        {
            ret = ret*num%mod;
        }
        num = num*num%mod;
        n >>= 1;
    }
    return ret;
}

int main ( )
{
    scanf ( "%d" , &t );
    while ( t-- )
    {
        scanf ( "%d" , &n );
        LL ans = pow ( 2 , n-1 );
        cout << ans-1 << endl;
    }
    return 0;
}
