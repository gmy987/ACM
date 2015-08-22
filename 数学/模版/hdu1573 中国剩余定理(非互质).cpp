#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 12

using namespace std;
int a[MAXN],b[MAXN];
int mod;
int gcd( int a , int b )
{
    if(!b) return a;
    return gcd( b , a%b );
}
int extended_gcd( int a , int b , int &x , int &y )
{
    int d;
    if(!b){
        x=1,y=0;
        return a;
    }
    d = extended_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int inv( int a , int n )
{
    int x,y;
    int t = extended_gcd(a,n,x,y);
    if(t!=1)
        return -1;
    return (x%n+n)%n;
}
int lcm;
bool merge_(int a1 , int n1, int a2 ,int n2 , int &a3 , int &n3)
{
    int d = gcd(n1,n2);
    int c = a2 - a1;
    if(c%d)
        return false;
    c = (c%n2+n2)%n2;
    c /= d;
    n1 /= d;
    n2 /= d;
    c *= inv(n1,n2);
    c %= n2;
    c *= n1*d;
    c += a1;
    n3 = n1 * n2 *d;
    a3 = (c%n3+n3)%n3;
    return true;
}
int chinese_remainder( int a[] , int b[] , int len )
{
    int a1 = a[0],n1 = b[0];
    int a2,n2;
    for( int i = 1 ; i < len ; i++ )
    {
        int aa,nn;
        a2 = a[i],n2 = b[i];
        if(!merge_(a1,n1,a2,n2,aa,nn))
            return -1;
        a1 = aa;
        n1 = nn;
    }
    mod = n1;
    return (a1%n1+n1)%n1;
}

int main()
{
    int t;
    scanf("%d",&t);
    int n,m;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for( int i = 0 ; i < m ; i++ )
            scanf("%d",&a[i]);
        for( int i = 0 ; i < m ; i++ )
            scanf("%d",&b[i]);
        lcm = 1;
        for( int i = 0 ; i < m ; i++ )
            lcm = a[i]/gcd(lcm,a[i])*lcm;
        int ans = chinese_remainder(b,a,m);
        if( ans == -1 )
        {
            printf("0\n");
            continue;
        }
        if( ans > n )
        {
            printf("0\n");
            continue;
        }
        int res = (n-ans)/lcm+1;
        if( ans == 0 )
            res--;
        printf("%d\n",res);
    }
    return 0;
}
