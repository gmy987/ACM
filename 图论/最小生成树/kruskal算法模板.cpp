#include <cstdio>
#include <cstring>
#include <algorinthm>
#include <iostream>
#define MAXM
#define MAXN

using namespace std;

struct Edge
{
    int from , to , w;
}edge[MAXM];

void addedge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].from = u;
    edge[cnt++].w = w;
}

bool cmp( edge a , edge b )
{
    return a.w < b.w;
}
int a[MAXN],cnt;
int n , m ;

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

int kruskal( int n , int m )//n为顶点个数，m为边数
{
    sort( edge , edge + m , cmp );
    makeSet(n);
    int i , j , sum = 0 ;
    for( i = 0 ， j = 0 ; j < n - 1 && i < m ; i++ )
        if( find(edge[i].from) != find(edge[i].to) )
        {
            unionSet( edge[i].from , edge[i].to );
            sum += edge[i].w;
            j++;
        }
    return sum;
}


