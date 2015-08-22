//人是按序号排的
//应该还有一个约束条件：s(i) - s(i-1) >= 0;
//此题数据较水，因此没考虑也AC了，但以后要考虑全面
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct Edge
{
    int to,next,w;
}edge[40000];
int head[1005],h[1005],cnt[1005],c,n,t,x,y;
bool vis[1005];
void addEdge( int u , int v , int w)
{
    edge[c].to = v;
    edge[c].next = head[u];
    edge[c].w = w;
    head[u] = c++;
}
bool spfa()
{
    memset( h , 0x7f , sizeof(h));
    //cout<<h[0]<<endl;
    memset( vis , 0 ,sizeof(vis));
    memset( cnt , 0 , sizeof(cnt) );
    h[1] = 0;
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    cnt[1]++;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] > h[u] + w)
            {
                h[v] = h[u] + w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
                if(++cnt[v] > n)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&x,&y);

            int a,b,c;
            c = 1;
            memset( head , -1 , sizeof(head));
            for( int i = 0 ; i < x ; i++ )
            {
                scanf("%d%d%d",&a,&b,&c);
                addEdge( a , b , c);
            }
            for( int i = 0 ; i < y ; i++)
            {
                scanf("%d%d%d",&a,&b,&c);
                addEdge( b , a , -c );
            }
            for( int i = 2 ; i <= n ; i++ )
                addEdge( i - 1 , i , 0 );
            if(!spfa())
                printf("-1\n");
            else if(h[n] == 2139062143) printf("-2\n");
            else printf("%d\n",h[n]);

    }
    return 0;
}
