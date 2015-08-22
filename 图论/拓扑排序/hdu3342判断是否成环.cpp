#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
#define MAXN 200
#define MAXM 40000
using namespace std;

struct Edge{
    int to,next;
}edge[MAXM];
int head[MAXN],in[MAXN];
int n,m,cnt;
void addedge( int u , int v )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int topsort()
{
    queue<int> q;
    int num = 0;
    for( int i = 0 ; i < n ; i++ )
        if(!in[i])
        {
            q.push(i);
            num++;
        }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            if( --in[v] == 0 )
            {
                q.push(v);
                num++;
            }
        }
    }
    return num == n;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int a,b;
        cnt = 0;
        if( n == 0 )
            break;
        memset( head , 0xff , sizeof(head));
        memset( in , 0 , sizeof(in));
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&a,&b);
            addedge( b , a );
            in[a]++;
        }
        if( topsort() )
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
