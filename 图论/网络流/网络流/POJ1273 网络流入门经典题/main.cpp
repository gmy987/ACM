#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 0x7fffffff

using namespace std;

int ans,n,m,q[250],dis[250],tab[250][250];
int h,r;
bool BFS()
{
    memset( dis , 0xff , sizeof(dis));
    memset( q , 0 , sizeof(q));
    dis[1] = 0;
    h = 0 , r = 1;
    q[1] = 1;
    int i,j;
    while( h < r )
    {
        j = q[++h];
        for( i = 1 ; i <= n ; i++ )
        {
            if( dis[i] < 0 && tab[j][i] > 0 )
            {
                dis[i] = dis[j] + 1;
                q[++r] = i;
            }
        }
    }
    if( dis[n] > 0 ) return true;
    else  return false;
}

int dinic( int x , int low )
{
    int a = 1 , i;
    if( x == n )
        return low;
    for( i = 1 ; i <= n ; i++ )
        if( tab[x][i] > 0 && dis[i] == dis[x] + 1
            && (a = dinic( i , min( low , tab[x][i]))))
        {
            tab[x][i] -= a;
            tab[i][x] += a;
            return a;
        }
    return 0;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        int a,b,c,i;
        memset( tab , 0 , sizeof(tab));
        for( i = 1 ; i <= m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            tab[a][b] += c;
        }
        ans = 0;
        int tans;
        while( BFS() )
        {
            if( tans = dinic( 1 , MAX ))
                ans += tans;
        }
        printf("%d\n",ans);
    }
}
