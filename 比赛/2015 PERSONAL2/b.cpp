#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 100005

using namespace std;
int set[MAXN];
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
    if( set[x] != set[y] ) 
        set[find(y)] = find(x);
}
int vis[MAXN];

int main()
{
    int t;
    int n,m;
    char str[5];
    int a,b;
    scanf("%d",&t);
    while(t--)
    {
        memset( vis , 0 , sizeof(vis) );
        scanf("%d%d",&n,&m);
        build(n);
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%s%d%d",str,&a,&b);
            if( str[0] == 'A')
            {
                if( n == 2 )
                    printf("In different gangs.\n");
                else if( find(a) == find(b) ) printf("In the same gang.\n");
                else if( find(a) == find(vis[b])) printf("In different gangs.\n");
                else printf("Not sure yet.\n");
            }
            else{
                if( vis[a] ) unionSet( vis[a] , b );
                if( vis[b] ) unionSet( vis[b] , a );
                vis[a] = b;
                vis[b] = a;
            }
        }
    }
    return 0;
}
