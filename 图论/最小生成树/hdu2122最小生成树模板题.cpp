#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 3000
#define MAXM 20000

using namespace std;

int n,m;
int set[MAXN];
struct Edge
{
    int to,from,w;
}edge[MAXM];

void build( int n )
{
    for( int i = 0 ; i < n ; i++ )
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
    sort( edge , edge+m , cmp );
    int sum = 0 , i , j;
    build(n);
    for( i = 0 , j = 0 ; i < n-1 , j < m ; j++ )
    {
        if( find( edge[j].to ) != find( edge[j].from ) )
        {
            unionSet( edge[j].to , edge[j].from );
            sum += edge[j].w;
            i++;
        }
    }
    if( i != n-1 )
        return -1;
    return sum;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int cnt = 0;
        int a,b,c;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            edge[cnt].to = a;
            edge[cnt].from = b;
            edge[cnt++].w = c;
        }
        int ans = kruskal( n , m );
        if( ans == -1 )
            printf("impossible\n");
        else
            printf("%d\n",ans);
        printf("\n");
    }
    return 0;
}
