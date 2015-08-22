#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int l , n , m , mid;

int main()
{
    while( scanf ( "%d%d%d" , &l ,&n , &m )!=EOF)
    {
        int low = l,high = l;
        int *distance = new int[n+2];
        distance[0] = 0;
        distance[n+1] = l;
        for( int i = 1 ; i < n+2 ; i++ )
        {
            if( i < n + 1 )
                scanf("%d" , &distance[i]);
            if( low > distance[i] - distance[i-1])
                low = distance[i] - distance[i-1];
        }
        sort( distance , distance + n + 2 );
        while( low <= high )
        {
            int sum = 0 , cnt = 0;
            mid = ( low + high )/2;
            for( int i = 1 ; i < n + 2 ; i++  )
            {
                if(( sum += distance[i] - distance[i - 1]) <= mid)
                    cnt++;
                else
                    sum = 0;
            }
            if( cnt <= m )
                low = mid + 1;
            else
                high = mid - 1;
        }
        printf( "%d\n" ,low);
        delete []distance;
    }
    return 0;
}
