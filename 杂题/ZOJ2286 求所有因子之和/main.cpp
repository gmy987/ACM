#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int f[1000006];
void factor()
{
    f[1] = 0;
    for( int i = 1 ; i < 1000006 ; i++ )
        f[i] = 1;
    for ( int i = 2 ; i < 1000006 ; i++ )
        for( int j = i*2 ; j < 500003 ; j+=i )
            f[j] += i;
}

int main()
{
    int m;
    factor();
    while(~scanf("%d",&m))
    {
        sort( f+1 , f+1000000 );
        int low = 1,high = 1000000;
        int mid;
        while( low < high )
        {
            mid = low + high + 1 >> 1;
            if( f[mid] > m )
                high = mid - 1;
            else
                low = mid;
        }
        printf("%d\n",low);
    }
}
