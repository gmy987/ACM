#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXM 9000010000
#define MAXN 30100

using namespace std;

struct Edge{
    int to , from , w;
}edge[MAXM];
int a[MAXN],n,m,cnt;
void addedge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].from = u;
    edge[cnt++].w = w;
}

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
bool cmp( Edge a , Edge b )
{
    return a.w < b.w;
}
int kruskal( int n , int m )
{
    sort( edge , edge + m , cmp );
    int i , j = 1 , sum = edge[0].w ;
    makeSet(n);
    unionSet( edge[0].from , edge[0].to );
    for( i = 1 ; j < n - 1 && i < m ; i++ )
    {
        if( find(edge[i].from) != find(edge[i].to) )
        {
            unionSet( edge[i].from , edge[i].to );
            sum += edge[i].w;
            ++j;
        }
    }
    return sum;
}

int main()
{
    while(~scanf("%d",&n))
    {
        int a;
        cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
            {
                scanf("%d",&a);
                if(a) addedge( i , j , a );
            }
        printf("%d\n",kruskal(n,cnt));
    }
    return 0;
}
