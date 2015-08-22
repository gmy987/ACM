#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define MAXM 20000

using namespace std;
int n,m;
struct Edge
{
    int to , from , w;
}edge[MAXM];
int set[MAXN];
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
    if( find(x) != find(y) )
        set[find(y)] = find(x);
}
bool cmp( Edge a , Edge b )
{
    return a.w < b.w;
}

int kruskal( int n , int m )
{
    sort( edge, edge + m , cmp );
    int sum = 0 , i , j;
    build(n);
    for( i = 0 , j = 0 ; i < m && j < n-1 ; i++ )
    {
        if( find( edge[i].to ) != find( edge[i].from ) )
        {
            sum += edge[i].w;
            unionSet( edge[i].to , edge[i].from );
            j++;
        }
    }
    if( j != n-1 )
        return -1;
    return sum;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        if( m == 0 )
            break;
        int cnt = 0 , a,b,c;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            edge[cnt].to = a;
            edge[cnt].from = b;
            edge[cnt++].w = c;
        }
        int ans = kruskal( n , m );
        if( ans == -1 )
            printf("?\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
