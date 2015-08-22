#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define MAXN 1005

using namespace std;
int a[MAXN][MAXN],l[MAXN],r[MAXN];
char s[5];
int n,m;

int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%d",&n,&m);
        memset( a , 0 , sizeof(a) );
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
            {
                scanf("%s",s);
                if( s[0] == 'R' )
                    a[i][j] = 0;
                else a[i][j] = a[i-1][j]+1;
            }
        int ans = 0;
        int t;
        for( int i = 1 ; i <= n ; i++ )
        {
            l[1] = 1;
            r[m] = m;
            for( int j = 2 ; j <= m ; j++ )
            {
                t = j;
                while( t > 1 && a[i][t-1] >= a[i][j] )
                    t = l[t-1];
                l[j] = t;
            }
            for( int j = m-1 ; j >= 0 ; j-- )
            {
                t = j;
                while( t < m && a[i][t+1] >= a[i][j] )
                    t = r[t+1];
                r[j] = t;
            }
            int Max = 0;
            for( int j = 1 ; j <= m ; j++ )
                ans = max( ans , (r[j]-l[j]+1)*a[i][j] );
        }
        printf("%d\n",ans*3);
    }
    return 0;
}
