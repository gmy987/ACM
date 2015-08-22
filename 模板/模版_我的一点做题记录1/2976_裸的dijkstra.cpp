#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define maxn 105
#define maxm 20020
typedef struct{
    int v,u,d,next;
}Edge;
Edge edge[maxm];
int head[maxn];
int dist[maxn];
int flag[maxn];
int tp;
void init()
{
    memset(head,-1,sizeof(head));
    return;
}

void insert(int vi,int ui,int di)
{
    edge[tp].u = ui;
    edge[tp].d = di;
    edge[tp].next = head[vi];
    head[vi] = tp++;
    return;
}
int stone;
void init_dist()
{
    memset(dist,0x7f,sizeof(dist));
    memset(flag,0,sizeof(flag));
    stone = dist[0];
    return;
}

void dijkstra(int s,int en)
{
    init_dist();
    dist[s] = 0;
    for(int i = 1;i < en;i++)
    {
        int minx = stone;
        int chos = -1;
        for(int j = 1;j <= en;j++)
        {
            if(flag[j] == 0 && minx > dist[j])
            {
                minx = dist[j];
                chos = j;
            }
        }
        if(chos == -1)
            break;
        for(int j = head[chos];j != -1;j = edge[j].next)
        {
            if(flag[edge[j].u] == 0 && dist[edge[j].u] > dist[chos] + edge[j].d)
                dist[edge[j].u] = dist[chos] + edge[j].d;
        }
        flag[chos] = 1;
    }
    return;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n == 0 && m == 0)
        break;
        init();
        tp = 0;
        for(int i = 0;i < m;i++)
        {
            int vi,ui,di;
            scanf("%d%d%d",&vi,&ui,&di);
            insert(vi,ui,di);
            insert(ui,vi,di);
        }
        dijkstra(1,n);
        printf("%d\n",dist[n]);
    }
    return 0;
}
