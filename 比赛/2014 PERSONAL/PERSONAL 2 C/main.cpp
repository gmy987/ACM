#include <iostream>
#include <cstdio>

using namespace std;
int x[100],y[100];

int main()
{
    int t , n ;
    scanf("%d" , &t);
    for( int i = 1 ; i <= t ; i++ )
    {
        scanf("%d" , &n);
        for( int j = 0 ; j < n ; j++ )
            scanf("%d%d",&x[j],&y[j]);
    }
}
