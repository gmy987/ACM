//K短路问题
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

struct cmp
{
    bool operator() ( const int a , const int b )
    {
        return h[a]>h[b];
    }
};

void Dijkstra()
{
    memset(h,0x7f,sizeof(h));
    memset(vis,0,sizeof(vis));
    priority_queue<int,vector<int>,cmp> q;
    h[t] = 0;
    q.push(t);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for( int i = tail[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            if(!vis[v] && h[v] > h[u] + edge[i].w)
            {
                h[v] = h[u] + edge[i].w;
                q.push(v);
            }
        }
    }
}


void addEdge( int u , int v , int w , int cnt )
{
    int i = cnt<<1,j = cnt<<1|1;
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
