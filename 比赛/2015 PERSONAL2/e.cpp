#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1005

using namespace std;

int main()
{
    int t;
    int a[MAXN];
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        double sum = 0;
        for( int i = 0 ; i < n ; i++  )
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sum/=n;
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if( a[i] > sum )
                ans++;
        double cnt = (double)ans/n;
        printf("%.3lf%%\n",cnt*100);
    }
    return 0;
}
