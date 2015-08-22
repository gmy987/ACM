#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 20005
#define MAXM 40000005
using namespace std;
struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],dfn[MAXN],low[MAXN],cnt,deep,t,n;
bool vis[MAXN],flag;
void addEdge( int u , int v )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
stack<int> s;
void tarjan( int x )
{
    int i;
    low[x] = dfn[x] = ++deep;
    s.push(x);
    vis[x] = 1;
    for( i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to;
        if( dfn[v] == -1 )
        {
            tarjan(v);
            if( low[x] < low[v] )
                low[x] = low[v];
        }
        else if( vis[v] && low[x] > dfn[v] )
            low[x] = dfn[v];
    }
    if( low[x] == dfn[x] )
    {
        int c = 0;
        while(!s.empty())
        {
            i = s.top();
            s.pop();
            vis[i] = 0;
            c++;
            if( i == x )
                break;
        }
        if( c >= 3 )//注意是大于等于3，强连通分量不一定正好有三个节点
            flag = true;//由于强联通分量的性质，大于三时，一定也存在一个三角环
    }

}
int main()
{
    scanf("%d",&t);
    for( int num = 1 ; num <= t ; num++)
    {
        scanf("%d",&n);
        int i,j;
        char a[20005];
        memset(head,0xff,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(dfn,0xff,sizeof(dfn));
        memset(low,0,sizeof(low));
        cnt = deep = 0;
        flag = false;
        for( i = 1 ; i <= n ; i++ )
        {
            scanf("%s",a);
            for( j = 1 ; j <= n ; j++ )
            {
                if( a[j-1] - '0' == 1 )
                    addEdge( i , j );
            }
        }
        for( i = 1 ; i <= n ; i++ ){
            if( dfn[i] == -1 )
                tarjan(i);
            if(flag)
                break;
        }
        printf("Case #%d: ",num);
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
