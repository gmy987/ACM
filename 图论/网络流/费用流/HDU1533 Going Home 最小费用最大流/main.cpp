#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define MAXN 10100
#define MAXM 1000200
#define INF 0x7fffffff
using namespace std;

int sumFlow;
struct Node
{
    int x,y;
}h[300],m[300];
struct Edge
{
    int u,to,next,w,cap;//cap为流量
}edge[MAXN<<2];
int cnt;
int head[MAXN],dis[MAXN],pp[MAXN];
bool vis[MAXN];
char map[MAXN][MAXN];
void addEdge( int u , int v , int cap , int w)
{
    edge[cnt].u = u;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    edge[cnt].cap = cap;
    head[u] = cnt++;
    //cout<<head[u]<<endl;
}

bool spfa( int s , int t , int n )
{
    queue<int> q;
    memset( vis , 0 , sizeof(vis));
    memset( dis , 0x7f , sizeof(dis));
    //cout<<dis[0]<<endl;
    memset( pp , 0xff , sizeof(pp));
    dis[s] = 0 , vis[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to , w = edge[i].w;
            int cap = edge[i].cap;
            if( dis[v] > dis[u] + w && cap )
            {
                dis[v] = w + dis[u];
                pp[v] = i;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    if( dis[t] == 2139062143 )
        return false;
    return true;
}

int mcmf( int s , int t , int n)
{
    int flow = 0;//总流量
    int i,minflow,mincost = 0;
    while(spfa(s,t,n))
    {

        minflow = INF-1;
        for( i = pp[t] ; ~i ; i = pp[edge[i].u])
            if( edge[i].cap < minflow )
                minflow = edge[i].cap;
        flow += minflow;
        for( i = pp[t] ; ~i ; i = pp[edge[i].u])
        {
            edge[i].cap -= minflow;
            edge[i^1].cap += minflow;
        }
        mincost += dis[t]*minflow;
    }
    sumFlow = flow;
    return mincost;
}
int main()
{
    int n,M;
    while(~scanf("%d%d",&n,&M))
    {
        if( n == 0 && M == 0 ) break;
        memset( head , -1 , sizeof(head));
        cnt = 0;
        int i,j,ch = 0,cm = 0,temp;
        for( i = 0 ; i < n ; i++ )
        {
            scanf("%s",map[i]);
            for( j = 0 ; j < M ; j++ )
            {
                if( map[i][j] == 'H')
                {
                    h[ch].x = i;
                    h[ch++].y = j;
                }
                if( map[i][j] == 'm')
                {
                    m[cm].x = i;
                    m[cm++].y = j;
                }
            }
        }
        int S = 0 , T = 2 * ch + 1;
        for( i = 1 ; i <= cm ; i++ )
        {
            addEdge( 0 , i , 1 , 0 );
            addEdge( i , 0 , 0 , 0 );
            for( j = 1 ; j <= ch ; j++ )
            {
                temp = abs(h[i-1].x - m[j-1].x) + abs( h[i-1].y - m[j-1].y);
                addEdge( i , j + ch , 1 , temp );
                addEdge( j + ch , i , 0 , -temp );
            }
            addEdge( i + ch , T , 1 , 0 );
            addEdge( T , i + ch , 0 , 0 );
        }
        int ans = mcmf( S , T , T + 1 );//T+1为总的点数：0～T
        printf("%d\n",ans);
    }
    return 0;
}
