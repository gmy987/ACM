#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXM 10000
#define MAXN 500
#define INF 10000000
using namespace std;
struct Edge
{
    int to,next,cap;
}edge[MAXM];
int head[MAXN],dis[MAXN],cnt,n,S,T;
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
void addEdge( int u , int v , int cap )
{
    edge[cnt].to = v;
    edge[cnt].cap = cap;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].next = head[v];
    edge[cnt].cap = 0;
    head[v] = cnt++;
}
bool bfs()
{
    queue<int>q;
    memset(dis,0xff,sizeof(dis));
    q.push(S);
    dis[S] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u]; ~i ; i = edge[i].next )
        {
            int v =edge[i].to , cap = edge[i].cap;
            if( dis[v] == -1 && cap )
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
    if( x == T || low == 0 )
        return low ;
    int flow = 0 , a , i;
    for( i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap )
        {
            a = dfs( v , min(cap , low ));
            edge[i].cap -= a;
            edge[i^1].cap += a;
            flow += a;
            low -= a;
            if( low == 0 )
                break;
        }
    }
    return flow;
}
int dinic()
{
    int ans = 0 ;
    while(bfs())
        ans += dfs( S  , INF );
    return ans;
}
int main()
{
    while(~scanf("%d",&n))
    {
        int i,j,a,sum = 0 ;
        memset( head , 0xff , sizeof(head));
        cnt = 0;
        S = 0 , T = n*n+1;
        for( i = 1 ; i <= n ; i++ )
            for( j = 1 ; j <= n ; j++ )
            {
                scanf("%d",&a);
                sum += a;
                if((i+j)%2 == 1)
                    addEdge( S , (i-1)*n+j,a);
                else
                    addEdge((i-1)*n+j,T,a);
                for( int k = 0 ; k < 4 ; k++ )
                {
                    int x = i + dir[k][0] , y = j + dir[k][1];
                    if( x > 0 && y > 0 && x <= n && y <= n && (i+j)%2==1)
                        addEdge((i-1)*n+j,(x-1)*n+y,INF);
                }
            }
        printf("%d\n",sum - dinic());
    }
    return 0;
}
