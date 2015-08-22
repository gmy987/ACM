#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXM 150

using namespace std;
struct Edge{
    int a,b,w;
}edge[MAXM];
int set[100];

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
    {
        set[find(y)] = find(x);
    }
}
bool cmp( Edge c , Edge d )
{
    return c.w < d.w;
}
int kruskal( int m , int n  )
{
    sort(edge,edge+m,cmp);
    build(n);
    int sum = 0;
    for( int i = 0 , j = 0 ; i < m && j < n-1 ; i++ )
    {
        if( find(edge[i].a) != find(edge[i].b) )
        {
            unionSet( edge[i].a , edge[i].b ); 
            sum += edge[i].w;
            j++;
        }
    }
    return sum;
}

int main()
{
    int n,m;
    while(~scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        for( int i = 0 ; i < m ; i++ )
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].w);
        printf("%d\n",kruskal(m,n));
    }
}
