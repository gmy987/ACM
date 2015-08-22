//枚举每个等级对应可走的点
//1为终点，可以自己设定一个源点，每个物品本身的价值为此源点到该点的边权

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define maxn 105
#define maxm 20005
#define INF 0x7fffffff

using namespace std;
struct Edge{
    int to,next,w;
}edge[maxm];
int head[maxn],vis[maxn],h[maxn],cnt,lv[maxn];
int m,n;
void addEdge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}

struct cmp{
    bool operator() ( const int a , const int b)
    {
        return h[a] > h[b];
    }
};

void Dijkstra()
{
    priority_queue<int,vector<int>,cmp> q;
    h[0] = 0;
    q.push(0);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for( int i = head[u] ; ~i ; i = edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if(!vis[v] && h[v] > h[u] + w)
            {
                h[v] = h[u] + w;
                q.push(v);
            }
        }
    }
}
int main()
{
    freopen( "input.txt","r",stdin);
    while(~scanf("%d%d",&m,&n))
    {
        memset(head , -1 , sizeof(head));
        memset(lv,0,sizeof(lv));
        cnt = 1;
        int w,num,a;
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d%d%d",&w,&lv[i],&num);
            addEdge(0,i,w);
            for( int j = 1 ; j<= num ; j++ )
            {
                scanf("%d%d",&a,&w);
                addEdge(a,i,w);
            }
        }

        //int tempPrice;//当前交易后目标点1在等级lv[i]限制下的最小值
        int maxlv;
        int minPrice = 0x7fffffff;//最低价格（初始化为无限大）

        for( int i = 1 ; i <= n ; i++ )
        {
            memset( vis , 0 , sizeof( vis ));
            memset( h , 0x7f , sizeof(h));
            maxlv = lv[i];//把当前物品的等级暂时看做最高等级
            for( int j = 1 ; j <= n ; j++ )
            {
                if(lv[j] > maxlv || maxlv-lv[j] > m )
                    vis[j] = 1;
                else
                    vis[j] = 0;
            }
            Dijkstra();
            //tempPrice = h[1];
            minPrice = min(minPrice , h[1]);
        }
        printf("%d\n",minPrice);
    }
    return 0;
}
