#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXM 40000
#define MAXN 105

using namespace std;
int n , set[MAXN];
int cnt;
int map[MAXN][MAXN];
struct Edge{
    int to , from , w ;
}edge[MAXM];
bool cmp ( Edge a , Edge b )
{
    return  a.w < b.w;
}
void addedge ( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].from = u;
    edge[cnt++].w = w;
}
void build ( int n )
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
    if( set[x] != set[y] )
        set[find(y)] = find(x);
}
int kruskal ( int n , int m )
{
    sort( edge , edge + m , cmp );
    int sum = edge[0].w , i , j;
    build(n);
    unionSet( edge[0].from , edge[0].to );
    for( i = 1 , j = 1 ; i < n-1 , j < m ; j++ )
    {
        if( find(edge[j].to) != find( edge[j].from ))
        {
            sum += edge[j].w;
            unionSet( edge[j].from , edge[j].to );
            i++;
        }
    }
    return sum;
}

int main()
{
    while(~scanf("%d",&n))
    {
        cnt = 0;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= n ; j++ )
               scanf("%d",&map[i][j]); 
        int k , a , b;
        scanf("%d",&k);
        for( int i = 0 ; i < k ; i++ )
        {
            scanf("%d%d",&a,&b);
            map[a][b] = map[b][a] = 0;
        }
        for( int i = 1 ; i <= n ; i++  )
            for( int j  =1 ; j <= n ; j++ )
                if( i != j )
                    addedge( i , j , map[i][j] );
        printf("%d\n",kruskal(n,cnt));
    }
    return 0;
}

