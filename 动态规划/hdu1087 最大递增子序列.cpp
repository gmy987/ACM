#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define MAXN 1005

using namespace std;
int a[MAXN];
int sum[MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d",&a[i]);
            sum[i] = a[i];
        }
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < i ; j++ )
            {
                if( a[i] > a[j] )
                    sum[i] = max( sum[i] , sum[j]+a[i] );
            }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans = max( ans , sum[i] );
        printf("%d\n",ans);
    }
    return 0;
}
