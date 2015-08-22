#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 150
#define MAXM 10000

using namespace std;
int n,set[MAXN];
struct Edge
{
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
    int sum = 0 , i , j ;
    build(n);
    for( i = 0 , j = 0 ; i < m && j < n-1 ; i++ )
    {
        if( find( edge[i].to ) != find(edge[i].from ))
        {
            unionSet( edge[i].to , edge[i].from );
            sum += edge[i].w;
            j++;
        }    
    }
    return sum;
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        int cnt = 0 , a , b , c , d;
        int m = n*(n-1)/2; 
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            edge[cnt].to = a;
            edge[cnt].from = b;
            if(!d)
                edge[cnt++].w = c;
            else
                edge[cnt++].w = 0;
        }
        printf("%d\n",kruskal(n,cnt));
    }
    return 0;
}

