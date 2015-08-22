#include <cstdio>
#include <cstring>

using namespace std;

int extended_gcd(int a,int b,int &x,int &y)
{
    int ans,t;
    if (b==0) { x=1; y=0; return a; }
    else { ans=extended_gcd(b,a%b,x,y); t=x; x=y; y=t-(a/b)*y;}
    return ans;
}

