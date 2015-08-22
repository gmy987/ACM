/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-17 09:25
*
* Filename: hdu4888.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#define maxm 500000
#define maxn 900 
#define INF 0x7fffffff

using namespace std;
struct Edge{
    int to,from,cap,next;
}edge[maxm];
int S,T;
int dis[maxn],gap[maxn],cur[maxn],q[maxn],st[maxn],front,rear,cnt,head[maxn];
//int dis[maxn],head[maxn],cnt;
void addedge( int u , int v , int cap ){
    edge[cnt].to = v;
    edge[cnt].from = u;
    edge[cnt].cap = cap;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].from = v;
    edge[cnt].next = head[v];
    edge[cnt].cap = 0;
    head[v] = cnt++;
}
int n,m,k;

void bfs(int t){
    memset(dis,0xff,sizeof(dis));
    memset(gap,0,sizeof(gap));
    dis[t] = 0;
    gap[0] = 1;
    front = rear = 0;
    q[rear++] = t;
    while(front!=rear){
        int u = q[front++];
        for( int i = head[u] ; ~i ; i = edge[i].next ){
            int v = edge[i].to;
            if(~dis[v]) continue;
            dis[v] = dis[u]+1;
            gap[dis[v]]++;
            q[rear++] = v;
        }
    } 
}
int isap( int s, int t, int n ){
    bfs(t);
    memcpy(cur,head,sizeof(head));
    int top = 0;
    int u = s;
    int flow = 0,i;
    while(dis[s]<n){
        if(u==t){
            int f = INF;
            int inser = n;
            for( i = 0 ; i < top ; i++ ){
                if(f>edge[st[i]].cap){
                    f = edge[st[i]].cap;
                    inser = i;
                }
            }
            for( i = 0 ; i < top ; i++ ){
                edge[st[i]].cap -= f;
                edge[st[i]^1].cap += f;
            }
            flow += f;
            top = inser;
            u = edge[st[top]].from;
            continue;
        }
        if(u!=t&&gap[dis[u]-1]==0) break;
        for( i = cur[u] ; ~i ; i = edge[i].next )
            if(edge[i].cap&&dis[u] == dis[edge[i].to]+1) break;
        if(~i){
            cur[u] = i;
            st[top++] = i;
            u = edge[i].to;
        }
        else{
            int f = n;
            for( i = head[u] ; ~i ; i = edge[i].next ){
                if(!edge[i].cap) continue;
                if( f > dis[edge[i].to] ){
                    f = dis[edge[i].to];
                    cur[u] = i;
                }
            }
            --gap[dis[u]];
            ++gap[dis[u]=f+1];
            if(u!=s) u = edge[st[--top]].from;
        }
    }
    return flow;
}

bool flag;
int vis[maxn];
void Dfs( int x , int pre ){
    if(!flag) return;
    if(vis[x]){
        flag = false;
        return;
    }
    vis[x] = 1;
    for( int i = head[x] ; ~i ; i = edge[i].next ){
        if(!edge[i].cap) continue;
        int v = edge[i].to;
        if( v != pre && v != S && v != T ){
            Dfs(v,x);
            if(!flag) return;
        }
    }
    vis[x] = 0;
}
/*
bool bfs()
{
    memset( dis , 0xff , sizeof(dis));
    queue<int> q;
    dis[S] = 0;
    q.push(S);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for( int i = head[u] ; ~i ; i = edge[i].next )
        {
            int v = edge[i].to , cap = edge[i].cap;
            if( dis[v] < 0 && cap > 0)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[T] > 0;

}

int dfs( int x , int low )
{
    if( x == T || low == 0)
        return low;
    int flow = 0 , a;
    for( int i = head[x] ; ~i ; i = edge[i].next )
    {
        int v = edge[i].to , cap = edge[i].cap;
        if( dis[v] == dis[x] + 1 && cap > 0)
        {
            a = dfs( v , min( low , cap ));
            edge[i].cap -= a;
            edge[i^1].cap += a;
            flow += a;
            low -= a;
            if( low == 0 )
                break;
        }
    }
    return flow;
}

int dinic()
{
    int ans = 0;
    while( bfs() )
        ans += dfs( S , INF );
    return ans;
}*/


int main(){
    while(~scanf("%d%d%d",&n,&m,&k)){
        int sum = 0;
        int a;
        S = 0;
        T = n+m+1;
        cnt = 0;
        memset(head,0xff,sizeof(head));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = n+1 ; j <= n+m ; j++ )
                addedge(i,j,k);
        int tmp = cnt;
        for( int i = 1 ; i <= n ; i++ ){
            scanf("%d",&a);
            sum += a;
            addedge(S,i,a);
        }
        int sum2 = 0;
        for( int i = n+1 ; i <= n+m ; i++ ){
            scanf("%d",&a);
            sum2 += a;
            addedge(i,T,a);
        }
        if( sum != sum2 ){
            printf("Impossible\n");
            continue;
        }
        int ans = isap(S,T,T+1);
        flag = true;
        if( sum != ans ){
            printf("Impossible\n");
            continue;
        }
        memset( vis, 0 , sizeof(vis));
        for( int i = 1 ; i <= n  ; i++ ){
            Dfs(i,-1);
            if(!flag) break;
        }
        if(!flag){
            printf("Not Unique\n");
            continue;
        }
        printf("Unique\n");
        int num = 0;
        for( int i = 0 ; i < tmp ; i+=2 ){
            if(!num) printf("%d",k-edge[i].cap);
            else printf(" %d",k-edge[i].cap);
            num++;
            if(num==m){
                puts("");
                num = 0;
            }
        }
    }
    return 0;
}
