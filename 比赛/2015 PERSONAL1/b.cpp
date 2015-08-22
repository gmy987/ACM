#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXM 900
#define MAXN 30

using namespace std;
struct Edge{
    int to,from,w;
}edge[MAXM];
int set[MAXN];
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
    build(n);
    int sum = 0;
    for( int i = 0 , j = 0 ; i < m && j < n-1 ; i++ )
    {
        if( find(edge[i].to) != find(edge[i].from ))
        {
            sum+=edge[i].w;
            unionSet( edge[i].to , edge[i].from );
            j++;
        }
    }
    return sum;
}

int main()
{
    int n;
    char a,c;
    int b,d;
    int cnt;
    while(~scanf("%d",&n)&&n)
    {
        cnt = 0;
        for( int i = 1 ; i < n ; i++ )
        {
            cin>>a>>b;
            for( int k = 0 ; k < b ; k++ )
            {
                cin>>c>>d;
                edge[cnt].to = c-'A';
                edge[cnt].from = a-'A';
                edge[cnt++].w = d; 
            }
        }
        printf("%d\n",kruskal(n,cnt));
    }
    return 0;
}





