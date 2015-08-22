#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
struct Edge
{
    int to,cap,next;
}edge[2500000];
int dis[5000],n,f,d,N,cnt,head[5000];
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
    queue<int> q;
    memset( dis , 0xff , sizeof(dis));
    dis[0] = 0;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , cap = edge[i].cap;
            if( cap > 0 && dis[v] < 0 )
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[N] > 0;
}
int dfs( int x , int low )
{
    //cout<<"aaa"<<endl;
    if( x == N || low == 0 )
        return low;
    int flow = 0 , a;
    for( int i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( cap > 0 && dis[v] == dis[x] + 1 )
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
    int ans = 0 ;
    while(bfs())
        ans += dfs( 0 , INF );
    return ans;
}
int main()
{
    while(~scanf("%d%d%d",&n,&f,&d))
    {
        int i,j;
        N = n+n+f+d+1;
        cnt = 0;
        char a[205];
        memset( head , 0xff , sizeof(head));
        for( i = 1 ; i <= f ; i++)
        {
            scanf("%d",&j);
            addEdge( 0 , n + n + i , j);
        }
        for( i = 1 ; i <= d ; i++)
        {
            scanf("%d",&j);
            addEdge(n+n+f+i,N,j);
        }
        for( i = 1 ; i <= n ; i++)
        {
            scanf("%s",a);
            for( j = 0 ; j < f ; j++)
                if(a[j] == 'Y')
                    addEdge(n+n+j+1 , i , INF);
            addEdge( i , i + n , 1 );
        }
        for( i = 1 ; i <= n ; i++)
        {
            scanf("%s",a);
            for( j = 0 ; j < d ; j++)
                if(a[j] == 'Y')
                    addEdge( n+i , n+n+f+j+1 , INF );
        }
        printf("%d\n",dinic());
    }
    return 0;
}
