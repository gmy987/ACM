/*
设v[i]代表第i项工作持续时间，s[i]代表第i项工作开始时间，则s[i]+v[i]代表第i项工作结束时间
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
struct Edge
{
    int to,next,w;
}edge[10000000];
int h[100000],head[100000],c[100000],cnt,n,v[100000];
bool vis[100000];
void addEdge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool spfa()
{
    memset( h , -1 , sizeof( h ));
    memset( vis , 0 , sizeof( vis ));
    memset( c , 0 , sizeof(c));

    queue<int> q;
    q.push(0);
    vis[0] = 1;
    h[0] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] < w + h[u] )
            {
                h[v] = w + h[u];
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
                if( ++c[v] > n )
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int num = 1;
    while(~scanf("%d",&n)&&n)
    {
        cnt = 1;
        memset( head , -1 , sizeof(head));
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d",&v[i]);
        char op[5];
        while(true){
            scanf("%s",op);
            if( op[0] == '#' ) break;
            int a , b;
            scanf("%d%d",&a,&b);
            if( op[0] == 'F' )
            {
                if( op[2] == 'S' )
                    addEdge( b , a , -v[a] );
                else
                    addEdge( b , a , v[b] - v[a]);
            }
            else
            {
                if(op[2] == 'F')
                    addEdge( b , a , v[b]);
                else
                    addEdge( b , a , 0);
            }
        }
        printf("Case %d:\n",num++);
        //加入超级源点
        for( int i = 1 ; i <= n ; i++ )
            addEdge( 0 , i , 0);
        if(!spfa())
                printf("Impossible\n");
        else
        {
            for( int i = 1 ; i <= n ; i++ )
            {
                printf("%d %d\n",i,h[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
