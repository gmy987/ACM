//注意求起点和终点最大距离是，是较小id的点到较大id的点
//而不是单纯的1到n

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge
{
    int to,next,w;
}edge[3000000];

int h[10100],head[10100],c[10100],cnt,n,d;
bool vis[10100];
struct Node
{
    int height,id;
}node[10100];

void addEdge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
bool cmp ( Node a , Node b)
{
    return a.height < b.height;
}

bool spfa( int temp )
{
    memset(h , 0x7f,sizeof(h));
    memset( vis , 0 , sizeof(vis));
    memset( c , 0 , sizeof(c));
    h[temp] = 0;
    vis[temp] = 1;
    c[temp]++;
    queue<int> q;
    q.push(temp);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u]= 0;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] > w + h[u])
            {
                h[v] = w + h[u];
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push( v);
                }
                if(++c[v] > n)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    int t , num = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&d);
        memset( head ,  -1 , sizeof(head));
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&node[i].height);
            node[i].id = i;
        }
        sort ( node + 1 , node + 1 + n , cmp );

        for( int i = 2 ; i <= n ; i++ )
        {
            if( node[i].id > node[i-1].id)
                addEdge( node[i-1].id , node[i].id , d);
            else
                addEdge( node[i].id , node[i-1].id , d);
            //隐含条件s(i) - s(i-1) >= 1---> s(i-1) - s(i) <= -1
            addEdge( i , i - 1 , -1 );
        }
        printf("Case %d: ",num++);
        int temp = min( node[1].id , node[n].id);
        if(!spfa(temp))
            printf("-1\n");
        else
            printf("%d\n",h[max( node[1].id , node[n].id)]);
    }
    return 0;
}
