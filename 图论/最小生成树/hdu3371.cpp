#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 600
#define MAXM 30000

using namespace std;
int t,m,n,k;
int set[MAXN];
struct Edge{
    int to,from,w;
}edge[MAXM];
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
    sort( edge , edge + m , cmp );
    int sum = 0 , i , j;
    for( i = 0 , j = 0 ; i < m && j < n-1 ; i++ )
    {
        if( find( edge[i].to ) != find( edge[i].from ))
        {
            unionSet(edge[i].to,edge[i].from);
            sum += edge[i].w;
            j++;
        }
    }
    if( j != n-1 )
        return -1;
    return sum;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        int cnt = 0 , a , b , c;
        build(n);
        for( int i = 0 ; i < m ; i++ )
            scanf("%d%d%d",&edge[cnt].to,&edge[cnt].from,&edge[cnt++].w);
        for( int i = 0 ;  i < k ; i++ )
        {
            scanf("%d",&a);
            scanf("%d",&c);
            for( int j = 1 ; j < a ; j++ )
            {
                scanf("%d",&b);
                edge[cnt].to = c;
                edge[cnt].from = b;
                edge[cnt++].w = 0;
            }
        }
        printf("%d\n",kruskal(n,cnt));
    }
    return 0;
}
