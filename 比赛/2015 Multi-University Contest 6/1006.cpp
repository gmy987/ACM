#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 100007

using namespace std;

typedef long long LL;

int t,n;
int a[MAX];
LL sum[MAX];

int log22 ( int x )
{
    if ( x == 0 ) return 0;
    return log2(x);
}

int bsearch ( int x , int num )
{
    int l = x , r = n , mid;
    while ( l != r )
    {
        mid = (l+r+1)>>1;
        if ( log22(sum[mid]-sum[x-1]) > num ) r = mid-1;
        else l = mid;
    }
    if ( log22(sum[l]-sum[x-1]) < num ) return -1;
    return l;
}

int main ( )
{
    scanf ("%d" , &t );
    while ( t-- )
    {
        scanf ( "%d" , &n );
        sum[0] = 0;
        LL ans = 0;
        for ( int i = 1 ; i <= n ; i++ )
        {
            scanf ( "%d" , &a[i] );
            sum[i] = sum[i-1] + a[i];
        }
        int high = log22(sum[n]);
        int loc[50];
        memset ( loc , -1 , sizeof ( loc ));
        for ( int i = 1 ; i <= n ;i ++ )
        {
            int low = log22(sum[i]-sum[i-1]);
            //cout << "loc : " << i << " " << low << " " << high << endl;
            for ( int j = low ; j <= high ; j++ )
            {
                int x = bsearch ( i , j );
                //cout << "Yes : " << x << endl;
                loc[j] = x;
                //cout << loc[j] << " ";
            }
            //cout << endl;
            for ( int j = low ; j <= high ; j++ )
            {
                if ( loc[j] == -1 ) break;
                if ( j == low )
                {
                    LL  ii = i;
                    LL len = loc[j]-ii+1;
                    ans += (ii*len + (ii+loc[j])*len/2LL)*(j+1);
                }
                else
                {
                    LL ii = i;
                    LL len = loc[j]-loc[j-1];
                    ans += ( ii*len + (loc[j-1]+1+loc[j])*len/2LL)*(j+1);
                }
            }
            //cout << ans << endl;
        }
        printf ( "%lld\n" , ans );
    }
}
