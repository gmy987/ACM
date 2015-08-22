#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int a[2000];
void build( int n )
{
    for( int i = 1 ; i <= n ; i++ )
        a[i] = i;
}
int find( int x )
{
    return a[x] == x ? x : a[x] = find(a[x]);
}
void unionSet( int x , int y )
{
    if( a[x] != a[y] )
        a[find(y)] = find(x);
}
int n , m ;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        build(n);
        int c , b ;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&c,&b);
            unionSet( c , b );
        }
        int cnt = 0;
        for( int i = 1 ; i <= n ; i++ )
            if( a[i] != i )
                cnt++;
        printf("%d\n",n-cnt);
    }
    return 0;
}
