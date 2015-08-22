#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100005

using namespace std;
int l[MAXN],r[MAXN];
int n;
long long a[MAXN];

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        int i;
        for( i = 0 ; i < n ; i++ )
            scanf("%lld",&a[i]);
        l[0] = 0;
        r[n-1] = n-1;
        for( i = 1 ; i < n ; i++ )
        {
            int temp = i;
            while( temp > 0 && a[temp-1] >= a[i] )
                temp = l[temp-1];
            l[i] = temp;
        }
        for( i = n-2 ; i >= 0 ; i-- )
        {
            int temp = i;
            while( temp < n-1 && a[temp+1] >= a[i] )
                temp = r[temp+1];
            r[i] = temp;
        }
        long long m = 0;
        for( i = 0 ; i < n ; i++ )
            m = max( m , (r[i]-l[i]+1)*a[i] );
        printf("%lld\n",m);
    }
    return 0;
}
