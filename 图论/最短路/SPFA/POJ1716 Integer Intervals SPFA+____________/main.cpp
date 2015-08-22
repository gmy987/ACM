/*
node1：对于区间放置元素问题，要注意区间开闭性，也就是说要关注对点的约束。
特别注意每个点上放置元素个数的限制，这里一般都是隐含关系的考察点（详见下文）。

node2：对于差分不等式，a - b <= c ，建一条 b 到 a 的权值为 c 的边，求的是最短路，
得到的是最大值；对于不等式 a - b >= c ，建一条 b 到 a 的权值为 c 的边，
求的是最长路，得到的是最小值。存在负环的话是无解，求不出最短路（dist[ ]没有得到更新）的话是任意解。

node3：建图中有时候会用到一个虚点，这个点到图中每个实点的距离（dist[ ]）为0，
当然这个点的作用是方便图中的点入队（spfa算法），然后使这些实点的dist[ ]值得到更新，
其实有时候我们可以省略这个点，手动把所有实点入队，
同时更新这些实点的 dist[ ] 值和 visit[ ] 值。

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
    int to,next,w;
}edge[40000];
int head[10005],h[10005],cnt,n,c[100005],Min,Max;
bool vis[10005];

void addEdge( int u , int v , int w )
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool spfa()
{
    memset( h , 0 , sizeof(h));
    memset( vis , 0 ,sizeof(vis));
    memset( c , 0 , sizeof(c));

    queue<int> q;
    //将每个点入队一次,同时更新vis值；
    for( int i = Min ; i < Max ; i++)
    {
        vis[i] = 1;
        q.push(i);
    }

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
                    vis[v] = 1;
                    q.push(v);
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
    scanf("%d",&n);
    memset( head , -1 , sizeof( head ));
    Min = ~0u>>1 , Max = 0 ;
    cnt = 1;
    int a , b;
    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%d%d",&a,&b);
        Min = min( Min , a);
        Max = max( Max , b + 1);
        addEdge( a , b + 1 , 2 );
    }
    for( int i = Min ; i < Max ; i++ )
    {
        addEdge( i , i + 1 , 0 );
        addEdge( i + 1 , i , -1 );
    }
    if(spfa())
        printf("%d\n",h[Max]);
    else
        printf("0\n");
}
