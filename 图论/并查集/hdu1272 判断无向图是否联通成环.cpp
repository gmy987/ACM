#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstring>
#define MAX 100005

using namespace std;

int num[MAX+1],set[MAX+1];
bool flag;
bool vis[MAX+1];
void build( int n )
{
    for( int i = 1 ; i <= n ; i++ )
    {
        set[i] = i;
        num[i] = 1;
    }
}

int find( int x )
{
   return set[x] == x ? x : set[x] = find(set[x]);
}

void unionSet( int a , int b )
{
    int x = find(a) , y = find(b);
    if( x == y )
    {
        flag = false;
        return;
    }
    if( num[x] <= num[y] )
    {
        set[x] = y;
        num[y] += num[x];
    }
    else
    {
        set[y] = x;
        num[x] += y;
    }
}

int main()
{
    int a , b;
    while(~scanf("%d%d",&a,&b))
    {
        if( a == -1 && b == -1 )
            break;
        flag = true;
        if( a == 0 && b == 0 )
        {
            printf("Yes\n");
            continue;
        }
        memset( vis , 0 , sizeof(vis));
        build(MAX);
        unionSet( a , b );
        vis[a] = vis[b] = 1;
        while( scanf("%d%d",&a,&b))
        {
            if( a == 0 && b == 0 )
                break;
            unionSet( a , b );
            vis[a] = vis[b] = 1;
        }
        int cnt = 0;
        for( int i = 1 ; i <= MAX ; i++ )
            if( vis[i] && set[i] == i )
                cnt++;
        if( cnt > 1 )
            flag = false;
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
