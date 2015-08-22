#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 0x7fffffff
#define MAXM 1000000
#define MAXN 6000
using namespace std;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
struct Edge
{
    int to,next,cap;
}edge[MAXM];
int head[MAXN],cnt,dis[MAXN],n,m,T,G,S,board1[60][60],board2[60][60];
void addEdge( int u , int v , int cap )
{
    edge[cnt].to = v;
    edge[cnt].cap = cap;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].cap = 0;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
bool bfs()
{
    memset( dis , 0xff , sizeof(dis));
    queue<int>q;
    q.push(0);
    dis[0] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , cap = edge[i].cap;
            if( dis[v] < 0 && cap )
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[T] > 0;
}

int dfs( int x , int low )
{
    if( x == T )
        return low;
    int i , a;
    for( i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap > 0 && ( a = dfs(v,min(cap,low))))
        {
            edge[i].cap -= a;
            edge[i^1].cap += a;
            return a;
        }
    }
    dis[x] = -1;///此句话很关键，不再TLE!!!
    return 0;
}
int dinic()
{
    int ans = 0 , tans ;
    while(bfs())
        while( tans = dfs( 0 , INF ))
            ans += tans;
    return ans;
}
int main()
{
    int t,num = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&G,&S);
        int i , j , k , temp , tp = n*m , sum = 0 ,ax , ay , cnt = 0;
        T = 2*tp+1;
        memset( head , 0xff , sizeof(head));
        for( i = 1 ; i <= n ; i++ )
            for( j = 1 ; j <= m ; j++ ){
                scanf("%d",&board1[i][j]);
                sum+=board1[i][j];
            }
        for( i = 1 ; i <= n ; i++ )
            for( j = 1 ; j <= m ; j++ ){
                scanf("%d",&board2[i][j]);
                sum+=board2[i][j];
            }
        for( i = 1 ; i <= n ; i++ )
        {
            for( j = 1 ; j <= m ; j++ )
            {
                temp = (i-1)*m+j;
                if( (i+j)%2 == 0 )
                {
                    addEdge( 0 , temp , board1[i][j]);
                    addEdge( temp + tp , T , board2[i][j]);
                    addEdge( temp , temp + tp , INF );
                    for( k = 0 ; k < 4 ; k++ )
                    {
                        ax = i + dir[k][0] , ay = j + dir[k][1];
                        if( ax > 0 && ax <= n && ay > 0 && ay <= m )
                            addEdge( temp , (ax-1)*m+ay , G );
                            //tab[temp][(ax-1)*m+ay] += G;
                    }
                }
                else
                {
                    addEdge( 0 , temp+tp , board2[i][j]);
                    addEdge( temp , T , board1[i][j]);
                    addEdge( temp + tp , temp , INF );
                    //tab[0][temp+tp] += board2[i][j];
                    //tab[temp][T] += board1[i][j];
                    //tab[temp+tp][temp] = INF;
                    for( k = 0 ; k < 4 ; k++ )
                    {
                        ax = i + dir[k][0] , ay = j + dir[k][1];
                        if( ax > 0 && ax <= n && ay > 0 && ay <= m )
                            addEdge( temp + tp , (ax-1)*m+ay+tp , S );
                            //tab[temp][(ax-1)*m+ay+tp] += S;
                    }
                }
            }
        }
        printf("Case %d: %d\n",num++,sum-dinic());
    }
    return 0;
}
