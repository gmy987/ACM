//建立超级源点和超级汇点
//将所有发电站和超级源点相连和所有消耗点和超级汇点相连
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int q[150],dis[150],tab[150][150],n,np,nc,m,N,h,r;

bool BFS()
{
    memset( q , 0 , sizeof(q));
    memset( dis , 0xff , sizeof(dis));
    int i,j;
    dis[0] = 0;
    h = 0 , r = 1;
    q[1] = 0;
    while( h < r )
    {
        j = q[++h];
        for( i = 0 ; i <= N ; i++ )
            if( dis[i] < 0 && tab[j][i] )
            {
                dis[i] = dis[j] + 1;
                q[++r] = i;
            }
    }
    if( dis[N] > 0 )
        return true;
    else
        return false;
}

int dfs( int x , int low )
{
    int a = 0 , i;
    if( x == N )
        return low;
    for( i = 0 ; i <= N ; i++ )
        if( tab[x][i] > 0 && dis[i] == dis[x] + 1
            && ( a = dfs( i , min( low , tab[x][i]))))
        {
            tab[x][i] -= a;
            tab[i][x] += a;
            return a;
        }
    return 0;
}

int dinic()
{
    int ans = 0 , tans;
    while(BFS())
    {
        while(tans = dfs( 0 , 0x7fffffff))
            ans += tans;
    }
    return ans;
}
int main()
{
    while(~scanf("%d%d%d%d",&n,&np,&nc,&m))
    {
        memset( tab , 0 , sizeof(tab));
        int i,u,v,w;
        for( i = 0 ; i < m ; i++)
        {
            scanf(" (%d,%d)%d",&u,&v,&w);
            tab[u+1][v+1]+=w;
        }
        for( i = 0 ; i < np ; i++)
        {
            scanf(" (%d)%d",&v,&w);
            tab[0][v+1] += w;
        }
        for( i = 0 ; i < nc ; i++ )
        {
            scanf(" (%d)%d",&u,&w);
            tab[u+1][n+1] += w;
        }
        N = n + 1;
        printf("%d\n",dinic());
    }
    return 0;
}
*/



#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int q[150],tab[150][150],dis[150],n,np,nc,m,N,h,r;

bool bfs()
{
    memset( dis , 0xff ,sizeof(dis));
    memset( q , 0 , sizeof(q));
    int i,j;
    h = 0 , r = 1;
    dis[0] = 0;
    q[1] = 0;
    while( h < r )
    {
        j = q[++h];
        for( i = 0 ; i <= N ; i++ )
        {
            if( dis[i] < 0 && tab[j][i] > 0 )
            {
                dis[i] = dis[j] + 1;
                q[++r] = i;
            }
        }
    }
    if( dis[N] > 0 )
        return true;
    else
        return false;
}

int dfs( int x , int low )
{
    int a = 0 , i ;
    if( x == N )
        return low;
    for( i = 0 ; i <= N ; i++ )
        if( tab[x][i] > 0 && dis[i] == dis[x] + 1 && ( a = dfs( i , min( low , tab[x][i]))))
        {
            tab[x][i] -= a;
            tab[i][x] += a;
            return a;
        }
    return 0;
}

int dinic()
{
    int ans = 0 , tans;
    while( bfs() )
    {
        while( tans = dfs( 0 , 0x7fffffff ))
            ans += tans;
    }
    return ans;
}


int main()
{
    while(~scanf("%d%d%d%d",&n,&np,&nc,&m))
    {
        memset( tab , 0 , sizeof(tab));
        char temp[30];
        int i,a,b,c;
        for( i = 0 ; i < m ; i++ )
        {
            scanf("%s",temp);
            sscanf(temp,"(%d,%d)%d",&a,&b,&c);
            //cout << a << " " << b << " " << c << endl;
            tab[a+1][b+1] += c;
        }
        for( i = 0 ; i < np ; i++ )
        {
            scanf("%s",temp);
            sscanf(temp,"(%d)%d",&b,&c);
            tab[0][b+1] += c;
        }
        for( i = 0 ; i < nc ; i++ )
        {
            scanf("%s",temp);
            sscanf(temp,"(%d)%d",&a,&c);
            tab[a+1][n+1] += c;
        }
        N = n + 1;
        printf("%d\n",dinic());
    }
}






































