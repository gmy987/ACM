#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#define INF 0x7fffffff
#define MAX 2139062143
using namespace std;
struct Edge
{
    int u , v , next , cap , w;
}edge[5000000];

int head[2000],h[2000],pp[2000],n,m,maxflow,mincost,cnt,in[2000],out[200];
bool vis[2000];

void addEdge( int u , int v , int cap , int w)
{
    edge[cnt].u = u , edge[cnt].v = v , edge[cnt].w = w;
    edge[cnt].cap = cap , edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].u = v , edge[cnt].v = u , edge[cnt].w = -w;
    edge[cnt].cap = 0 , edge[cnt].next = head[v];
    head[v] = cnt++;
}
bool spfa( int s , int t )
{
    queue<int> q;
    memset( h , 0x7f , sizeof(h));
    memset( vis , 0 , sizeof(vis));
    memset( pp , 0xff , sizeof(pp));
    h[s] = 0 ;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].v , w = edge[i].w , cap = edge[i].cap;
            if( h[v] > w + h[u] && cap > 0 )
            {
                h[v] = w + h[u];
                pp[v] = i;
                if( !vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return h[t] < MAX;
}

void mcmf( int s , int t )
{
    int i , minflow;
    maxflow = 0,mincost = 0;
    while( spfa( s , t ))
    {
        minflow = INF;
        for( i = pp[t] ; ~i ; i = pp[edge[i].u])
            minflow = min( minflow , edge[i].cap );
        maxflow += minflow;
        for( i = pp[t] ; ~i ; i = pp[edge[i].u])
        {
            edge[i].cap -= minflow;
            edge[i^1].cap += minflow;
        }
        mincost += h[t]*minflow;
    }
}
int main()
{
    int q , num = 1;//注意变量不要起重复的名字！！
    scanf("%d",&q);
    while(q--)
    {
        cnt = 0;
        int s,t;
        memset( head , 0xff , sizeof(head));
        memset( in , 0 , sizeof(in));
        memset( out , 0 , sizeof(out));
        scanf("%d %d %d %d",&n,&m,&s,&t);
        int u , v , a , b , i , sum = 0;//sum表示初始图的代价
        for( i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d%d",&u,&v,&a,&b);
            if( a <= b )//因为a<b,所以保留此边花费较小，所以默认此边保留，花费a，删除这条边的代价为b-a
            {
                addEdge( v , u , 1 , b - a );
                sum += a;
                out[u]++ , in[v]++;
            }
            else//b < a ,所以此边删除花费较小，因此删除此边，花费b，若要恢复，则代价为a-b
            {
                addEdge( u , v , 1 , a - b );
                sum += b;
            }

        }
        in[s]++,out[t]++;
        int S = 0 , T = n + 1;
        for( i = 1 ; i <= n ; i++ )
        {
            //因为此刻记录出入度的边流量都为0，因此，若出度大于入度，
            //代表此刻有流量不为零的边指向i，为可以使
            //其流入汇点，将此点与汇点连接
            if( out[i] > in[i] )
                addEdge( i , T , out[i] - in[i] , 0 );
            else if( in[i] > out[i] )
                addEdge( S , i , in[i] - out[i] , 0 );
        }
        bool flag = true;
        mcmf(S,T);
        for( i = head[S] ; ~i ; i = edge[i].next )
            if( edge[i].cap > 0 )
                flag = false;
        printf("Case %d: ",num++);
        if( !flag )
            printf("impossible\n");
        else
            printf("%d\n",sum+mincost);
    }
    return 0;
}
