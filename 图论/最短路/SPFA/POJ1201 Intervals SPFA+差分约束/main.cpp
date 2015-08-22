/*
设x[i]是{i}这个集合跟所求未知集合的交集元素个数，明显最大只能是1
再设s[i] = x[0] + x[1] + …… + x[i]
明显的，s[i]表示集合{0,1,2,3,……,i}与所求未知集合的交集元素个数
那么就有x[i] = s[i] - s[i-1]
∵0 <= x[i] <= 1
∴0 <= s[i] - s[i-1] <= 1
由于题目求最小值，所以是最长路，用的是a - b >= c这种形式
即有：①s[i] - s[i-1] >= 0; ②s[i-1] - s[i] >= -1;
按照题目输入a, b, c：
表示{a,a+1,a+2,……,b}(设这个集合是Q)与所求未知集合的交集元素个数至少为c
而s[a-1]表示{1,2,3,……,a-1}与所求未知集合的交集元素个数
s[b]表示{1,2,3,……,a-1,a,a+1,a+2,……,b}与所求未知集合的交集元素个数
∴Q = s[b] - s[a-1];
即可建立关系: ③s[b] - s[a-1] >= c;
但是还有一个问题a >= 0，那么a-1有可能不合法
解决方法：所有元素+1就可以了
实现：把③变成 s[b+1] - s[a] >= c;
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge
{
    int to,next,w;
}edge[150005];
int head[50005],h[50005],cnt,n,Min,Max;
bool vis[50005];

void addEdge( int u , int v , int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void spfa()
{
    memset( h , -1 , sizeof(h));
    memset( vis , 0 , sizeof(vis));
    h[Min] = 0;
    vis[Min] = 1;
    queue<int>q;
    q.push(Min);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , w = edge[i].w;
            if( h[v] < h[u] + w )
            {
                h[v] = h[u] + w;
                if( !vis[v] )
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        int a,b,c;
        Min = ~0u >> 1,Max = 0;
        cnt = 1;
        memset( head , -1 , sizeof(head));
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            Min = min( Min , a );
            Max = max( Max , b+1 );
            addEdge( a , b + 1 , c );
        }
        for( int i = Min ; i < Max ; i++ )
        {
            addEdge( i , i + 1 , 0 );
            addEdge( i+1 , i , -1 );
        }
        spfa();
        printf("%d\n",h[Max]);
    }
}
