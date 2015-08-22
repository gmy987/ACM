#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 10005
#define MAXM 20005
#include <queue>

using namespace std;

int n,m;
int in[MAXN];
int path[MAXN];
struct Edge{
    int to,next;
}edge[MAXM];
int head[MAXN];
int cnt;
void addedge( int u , int v )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int topsort()
{
    int sum = 0;
    queue<int> q;
    for( int i = 1 ; i <= n ; i++ )
        if( !in[i] )
        {
            sum++;
            path[i] = 0;
            q.push(i);
        }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        int temp = path[u];
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to;
            if( --in[v] == 0 )
            {
                path[v] = temp + 1;
                q.push(v);
                sum++;
            }
        }
    }
    return sum == n;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( in , 0 , sizeof(in) );
        memset( path , 0 , sizeof(path) );
        memset( head , 0xff , sizeof(head) );
        int a,b;
        cnt = 0;
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&b,&a);
            addedge( a , b );
            in[b]++;
        }
        int ans = topsort();
        if(!ans)
            printf("-1\n");
        else{
            int total = 0;
            total += n*888;
            for( int i = 1 ; i <= n ; i++ )
                total += path[i];
            printf("%d\n",total);
        }
    }
    return 0;
}
