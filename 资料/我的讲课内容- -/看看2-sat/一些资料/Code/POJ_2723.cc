#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 4400

using namespace std;

struct Edge{
	int u, v, next;
	Edge(){}
	Edge(int _v,int _next):v(_v),next(_next){}
}edge[MAXN*10];

int head[MAXN], size;
int n, m, depth, bcnt;
int belong[MAXN], dfn[MAXN], low[MAXN];
bool vis[MAXN];
int stack[MAXN], tail;
int key[MAXN][2], door[MAXN][2];

inline void init(){
	size = 0;
	memset(head,-1,sizeof(head));
}
inline void Tarjan_init(){
	bcnt = tail = depth = 0;
	memset(vis,false,sizeof(vis));
	memset(dfn,-1,sizeof(dfn));
	memset(low,0,sizeof(low));
}

inline void add_edge(int u,int v){
	edge[size] = Edge(v,head[u]);
	head[u] = size ++;
}

inline void Tarjan(int u){
	dfn[u] = low[u] = depth++;
	vis[u] = true;
	stack[++tail] = u;
	for(int i = head[u];i != -1;i = edge[i].next){
		int v = edge[i].v;
		if(dfn[v] == -1){
			Tarjan(v);
			if(low[u] > low[v])
				low[u] = low[v];
		}else if(vis[v] && low[u] > dfn[v]){
			low[u] = dfn[v];
		}
	}
	if(low[u] == dfn[u]){
		bcnt ++;
		int j;
		do{
			j = stack[tail--];
			vis[j] = 0;
			belong[j] = bcnt;
		}while(j != u);
	}
}

inline void build(int t){
	Tarjan_init();
	init();
	for(int i = 1;i <= n/2; ++i){
		add_edge(key[i][0],key[i][1] + n);
		add_edge(key[i][1],key[i][0] + n);
	}
	for(int i = 1;i <= t; ++i){
		add_edge(door[i][0] + n,door[i][1]);
		add_edge(door[i][1] + n,door[i][0]);
	}
}

inline bool check(){
	for(int i = 0;i < 2*n; ++i)
		if(dfn[i] == -1) Tarjan(i);
	for(int i = 0;i < n; ++i)
		if(belong[i] == belong[i+n]) return false;
	return true;
}
inline void work(){
	int low = 0, high = m, mid;
	while(high >= low){
		mid = (high + low) >> 1;
		build(mid);
		if(check())
			low = mid + 1;
		else    high = mid - 1;
	}
	printf("%d\n",high);
}

int main()
{
	while(scanf("%d %d",&n,&m) != EOF){
		if(!n && !m) break;
		for(int i = 1;i <= n; ++i)
			scanf("%d%d",&key[i][0],&key[i][1]);
		for(int i = 1;i <= m; ++i)
			scanf("%d%d",&door[i][0],&door[i][1]);
		n *= 2;
		work();
		//for(int i = 0;i < n; ++i) printf("%d\n",belong[i]);
	}
}
