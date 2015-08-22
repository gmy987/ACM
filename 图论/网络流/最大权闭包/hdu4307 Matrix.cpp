#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXM 3000000
#define MAXN 2000
#define INF 0x7fffffff

using namespace std;

struct Edge{
    int to,next,cap;
}edge[MAXM];
int head[MAXN],dis[MAXN],S,T,cnt,t;
void addEdge( int u , int v ,int cap )
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
/*
bool bfs()
{
    memset( dis , 0xff , sizeof(dis));
    dis[S] = 0;
    queue<int> q;
    q.push(S);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , cap = edge[i].cap;
            if( dis[v] == -1 && cap)
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
    int a , i;
    for( i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap && ( a = dfs( v , min( cap , low ))))
        {
            edge[i].cap -= a;
            edge[i^1].cap += a;
            return a;
        }
    }
    return 0;
}
long long dinic()
{
    long long ans = 0;
    while(bfs())
        ans += dfs( S , INF);
    return ans;
}
*/
int gap[MAXN], cur[MAXN], pre[MAXN], aug[MAXN]; 
int SAP( int x , int s  , int t )
{
    int maxflow = 0 , mindis , u = s , id;
    memset( gap , 0 , sizeof(gap) );
    memset( dis , 0 , sizeof( dis));
    gap[s] = x ;
    aug[s] = INF;
    pre[s] = -1;
    for( int i = s ; i <= t ; i++ )
        cur[i] = head[i];
    while(dis[s] < x )
    {
        int flag = 0;
        if( u == t )
        {
            maxflow += aug[t];
            for( int v = pre[t] ; ~v ; v = pre[v])
            {
               id = cur[v];
               edge[id].cap -= aug[t];
               edge[id^1].cap += aug[t];
               aug[v] -= aug[t];
               if( edge[id].cap == 0  )
                   u = v;
            }
        }
        for( int i = cur[u] ; ~i ; i =  edge[i].next )
        {
            int v = edge[i].to , cap = edge[i].cap;
            if( cap && dis[u] == dis[v] + 1)
            {
                flag = 1;
                pre[v] = u;
                cur[u] = i;
                aug[v] = min( cap , aug[u]);
                u = v;
                break;
            }
        }
        if(!flag)
        {
            if( --gap[dis[u]] == 0 )
                break;
            cur[u] = head[u];
            mindis = x;
            for( int i = head[u] ; ~i ; i = edge[i].next )
            {
                int v = edge[i].to;
                if( edge[i].cap && dis[v] < mindis )
                {
                    mindis = dis[v];
                    cur[u] = i;
                }
            }
            dis[u] = mindis + 1;
            gap[dis[u]]++;
            if( u!= s)
                u = pre[u];
        }
    }
    
    return maxflow;
}
int main()
{
    scanf("%d",&t);
    int n;
    while(t--)
    {
        scanf("%d",&n);
        cnt = 0;
        memset( head , 0xff , sizeof(head));
        S = 0 , T = n+1;
        long long sum = 0;
        int a;
        for( int i = 1 ; i <= n ; i++)
        {
            int temp = 0;
            for( int j = 1 ; j <= n ; j++)
            {
                scanf("%d",&a);
                temp += a;
                addEdge( i , j , a );
            }
            sum += temp;
            addEdge( S , i , temp );
        }
        for( int i = 1 ; i <= n ; i++)
        {
            scanf("%d",&a);
            addEdge( i , T , a );
        }
        printf("%lld\n",sum-SAP( T+1 , S , T ));
    }
    return 0;
}
