#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 2000

using namespace std;

int set[MAXN];
int n,m;
int ans;
void build( int n )
{
    for( int i = 0 ; i < n ; i++ )
        set[i] = i;
}

int find(int x )
{
    return set[x] == x ? x : set[x] = find(set[x]);
}
void unionSet( int x , int y ) 
{
    if( find(x) == find(y) )
        ans++;
    else
        set[find(y)] = find(x);
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        ans = 0;
        build(n);
        int a,b;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&a,&b);
            unionSet( a , b );
        }
        printf("%d\n",ans);
    }
    return 0;
}
