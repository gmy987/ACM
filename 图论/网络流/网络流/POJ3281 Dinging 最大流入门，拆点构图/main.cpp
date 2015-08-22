//注意构图
//由于每头牛只能选一次，所以进行拆点操作，将牛的点拆成两个，它们之间连一条边
//相当于给牛的数量加上了限制。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int q[500],dis[500],tab[500][500],N,F,Q,M,h,r;

bool bfs()
{
    memset( q , 0 ,sizeof( q ));
    memset( dis , 0xff , sizeof(dis));
    h = 0,r = 1;
    dis[0] = 0,q[1] = 0;
    int i,j;
    while( h < r )
    {
        j = q[++h];
        for( i = 0 ; i<= M ; i++ )
            if( dis[i] < 0 && tab[j][i] > 0 )
            {
                dis[i] = dis[j] + 1;
                q[++r] = i;
            }
    }
    if( dis[M] > 0 )
        return true;
    else
        return false;
}

int dfs( int x , int low )
{
    int a,i;
    if( x == M )
        return low;
    for( i = 0 ; i <= M ; i++ )
        if( tab[x][i] > 0 && dis[i] == dis[x] + 1 &&
            (a = dfs( i , min( low , tab[x][i]))))
        {
            tab[x][i] -= a;
            tab[i][x] += a;
            return a;
        }
    return 0;
}

int dinic()
{
    int ans = 0,tans;
    while( bfs() )
    {
        while(tans = dfs(0,0x7fffffff))
            ans+=tans;
    }
    return ans;
}
int main()
{
    scanf("%d%d%d",&N,&F,&Q);

    int f,q,a,b,i,j;
    memset( tab , 0 , sizeof(tab));
    for( i = 1 ; i <= N ; i++ )
    {
        scanf("%d%d",&f,&q);
        for( j = 1 ; j <= f ; j++ )
        {
            scanf("%d",&a);
            tab[a+N+N][i] += 1;
        }
        for( j = 1 ; j <= q ; j++ )
        {
            scanf("%d",&b);
            tab[i+N][N+N+F+b] += 1;
        }
    }
    M = N + F + Q + N + 1;
    for( i = 1 ; i <= N ; i++ )
        tab[i][i+N] += 1;
    for( i = 1 ; i <= F ; i++ )
        tab[0][N+N+i] = 1;
    for( i = 1 ; i <= Q ; i++ )
        tab[N+N+F+i][M] = 1;
    printf("%d\n",dinic());
}
