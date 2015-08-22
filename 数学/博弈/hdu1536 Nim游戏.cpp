#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10005

using namespace std;
int f[MAXN],sg[MAXN],h[MAXN];
void getSg( int n , int len )
{
    memset( sg , 0 , sizeof(sg));
    sort( f , f+len );
    for( int i = 1 ; i <= n ; i++ )
    {
        memset( h , 0 , sizeof(h));
        for( int k = 0 ; f[k] <= i && k < len ; k++ )
            h[sg[i-f[k]]]=1;
        for( int k = 0 ; k <= n ; k++ )
            if( !h[k] )
            {
                sg[i] = k;
                break;
            }
    }
}


int main()
{
    int len,n,ans,tmp,m;
    while(~scanf("%d",&len)&&len)
    {
        for( int i = 0 ; i < len ; i++ )
            scanf("%d",&f[i]);
        scanf("%d",&n);
        getSg(MAXN,len);
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d",&m);
            ans = 0;
            while(m--)
            {
                scanf("%d",&tmp);
                ans^=sg[tmp];
            }
            if(ans) printf("W");
            else printf("L");
        }
        printf("\n");
    }
    return 0;
}
