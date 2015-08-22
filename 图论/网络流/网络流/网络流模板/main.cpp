
----------------------------------------------------------
/*邻接矩阵模板*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

int tab[250][250];//邻接矩阵
int dis[250];//距源点距离，分层图
int q[2000],h,r;//BFS队列，首，尾
int N,M,ANS;//N点数，M边数，ANS答案
int BFS()
{
    int i,j;
    memset( dis , 0xff , sizeof(dis));//以-1填充
    dis[1] = 0;
    h = 0 ;
    r = 1;
    q[1] = 1;
    while( h < r )
    {
        j = q[++h];
        for( i = 1 ; i <= N ; i++ )
            if( dis[i] < 0 && tab[j][i]>0)
            {
                dis[i] = dis[j] + 1;
                q[++r] = i;
            }
    }
    if( dis[N] > 0 )
        return 1;
    else
        return 0;//汇点的dis小于零，表明BFS不到汇点
}

//dinic代表一次增广，函数返回本次增广的流量，返回零表示无法增广
int dfs( int x , int low )//low是源点到现在最窄的（剩余流量最小）的边的剩余量
{
    int i , a = 0;
    if( x == N )
        return low;
    for( i = 1 ; i <= N ; i++ )
        if( tab[x][i] > 0   //联通
            && dis[i] == dis[x] + 1 //是分层图的下一层
            &&(a = dfs(i,min(low,tab[x][i]))))//能到汇点
        {
            tab[x][i] -= a;
            tab[i][x] += a;
            return a;
        }
    return 0;
}

int dinic()
{
    int tans ,ans = 0;
    while( BFS() )//不停地建立分层图，如果BFS不到汇点才结束
    {
        while( tans = dfs( 1 , 0x7fffffff))//一次BFS要不停地寻找增广路
            ans += tans;                   //直到找不到为止
    }
    return ans;
}
int main()
{
    int i,j,f,t,flow;
    while(~scanf("%d%d",&M,&N))
    {
        memset( tab , 0 , sizeof(tab));
        for( i = 1 ; i <= M ; i++ )
        {
            scanf("%d%d%d",&f,&t,&flow);
            tab[f][t] += flow;
        }

        ANS = dinic();
        printf("%d\n",ANS);
    }
    return 0;
}
--------------------------------------------------------------------
/*邻接表模板*/
struct Edge
{
    int to,next,cap;
}edge[MAXM];
int head[MAXN],dis[MAXN],cnt,

void addEdge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].cap = w;
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
    queue<int> q;
    dis[S] = 0;
    q.push(S);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , cap = edge[i].cap;
            if( dis[v] < 0 && cap > 0)
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
    if( x == T || low == 0)
        return low;
    int flow = 0 , a;
    for( int i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap > 0)
        {
            a = dfs( v , min( low , cap ));
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
    while( bfs() )
        ans += dfs( S , 0x7fffffff );
    return ans;
}




















