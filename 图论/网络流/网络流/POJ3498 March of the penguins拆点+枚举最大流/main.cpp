#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define INF 10000000000
using namespace std;
int tab[220][220],q[220],h,r,n,N,T,mem[220],x[220],y[220],dis[220];
double d;

bool bfs()
{
    memset( q , 0 , sizeof(q));
    memset( dis , 0xff , sizeof(dis));
    int i,j;
    dis[0] = 0 , q[1] = 0;
    h = 0 , r = 1;
    while( h < r )
    {
        j = q[++h];
        for( i = 0 ; i <= N ; i++ )
            if( tab[j][i] > 0 && dis[i] < 0 )
            {
                dis[i] = dis[j] + 1;
                q[++r] = i;
            }
    }
    return dis[T] > 0;
}
int dfs( int x , int low )
{
    int a = 0 , i;
    if( x == T )
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
    while(bfs())
    {
        while( tans = dfs(0,0x7fffffff))
            ans += tans;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lf",&n,&d);
        int a,b,i,j,k,sum = 0,temp[220][220];
        memset( x , 0 , sizeof(x));
        memset( y , 0 , sizeof(y));
        memset( mem , 0 , sizeof(mem));
        memset( temp , 0 , sizeof(temp));
        memset( tab , 0 ,sizeof(tab));
        for( i = 1 ; i <= n ; i++ )
        {
            scanf("%d%d%d%d",&x[i],&y[i],&a,&b);
            temp[0][i] += a;
            temp[i][n+i] += b;
            sum += a;
        }
        d = d*d;
        for( i = 1 ; i < n ; i++ )
            for( j = i + 1 ; j <= n ; j++)
            {
                if( pow((double)x[i]-x[j],2)+pow((double)y[i]-y[j],2) <= d )
                {
                    temp[i+n][j] = INF;
                    temp[j+n][i] = INF;
                }
            }
        N = 2*n;
        for( i = 1 ; i <= n ; i++ )
        {
            T = i;
            for( j = 0 ; j <= N ; j++ )
                for( k = 0 ; k <= N ; k++)
                    tab[j][k] = temp[j][k];
            if(dinic()==sum)
                mem[i]++;
        }
        bool flag = false,c = 0;
        for( i = 1 ; i <= n ; i++ )
            if(mem[i])
            {
                flag = true;
                if( c == 0 ) printf("%d",i-1);
                else  printf(" %d",i-1);
                c++;
            }
        if(!flag) printf("-1");
        printf("\n");
    }
    return 0;
}
