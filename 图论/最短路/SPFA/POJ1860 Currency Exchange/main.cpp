#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
    int to,next;
    double w,r,c;
}edge[3000];

int head[1050],m,n,s,cnt,c[1050];
bool vis[1050];
double v,h[1050];

void addEdge( int u , int v , double r, double c)
{
    edge[cnt].to = v;
    edge[cnt].w = 0;
    edge[cnt].next = head[u];
    edge[cnt].r = r;
    edge[cnt].c = c;
    head[u] = cnt++;
}
bool spfa()
{
    queue<int> q;
    memset( vis , 0 , sizeof(vis));
    memset( h , 0 , sizeof(h));
    q.push(s);
    vis[s] = 1;
    h[s] = v;
    while(!q.empty())
    {
        if(h[s] > v ) return false;
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int to = edge[i].to;
            edge[i].w = ( h[u] - edge[i].c ) * edge[i].r - h[u];
            if( h[to] < h[u] + edge[i].w )
            {
                h[to] = edge[i].w + h[u];
                if( !vis[to] )
                {
                    q.push(to);
                    vis[to] = 1;
                }
            }
        }
    }
    return true;
}

int main()
{
    while(~scanf("%d%d%d%lf",&n,&m,&s,&v))
    {
        cnt = 1;
        int a,b;
        memset( head , -1 , sizeof(head));
        double c,d,e,f;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
            addEdge ( a , b , c , d );
            addEdge ( b , a , e , f );
        }
        if( spfa() )
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
