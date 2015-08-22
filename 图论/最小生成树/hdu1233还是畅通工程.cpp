#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 200
#define MAXM 40000

using namespace std;

int n , m , set[MAXN];
struct Edge
{
    int to , from , w;
}edge[MAXM];
bool cmp( Edge a , Edge b )
{
    return a.w < b.w;
}

void build( int n )
{
    for( int i = 1 ; i <= n ; i++ )
        set[i] = i;
}
int find( int x )
{
    return set[x] == x ? x : set[x] = find(set[x]);
}

void unionSet( int x , int y )
{
    if( find(x) != find(y))
        set[find(y)] = find(x);
}
int kruskal( int n , int m )
{
    sort( edge , edge + m , cmp );
    int sum = 0 , i , j;
    build(n);
    for( i = 0 , j = 0 ; i < m , j < n-1 ; i++ )
    {
        if( find(edge[i].to ) != find( edge[i].from ))
        {
            sum += edge[i].w;
            unionSet( edge[i].to , edge[i].from );
            j++;
        }
    }
    return sum;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        m = n*(n-1)/2;
        int a,b,c;
        int cnt = 0;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            edge[cnt].to = a;
            edge[cnt].from = b;
            edge[cnt++].w = c;
        }
        printf("%d\n",kruskal( n , m ));
    }
    return 0;
}
