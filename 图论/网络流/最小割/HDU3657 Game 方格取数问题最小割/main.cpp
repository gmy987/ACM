#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define MAXM 10000000
#define MAXN 10000
#define INF 0x7fffffff
using namespace std;

struct Edge
{
    int to , next , cap;
}edge[MAXM];

int head[MAXN],dis[MAXN],cnt,n,m,k,T,board[55][55];
bool vis[55][55];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void addedge( int u , int v , int cap )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u] ;
    edge[cnt].cap = cap;
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].cap = 0;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
/*
bool bfs()
{
    memset( dis , 0xff , sizeof(dis));
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , cap = edge[i].cap;
            if( cap && dis[v] < 0 )
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
    int a , i ;
    for( i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap && ( a = dfs(v , min( low , cap ))))
        {
            edge[i].cap -= a;
            edge[i^1].cap += a;
            return a;
        }
    }
    dis[x] = -1;
    return 0;
}

int dinic()
{
    int ans = 0;
    while(bfs())
        ans += dfs(0,INF);
    return ans;
}*/
int gap[MAXN],cur[MAXN],aug[MAXN],pre[MAXN];
int sap( int x )
{
    int maxflow = 0 , u = 0 , v;
    int id , mindis;
    aug[0] = INF;
    pre[0] = -1;
    memset( dis , 0 , sizeof(dis));
    memset( gap , 0 , sizeof(gap));
    gap[0] = x;
    for( int i = 0 ; i <= n ; i++ )
        cur[i] = head[i];
    while(dis[0] < x )
    {
        int flag = 0;
        if( u == T )
        {
            maxflow += aug[T];
            for( v = pre[T] ; ~v ; v = pre[v])
            {
                id = cur[v];
                edge[id].cap -= aug[T];
                edge[id^1].cap += aug[T];
                aug[v] -= aug[T];
                if( edge[id].cap == 0)
                    u = v;
            }
        }
        for( int i = cur[u] ; ~i ; i = edge[i].next )
        {
            v = edge[i].to;
            if( edge[i].cap > 0 && dis[u] == dis[v] + 1)
            {
                flag = 1;
                pre[v] = u;
                cur[u] = i;
                aug[v] = min( aug[u] , edge[i].cap );
                u = v;
                break;
            }
        }
        if( !flag )
        {
            if(--gap[dis[u]] == 0 )
                break;
            mindis = x;
            cur[u] = head[u];
            for( int i = head[u] ; ~i ; i = edge[i].next )
            {
                v = edge[i].to;
                if( edge[i].cap > 0 && dis[v] < mindis )
                {
                    mindis = dis[v];
                    cur[u] = i;
                }
            }
            dis[u] = mindis+1;
            gap[dis[u]]++;
            if( u != 0 )
                u = pre[u];
        }
    }
    return maxflow;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        cnt = 0;
        memset( head , 0xff , sizeof(head));
        //memset( vis , 0 , sizeof(vis));
        int i , j , a , b , temp , x , y , sum = 0;
        T = n*m+1;
        for( i = 1 ; i<= n ; i++ )
            for( j = 1 ; j <= m ; j++ ){
                scanf("%d",&board[i][j]);
                sum += board[i][j];
        }
        for( int i = 1 ; i <= k ; i++ )
        {
            scanf("%d%d",&a,&b);
            temp = (a-1)*m+b;
            if( (a+b)%2 == 0 )
                addedge( 0 , temp , INF );
            else
                addedge( temp , T , INF );
        }
        for( i = 1 ; i <= n ; i++ )
            for( j = 1 ; j <= m ; j++ )
            {
                temp = (i-1)*m+j;
                if( (i+j)%2 == 1 )
                    addedge( temp , T , board[i][j]);
                else{
                    addedge( 0 , temp , board[i][j]);
                    for( a = 0 ; a < 4 ; a++)
                    {
                        x = i + dir[a][0] , y = j + dir[a][1];
                        if( x >= 1 && y >= 1 && x <= n && y <= m )
                            addedge( temp , (x-1)*m+y , 2*(board[i][j]&board[x][y]));
                    }
                }
            }
        printf("%d\n",sum-sap( T + 1 ));
    }
    return 0;
}
