#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 30100

using namespace std;
int n , m;
int a[MAXN],num[MAXN];
void makeSet( int n )
{
    for( int i = 0 ; i < n ; i++ )
    {
        num[i] = 1;
        a[i] = i;
    }
}

int find( int x )
{
    if( a[x] == x )
        return a[x];
    else
        return a[x] = find(a[x]);
}

void unionSet( int ax , int bx )
{
    int x=find(ax),y=find(bx);
    if( x == y )
        return;
    if( num[x] <= num[y])
    {
        a[x] = y;
        num[y] += num[x];
    }
    else
    {
        a[y] = x;
        num[x] += num[y];
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&(m+n))
    {
        makeSet(n);
        int cnt , b , c;
        for( int i = 1 ; i <= m ; i++ )
        {
            scanf("%d%d",&cnt ,&b);
            for( int j = 1 ; j < cnt ; j++ )
            {
                scanf("%d",&c);
                unionSet( b , c );
            }
        }
        printf("%d\n",num[find(0)]);
    }
    return 0;
}

