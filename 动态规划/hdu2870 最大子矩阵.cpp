#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define MAXN 1005

using namespace std;
int n,m;
char a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
char d;
int l[MAXN],r[MAXN];
int dp[MAXN][MAXN];
int find( char a[MAXN][MAXN] , char flag )
{
    memset( dp , 0 , sizeof(dp) );
    for( int i = 0 ; i < m ; i++ )
        if( a[0][i] == flag ) dp[0][i] = 1;
        else dp[0][i] = 0;
    for( int i = 1 ; i < n ; i++ )
        for( int j = 0 ; j < m ; j++ )
        {
            if( a[i][j] == flag )
                dp[i][j] = dp[i-1][j]+1;
            else dp[i][j] = 0;
        }
    int ans = 0;
    int t;
    for( int i = 0 ; i < n ; i++ )
    {
        memset( l , 0 , sizeof(l) );
        memset( r , 0 , sizeof(r) );
        l[0] = 0;
        r[m-1] = m-1;
        for( int k = 1 ; k < m ; k++ )
        {
            t = k;
            while( t > 0 && dp[i][t-1] >= dp[i][k] )
                t = l[t-1];
            l[k] = t;
        }
        for( int k = m-2 ; k >= 0 ; k-- )
        {
            t = k;
            while( t < m-1 && dp[i][t+1] >= dp[i][k] )
                t = r[t+1];
            r[k] = t;
        }
        for( int k = 0 ; k < m ; k++ )
            ans = max( ans , (r[k]-l[k]+1)*dp[i][k] );
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
            {
                cin >> d;
                a[i][j] = b[i][j] = c[i][j] = d;
                if( d == 'w' || d == 'y' || d == 'z' )
                    a[i][j] = 'a';
                if( d == 'w' || d == 'x' || d == 'z' )
                    b[i][j] = 'b';
                if( d == 'x' || d == 'y' || d == 'z' )
                    c[i][j] = 'c'; 
            }
        int ans = 0;
        ans = max( ans , find(a,'a') );
        ans = max( ans , find(b,'b') );
        ans = max( ans , find(c,'c') );
        printf("%d\n",ans);
    }
    return 0;
}
