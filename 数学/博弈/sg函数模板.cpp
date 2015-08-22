#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

void findsg(int len , int n)
{
    sort( f , f+len );
    memset( sg , 0 , sizeof(sg));
    for( int i = 1 ; i <= n ; i++ )
    {
        memset( h , 0 , sizeof(h));
        for( int j = 0 ; j < len && f[j]<=i ; j++ )
                h[sg[i-f[j]]]=1;
        for( int j = 0 ; j <= n ; j++ )
            if(!h[j])
            {
                sg[i] = j;
                break;
            }
    }
}
int main()
{
    return 0;
}
