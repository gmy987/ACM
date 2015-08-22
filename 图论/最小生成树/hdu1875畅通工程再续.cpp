#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXM 10000
#define MAXN 150

using namespace std;
int t,n;
int set[MAXN];
struct Edge
{
    int to,from;
    double w;
}edge[MAXM];
struct Point
{
    int x , y;
}p[MAXN];
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
    double sum = 0 ;
    int  i , j;
    build(n);
    for( i = 0 , j = 0 ; i < m && j < n-1 ; i++ )
    {
        if( find( edge[i].to ) != find( edge[i].from ))
        {
            sum += edge[i].w;
            unionSet( edge[i].to , edge[i].from );
            j++;
        }
    }
    if( j == n-1 )
        return sum;
    return -1;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        double temp;
        int cnt = 0;
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d%d",&p[i].x,&p[i].y);
        for( int i = 1 ; i < n ; i++ )
            for( int j = i+1 ; j <= n ; j++ )
            {
                temp = sqrt((double)(p[i].x-p[j].x)*(p[i].x-p[j].x)+(double)(p[i].y-p[j].y)*(p[i].y-p[j].y));
                if( temp > 1000 || temp < 10 )
                    continue;
                edge[cnt].to = i;
                edge[cnt].from = j;
                edge[cnt++].w = temp;
            }
        double ans = kruskal( n , cnt );
        if( ans == -1 )
            printf("oh!\n");
        else
            printf("%.1lf\n",ans*100);
    }
    return 0;
}
