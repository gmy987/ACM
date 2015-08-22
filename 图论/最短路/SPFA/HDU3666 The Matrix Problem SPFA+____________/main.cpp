/*
这题spfa用队列卡数据容易超时，用栈吧……
由题意得对于矩阵每个元素【设为w，处于矩阵第i行，第j列】
L <= w*a[i]/b[j] <= U
两边取对数有：
lg(L) <= lg(w)+lg(a[i])-lg(b[j]) <= lg(U)
按照最长路整理得【也可以用最短路】：
①lg(a[i])-lg(b[j]) >= lg(L)-lg(w)；②lg(b[j])-lg(a[i]) >= lg(w)-lg(U)
把a和b数组合并成一个数组s得【a有n个元素，b有m个元素，这里把b接在a数组后面】：
①s(i) - s(j+n) >= lg(L) - lg(w)
②s(j+n) - s(i) >= lg(w) - lg(U)
最后加个超级起点即可
我把0作为超级起点：
for (i = 1; i <= n + m; i++)
    addedge (0, i, 0);
spfa (0);
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
struct Edge
{
    int to,next;
    double w;
}edge[1000000];

int head[5000],cnt[5000],c,n,m;
bool vis[5000];
double h[5000],l,u;

void addEdge(int u , int v , double w)
{
    edge[c].to = v;
    edge[c].w = w;
    edge[c].next = head[u];
    head[u] = c++;
}

bool spfa()
{
    memset( h , 0x7f , sizeof(h));
    memset( vis , 0 , sizeof(vis));
    memset( cnt , 0 , sizeof(cnt));
    h[1] = 0;
    vis[1] = 1;
    cnt[1]++;
    stack<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        vis[u] = 0;
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to ;
            double w = edge[i].w;
            if( h[v] > w + h[u])
            {
                h[v] = w + h[u];
                if( !vis[v] )
                {
                    vis[v] = 1;
                    q.push(v);
                }
                if(++cnt[v] > n+m)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%lf%lf",&l,&u);
        memset( head , -1 ,sizeof(head));
        c = 1;
        int num;
        for( int i = 1 ; i <= n ; i++)
            for( int j = 1 ; j <= m ; j++ )
            {
                scanf("%d",&num);
                addEdge( i , j + n , -log(l*1.0/num));
                addEdge( j + n , i , log(u*1.0/num));
            }
        if(spfa())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
