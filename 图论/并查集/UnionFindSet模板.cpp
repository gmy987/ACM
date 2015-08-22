#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int a[MAXN] , num[MAXN];
void makeSet(int n)
{
    for( int i = 0 ; i < n ; i++ )
    {
        a[i] = i;
        num[i] = 1;
    }
}

int find( int x )
{
    return a[x] == x ? x : a[x] = find(a[x]);
}

void unionSet( int ax , int bx )
{
    int x = find(ax), y = find(bx);
    if( x == y )
        return;
    if( num[x] <= num[y] )
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
------------------------------------------------------------
void makeSet( int n ) 
{
    for( int i = 0 ; i < n ; i++ )
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
