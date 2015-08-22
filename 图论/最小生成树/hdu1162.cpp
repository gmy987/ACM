#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 150
#define MAXM 15000

using namespace std;
struct Point{
    double x ,  y;
}p[MAXN];
struct Edge{
    int to,from;
    double w;
}edge[MAXM];
int n;
int set[MAXN];
double dis( int i , int j )
{
    return sqrt((double)(p[i].x-p[j].x)*(p[i].x-p[j].x)+(double)(p[i].y-p[j].y)*(p[i].y-p[j].y));
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
    if( find(x) != find(y) )
        set[find(y)] = find(x);
}
bool cmp( Edge a , Edge b )
{
    return a.w < b.w;
}
double kruskal( int n , int m )
{
    sort( edge , edge + m , cmp );
    build(n);
    double sum = 0;
    int i , j;
    for( i = 0 , j = 0 ; i < m && j < n-1 ; i++ )
    {
        if( find( edge[i].to ) != find( edge[i].from ) )
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
    while(~scanf("%d",&n))
    {
        int cnt = 0;
        for( int i = 1 ; i <= n ; i++ )
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for( int i = 1 ; i < n ; i++ )
            for( int j = i + 1 ; j <= n ; j++ )
            {
                edge[cnt].to = i;
                edge[cnt].from = j;
                edge[cnt++].w = dis(i,j);
            }
        printf("%.2lf\n",kruskal(n,cnt));
    }
    return 0;
}
