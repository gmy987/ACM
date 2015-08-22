/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-06 15:13
*
* Filename: 1009.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 123456789876543ll 
#define MAXN 211111
using namespace std;
long long dis[MAXN];
int vis[MAXN];
struct cmp
{
    bool operator()( int a, int b )
    {
        return dis[a]>dis[b];
    }
};
int l[MAXN],r[MAXN];
int n;
long long cost[MAXN];
void Dijkstra( int t )
{
    priority_queue<int,vector<int>,cmp> q;
    dis[t] = 0;
    q.push(t);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        if( vis[u] ) continue;
        vis[u] = 1;
        for( int i = l[u] ; i <= r[u] ; i++ )
        {
            int v = u+i;
            int w = cost[u];
            if( v <= n && dis[v] > dis[u] + w )
            {
                dis[v] = dis[u] + w;
                q.push(v);
            }
            v = u-i;
            if( v >= 1 && dis[v] > dis[u]+w )
            {
                dis[v] = dis[u] + w;
                q.push(v);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for( int i = 1 ; i <= n ; i++ )
        {
            dis[i] = INF;
        }
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d",&l[i]);
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d",&r[i]);
        for( int i = 1 ; i <= n ; i++ )
            scanf("%lld",&cost[i]);
        Dijkstra(1);
        for( int i = 1; i <= n ; i++ )
        {
            if( i == 1 ) printf("0");
            else printf(" %I64d",dis[i]==INF?-1:dis[i]);
        }
        printf("\n");
    }
    return 0;
}

