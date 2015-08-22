#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 1005

using namespace std;
int set[MAXN],n,m;
void build( int n )
{
    for ( int i = 1 ; i <= n ; i++ )
        set[i] = i;
}
int find( int x )
{
    return set[x] == x ? x : set[x] = find(set[x]);
}
void unionSet( int x , int y )
{
    if(set[x] != set[y])
        set[find(y)] = find(x);
}
int main()
{
    while(~scanf("%d",&n))
    {
        if( n == 0 )
            break;
        scanf("%d",&m);
        build(n);
        int a , b ;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&a,&b);
            unionSet( a , b );
        }
        int cnt = 0;
        for( int i = 1 ; i <= n ; i++ )
            if( set[i] == i )
                cnt++;
        printf("%d\n",cnt-1);
    }
    return 0;
}

