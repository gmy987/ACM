#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int gcd( int a , int b )
{
    if( b == 0 ) return a;
    return gcd( b , a % b );
}

int main()
{
    int t,n,a,b,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if( n == 1 )
        {
            scanf("%d",&a);
            printf("%d\n",a);
        }
        else
        {
            scanf("%d%d",&a,&b);
            tmp = a/gcd(a,b)*b;
            for( int i = 0 ; i < n - 2 ; i++ )
            {
                scanf("%d",&a);
                tmp = tmp/gcd(tmp,a)*a;
            }
            printf("%d\n",tmp);
        }
    }
    return 0;
}
