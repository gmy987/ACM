#include <cstdio>
#include <iostream>
#include <cstring>
#define ll long long
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
ll extended_gcd( ll a , ll b , ll &x , ll &y )
{
    if(!a && !b )
        return -1;
    if(!b)
    {
        x = 1LL;
        y = 0LL;
        return a;
    }
    ll d = extended_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll findMinX( ll a, ll b , ll n )
{
    long long x,y,g;
    g = extended_gcd(a,b,x,y);
    x = x/g*n;
    g = b/g;
    x = (x%g+g)%g;
    return x;
}

int main()
{
    return 0;
}
