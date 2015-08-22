/*

我们知道对于普通二分图来说，最大独立点集 + 最小点覆盖集 = 总点数，类似的，对于有权的二分图来说:
最大点权独立集 + 最小点权覆盖集 = 总点权和，
这个题很明显是要求 最大点权独立集 ，现在 总点权 已知，我们只要求出来 最小点权覆盖集 就好了
建图:
1，对矩阵中的点进行黑白着色（相邻的点颜色不同），从源点向黑色的点连一条边，权值为该黑色点的权值，
2，从白色的点向汇点连一条边，权值为该白色点的权值，
3，然后，对于每一对相邻的黑白点，从黑点向白点连一条边，权值为无穷大。
最后求最小割（最大流），即为最小点权覆盖集。
因为我们求出的最小割集一定是从那些相邻的黑白点之间的边（也就是不能用的边，因为相邻的数不能同时选）
中选出来的，且是最小代价，也就是说从方格中拿掉的数之和尽量小，那么剩下的数之和一定是最大的。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAXM 10000000
#define MAXN 3000
#define INF 0x7fffffff
using namespace std;
struct Edge
{
    int to,next,cap;
}edge[MAXM];
int head[MAXN],dis[MAXN],cnt,n,m,S,T;
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
void addEdge( int u , int v , int cap )
{
    edge[cnt].to = v ;
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
    q.push(S);
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
    if( x == T || low == 0 )
        return low;
    int flow = 0 , a , i;
    for( i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap )
        {
            a = dfs( v , min( cap , low ));
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
    int ans = 0;
    while(bfs())
        ans += dfs( 0 , INF );
    return ans;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( head , 0xff , sizeof(head));
        cnt = 0 , S = 0 , T = n*m + 1;
        int i,j,a,sum = 0;
        for( i = 1 ; i <= n ; i++ )
            for( j = 1 ; j <= m ; j++ )
            {
                scanf("%d",&a);
                sum += a;
                if( (i+j)%2 == 1){
                    addEdge( S , (i-1)*m+j , a );
                    for( int k = 0 ; k < 4 ; k++ )
                    {
                        int x = i + dir[k][0] , y = j + dir[k][1];
                        if( x > 0 && y > 0 && x <= n && y <= m && (i+j)%2 == 1)
                            addEdge( (i-1)*m+j , (x-1)*m+y , INF);
                    }
                }
                else
                    addEdge( (i-1)*m+j , T , a );

            }
        printf("%d\n",sum-dinic());
    }
}
