#include <cstdio>
#include <cstring>
#include <iostream>
/*
 对于ax+by=n这样的方程
 首先判断n%gcd(a,b)==0?有解:无解
 然后先求ax0+by0=gcd(a,b)
 则对于ax+by=n,x=x0*n/gcd(a,b),y=y0*n/gcd(a,b)
 所有的解可表示为 X = x+b/gcd(a,b)*t , Y = y-a/gcd(a,b)*t
 令 mod = b/gcd(a,b)
 则最小整数解为 xx = (x%mod+mod)%mod
 */

using namespace std;
long long gcd( long long a, long long b )
{
    if(!b) return a;
    return gcd(b,a%b);
}
long long extend_gcd( long long a , long long b , long long &x , long long &y )
{
    if(!b)
    {
        x = 1LL;
        y = 0LL;
        return a;
    }
    long long d = extend_gcd( b , a%b , y , x );
    y -= a/b*x;
    return d;
}
long long a,b,c,k;

int main()
{
    while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&k))
    {
        if( a == 0 && b == 0 && c == 0 && k == 0 )
            break;
        long long d = 1LL << k;
        long long g = gcd(c,d);
        if((b-a)%g)
        {
            printf("FOREVER\n");
            continue;
        }
        long long x0,y0;
        extend_gcd(c,d,x0,y0);
        x0 = x0*(b-a)/g;
        long long mod = d/g;
        x0 = (x0%mod+mod)%mod;
        printf("%lld\n",x0);
    }
    return 0;
}
