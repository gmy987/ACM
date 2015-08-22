#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
long long aa,bb;
long long extend_gcd( long long a, long long b , long long &x, long long &y )
{
    if(!a&&!b) return -1;
    if(!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
long long mod_reverse( long long a , long long mod )
{
    long long x,y;
    long long d = extend_gcd(a,mod,x,y);
    if( d == 1 ) return (x%mod+mod)%mod;
    else return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&aa,&bb);
        printf("%I64d\n",mod_reverse(bb,9973)*aa%9973);
    }
    return 0;
}
