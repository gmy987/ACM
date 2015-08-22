#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 1005
#define maxm 200005
using namespace std;
int n,m,s,t,k;
struct Edge
{
    int to,next,w;
}edge[maxm];

int h[maxn],head[maxn],tail[maxn],cnt[maxn];
bool vis[maxn];

struct Node
{
    int s,h,g;
    bool operator < ( Node a ) const
    {
        return h + g > a.h + a.g;
    }
};

void Dijkstra()
{
    memset( h , 0x7f , sizeof(h));
    memset( vis , 0 ,sizeof(vis));
    int k,i,j;
    h[t] = 0;
    for( i = 1 ; i <= n ;i++ )
    {
        k = 0;
        for( j = 1 ; j <= n ; j++ )
            if( !vis[j] && ( !k || h[j]<h[k]))
                k = j;
        if(!k) break;
        vis[k] = 1;
        for( j = tail[k] ; ~j ; j = edge[j].next )
        {
            int v = edge[j].to;
            h[v] = min( h[v] , h[k] + edge[j].w );
        }
    }
}

void addEdge( int u , int v , int w , int cnt )
{
    int i = cnt<<1,j = cnt<<1|1;
    //cout<<"i : "<<i <<" j: "<<j<<endl;
    edge[i].to = v;
    edge[i].w = w;
    edge[i].next = head[u];
    head[u] = i;

    edge[j].to = u;
    edge[j].w = w;
    edge[j].next = tail[v];
    tail[v] = j;
}

int A_star()
{
    memset( cnt , 0 , sizeof(cnt) );
    Node u;
    u.s = s,u.h = h[s],u.g = 0;
    priority_queue<Node> q;
    q.push(u);
    while(!q.empty())
    {
        u = q.top();
        q.pop();
        Node v;
        cnt[u.s]++;
        if( cnt[u.s] > k ) continue;
        if( cnt[t] == k )
            return u.g;
        for( int i = head[u.s] ; ~i ; i = edge[i].next )
        {
            v.s = edge[i].to;
            v.g = u.g + edge[i].w;
            v.h = h[edge[i].to];
            q.push(v);
        }
    }
    return -1;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( edge , 0 , sizeof( edge ));
        memset( head , -1 , sizeof(head));
        memset( tail , -1 , sizeof(tail));
        int a,b,c;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c,i);
        }
        scanf("%d%d%d",&s,&t,&k);
        if(s==t) k++;
        Dijkstra();
        printf("%d\n",A_star());
    }
    return 0;
}
