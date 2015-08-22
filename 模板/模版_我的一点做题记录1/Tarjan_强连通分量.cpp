#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

//求强连通分量Tarjan算法
void Tarjan(int v)
{
    dfn[v] = low[v] = depth++;
    vis[v] = true;
    stack[++tail] = v;
    for(int i = head[v];i != -1;i = edge[i].next)
    {
        int u = edge[i].u;
        if(dfn[u] == -1)
        {
            Tarjan(u);
            if(low[v] > low[u])
                low[v] = low[u];
        }else if(vis[u] && low[v] > dfn[u])
            low[v] = dfn[u];
    }
    if(low[v] == dfn[v])
    {
        bcnt++;
        int j;
        do{
            j = stack[tail--];
            vis[j] = 0;
            belong[j] = bcnt;
        }while(j != v);
    }
    return;
}

