#include <cstdio>
#include <cstring>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 10000000

using namespace std;
int set[MAX+1],num[MAX+1];
void build( int n )
{
    for( int i = 1 ; i <= n ; i++ )
    {
        set[i] = i;
        num[i] = 1;
    }
}
int find( int x )
{
    return set[x] == x ? x : set[x] = find(set[x]);
}
void unionSet(int x ,int y )
{
    int a = find(x),b = find(y);
    if( a == b )
        return;
    if( num[a] <= num[b])
    {
        set[a] = b;
        num[b] += num[a];
    }
    else
    {
        set[b] = a;
        num[a] += num[b];
    }
}

int main()
{
    int m;
    while(~scanf("%d",&m))
    {
        int a,b;
        int ans = -1;
        build(MAX);
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&a,&b);
            unionSet( a , b );
        }
        for( int i = 1 ; i <= MAX ; i++  )
            ans = max( ans , num[i] );
        printf("%d\n",ans);
    }
    return 0;
}
