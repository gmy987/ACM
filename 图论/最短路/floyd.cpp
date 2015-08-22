#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

void floyd()
{
    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < n ; j++ )
            for( int k = 0 ; k < n ; k++ )
                dis[i][j] = min( dis[i][j] , dis[i][k] + dis[k][j] );
}
