#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 100000

using namespace std;
int in[MAX+1];
int set[MAX+1];
bool vis[MAX+1];
bool flag;
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
    else
        flag = false;
}

int main()
{
    int cas = 1;
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        if( a < 0 && b < 0 )
            break;
        if( a == 0 && b == 0 )
        {
            printf("Case %d is a tree.\n",cas++);
            continue;
        }
        memset( in , 0 , sizeof(in) );
        memset( vis , 0 , sizeof(vis) );
        flag = true;
        if( a == b )
            flag = false;
        build(MAX);
        in[b]++;
        unionSet( a , b );
        vis[a] = vis[b] = 1;

        while(~scanf("%d%d",&a,&b))
        {
            if( a == 0 && b == 0 )
                break;
            if( a ==b )
                flag = false;
            vis[a] = vis[b] = 1;
            in[b]++;
            unionSet( a , b );
        }
        int cnt = 0;
        for( int i = 1 ; i <= MAX ; i++ )
        {
            if( vis[i] && set[i] == i )
                cnt++;
            if( in[i] > 1 )
                flag = false;
        }
        if( cnt > 1 )
            flag = false;
        if( flag )
            printf("Case %d is a tree.\n",cas++);
        else
            printf("Case %d is not a tree.\n",cas++);
    }
    return 0;

}
