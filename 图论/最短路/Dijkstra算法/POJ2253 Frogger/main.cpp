#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
struct Edge{
    int to,next;
    double w;
}edge[80005];

struct Node{
    int x,y;
}node[500];

int head[500],n,cnt;
double h[500];
bool vis[500];
void addEdge( int u , int v , double w )
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

struct cmp{
    bool operator () ( int a , int b )
    {
        return h[a] > h[b];
    }
};

void Dijkstra()
{
    memset( h, 0x7f , sizeof(h));
    memset(vis , 0 , sizeof(vis));
    priority_queue<int,vector<int>,cmp> q;
    h[1] = 0;
    q.push(1);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        vis[u] = 1;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            double w = edge[i].w;
            if( h[v] > max( w , h[u] ) )
            {
                h[v] = max( w , h[u] );
                q.push(v);
            }
        }
    }
}
/*
void spfa()
{
    memset( h , 0x7f , sizeof(h));
    memset( vis,0 , sizeof(vis));
    queue<int> q;
    h[1] = 0;
    vis[1] = 1;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            double w = edge[i].w;
            if( h[v] > max(h[u],w) )
            {
                h[v] = max( h[u] , w );
                if( !vis[v] )
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}*/
int main()
{
    int c = 1;
    while(~scanf("%d",&n) && n)
    {
        memset( head , -1 , sizeof(head));
        cnt = 1;
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d%d",&node[i].x,&node[i].y);
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= n ; j++ )
                if( i != j )
                    addEdge( i , j , sqrt((double)((node[i].x - node[j].x)*(node[i].x - node[j].x) + (node[i].y - node[j].y)*(node[i].y - node[j].y))));
        Dijkstra();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",c++,h[2]);
    }
}
