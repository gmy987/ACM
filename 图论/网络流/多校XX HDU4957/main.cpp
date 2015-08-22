// dinic cur_edge optimize
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define MAXN 1010
#define INF 0x7fffffff
using namespace std;
#define maxn 1010
const int inf = 0x7fffffff;
struct Edge{
    int from,to,next,f;
};
Edge edge[maxn*maxn];
int head[maxn],tp;
bool vis[maxn];
int row[maxn],col[maxn];
int n,m,flag,s,t;
int dfn[maxn],low[maxn],belong[maxn],stack[maxn];
int depth,tail,bcnt;
int cont[maxn];
void init()
{
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(dfn,-1,sizeof(dfn));
    tp = 0;
    depth = 0,tail = 0,bcnt = 0;
}

void insert(int ui,int vi,int fi)
{
    edge[tp].from = ui;
    edge[tp].to = vi;
    edge[tp].f = fi;
    edge[tp].next = head[ui];
    head[ui] = tp++;
    edge[tp].from = vi;
    edge[tp].to = ui;
    edge[tp].f = 0;
    edge[tp].next = head[vi];
    head[vi] = tp++;
}
int que[maxn],dis[maxn];
/*
int bfs(int s,int t)
{
    int i,x,a,head_i = 0,tail_i = 0;
    memset(dis,0,sizeof(dis));
    dis[s] = 1;
    que[tail_i++] = s;
    while(head_i < tail_i)
    {
        x = que[head_i++];
        for(i = head[x];i != -1;i = edge[i].next)
            if(edge[i].f && dis[a=edge[i].to] == 0)
            {
                dis[a] = dis[x]+1;
                if(a == t) return 1;
                que[tail_i++] = a;
            }
    }
    return 0;
}
int dfs(int s,int t,int limit)
{
    if(s == t)
        return limit;
    int a,tmp,cost = 0;
    for(int &i = cur[s];i != -1;i = edge[i].next)
        if(edge[i].f && dis[s] == dis[a = edge[i].to]-1)
        {
            tmp = dfs(a,t,min(limit-cost,edge[i].f));
            if(tmp > 0)
            {
                cost += tmp;
                edge[i].f -= tmp;
                edge[i^1].f += tmp;
                if(limit == cost) break;
            }
            else  dis[a] = -1;
        }
    return cost;
}

int Dinic(int s,int t)
{
    int ans = 0,i;
    while(bfs(s,t))
    {
        for(i = 1;i <= t;i++)
            cur[i] = head[i];
        ans += dfs(s,t,inf);
    }
    return ans;
}
*/
int gap[MAXN],cur[MAXN],aug[MAXN],pre[MAXN];
int sap( int x , int T , int S )// x = T + 1
{
    int maxflow = 0 , u = S , v;
    int id , mindis;
    aug[S] = INF;
    pre[S] = -1;
    memset( dis , 0 , sizeof(dis));
    memset( gap , 0 , sizeof(gap));
    gap[S] = x;
    for( int i = S ; i <= n ; i++ )
        cur[i] = head[i];
    while(dis[S] < x )
    {
        int flag = 0;
        if( u == T )
        {
            maxflow += aug[T];
            for( v = pre[T] ; ~v ; v = pre[v])
            {
                id = cur[v];
                edge[id].f -= aug[T];
                edge[id^1].f += aug[T];
                aug[v] -= aug[T];
                if( edge[id].f == 0)
                    u = v;
            }
        }
        for( int i = cur[u] ; ~i ; i = edge[i].next )
        {
            v = edge[i].to;
            if( edge[i].f > 0 && dis[u] == dis[v] + 1)
            {
                flag = 1;
                pre[v] = u;
                cur[u] = i;
                aug[v] = min( aug[u] , edge[i].f );
                u = v;
                break;
            }
        }
        if( !flag )
        {
            if(--gap[dis[u]] == 0 )
                break;
            mindis = x;
            cur[u] = head[u];
            for( int i = head[u] ; ~i ; i = edge[i].next )
            {
                v = edge[i].to;
                if( edge[i].f > 0 && dis[v] < mindis )
                {
                    mindis = dis[v];
                    cur[u] = i;
                }
            }
            dis[u] = mindis+1;
            gap[dis[u]]++;
            if( u != S )
                u = pre[u];
        }
    }
    return maxflow;
}


void Tarjan(int v)
{
    dfn[v] = low[v] = depth++;
    vis[v] = true;
    stack[++tail] = v;
    for(int i = head[v];i != -1;i = edge[i].next)
    {
        int u = edge[i].to;
        if(u == s || u == t || edge[i].f <= 0)
            continue;
        if(dfn[u] == -1)
        {
            Tarjan(u);
            if(low[v] > low[u]) low[v] = low[u];
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
}

int main()
{
    int k,i,j,ci;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int cas = 0;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)
        {
            printf("Case #%d: So naive!\n",++cas);
            continue;
        }
        init();
        s = n+m+1,t = n+m+2;
        int sum = 0,sumcol = 0;
        for(i = 1;i <= n;i++)
        {
            scanf("%d",&ci);
            sum += ci;
            insert(s,i,ci);
        }
        for(i = n+1;i <= n+m;i++)
        {
            scanf("%d",&ci);
            insert(i,t,ci);
            sumcol += ci;
        }
        for(i = 1;i <= n;i++)
            for(j = n+1;j <= n+m;j++)
                insert(i,j,9);
        if(sum != sumcol)
        {
            printf("Case #%d: So naive!\n",++cas);
            continue;
        }
        int res = sap(t+1,t,s);
        if(sum == res)
        {
            flag = 0;
            for(i = 1;i <= t-2;i++)
                if(dfn[i] == -1)
                    Tarjan(i);
            memset(cont,0,sizeof(cont));
            for(i = 1;i <= t-2;i++)
            {
                int num = belong[i];
                cont[num]++;
                if(cont[num] > 2)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag) printf("Case #%d: So young!\n",++cas);
            else printf("Case #%d: So simple!\n",++cas);
        }else printf("Case #%d: So naive!\n",++cas);

    }
    return 0;
}
