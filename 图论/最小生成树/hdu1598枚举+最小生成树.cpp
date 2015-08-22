#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 500
#define MAXM 2000
#define INF 0x7fffffff

using namespace std;
struct Edge{
    int to,from,w;
}edge[MAXM];
int n , m ,set[MAXN],q;
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
int kruskal( int n , int m , int u , int v )
{
    int ans = INF;
    for( int i = 0 ; i < m ; i++ )
    {
        build(n);
        for( int j = i ; j < m ; j++ )
        {
            unionSet( edge[j].to ,edge[j].from );
            if( find(u) == find(v) )
            {
                ans = min(ans,edge[j].w - edge[i].w);
                break;
            }
        }
    }
    return ans == INF ? -1 : ans ;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for( int i = 0 ; i < m ; i++ )
            scanf("%d%d%d",&edge[i].to,&edge[i].from , &edge[i].w);
        sort( edge , edge + m , cmp );
        scanf("%d",&q);
        int u , v;
        for( int i = 0 ; i < q ; i++ )
        {
            scanf("%d%d",&u,&v);
            printf("%d\n",kruskal(n,m,u,v));
        }
    }
    return 0;
}
