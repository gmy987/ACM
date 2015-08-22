#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 50100

using namespace std;
int a[MAXN];
int n , m;
void makeSet( int n )
{
    for( int i = 1 ; i <= n ; i++ )
         a[i] = i;
}

int find( int x )
{
    return a[x] == x ? x : a[x] = find(a[x]);
}

void unionSet( int x , int y )
{
    if(a[x] != a[y])
        a[find(y)] = find(x);
}

int main()
{
    int cas = 1;
    while(~scanf("%d%d",&n,&m)&&(n+m))
    {
        makeSet(n);
        int b , c;
        for( int i = 1 ; i <= m ; i++ )
        {
            scanf("%d%d",&b,&c);
            unionSet( b , c );
        }
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
            if(a[i] == i )
                ans++;
        printf("Case %d: %d\n",cas++,ans);
    }
}
