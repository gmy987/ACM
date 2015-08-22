#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

struct Edge
{
    int to,next,w;
}edge[125000];

int head[505],h[505],n,m,cnt;
bool vis[505];

void addEdge ( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}

struct cmp{
    bool operator()( int a , int b )
    {
        return h[a] > h[b];
    }
};

void Dijkstra()
{
    priority_queue<int,vector<int>,cmp> q;
    memset(vis,0,sizeof(vis));
    memset(h,0x7f,sizeof(h));
    h[1] = 0;
    q.push(1);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for ( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( !vis[v] && h[v] > w + h[u] )
            {
                h[v] = w + h[u];
                q.push(v);
            }
        }
    }
}
int find( int u , int v )
{
    for( int i = head[u] ; ~i ; i = edge[i].next )
    {
        if( edge[i].to == v )
            return edge[i].w;
    }
    return -1;
}

int main()
{
    int num = 1;
    while(~scanf("%d%d",&n,&m) && ( n || m))
    {
        int a,b,c;
        cnt = 1;
        memset( head , -1 , sizeof(head));
        if( n == 1 ){
            printf("System #%d\nThe last domino falls after 0.0 seconds, at key domino 1.\n\n",num++);
            continue;
        }
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge( a , b , c );
            addEdge( b , a , c );
        }
        int max1 = 0;
        double max2 = 0;
        int s = 1,t = 1,ss = 1;
        Dijkstra();
        for( int i = 1 ; i <= n ; i++ ){
            if( max1 < h[i])
            {
                max1 = h[i];
                ss = i;
            }
            for ( int j = 1 ; j <= n ; j++ )
            {
                int temp = find ( i , j );
                if( temp == -1 ) continue;
                else if( max2 < (double)(h[i] + h[j] + temp)/2 )
                {
                    max2 = (double)(h[i] + h[j] + temp)/2;
                    s = i,t = j;
                }
            }
        }
        printf("System #%d\n",num++);
        if( max2 > max1 )
            printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",max2,s,t);
        else
            printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n",(double)max1,ss);
    }
}
