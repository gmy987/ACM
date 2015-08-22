#include <cstdio>
#include <cstring>
#define MAXN 1100

using namespace std;

int belong[MAXN], dfn[MAXN], low[MAXN];
int stack[MAXN];
int bcnt, depth, tail;
bool vis[MAXN];

int head[MAXN], size;

int a[MAXN*10], b[MAXN*10], c[MAXN*10], x[MAXN];
int n, m;

struct Edge{
	int u, v, next;
	Edge(){}
	Edge(int _u,int _v,int _next):u(_u),v(_v),next(_next){}
}edge[MAXN*100];

inline void init(){
	size = 0;
	memset(head,-1,sizeof(head));
}
inline void add_edge(int u,int v){
	edge[size] = Edge(u,v,head[u]);
	head[u] =size ++;
}
inline void Tarjan_init(){
	depth = tail = bcnt = 0;
	memset(dfn,-1,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,false,sizeof(vis));
	memset(belong,0,sizeof(belong));
}
inline void Tarjan(int u){
	dfn[u] = low[u] = depth ++;
	vis[u] = true;
	stack[++tail] = u;
	for(int i = head[u];i != -1;i = edge[i].next){
		int v = edge[i].v;
		if(dfn[v] == -1){
			Tarjan(v);
			if(low[u] > low[v])
				low[u] = low[v];
		}else if(vis[v] && low[u] > dfn[v]){
			low[u] =dfn[v];
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
inline void build(int k){
	for(int i = 0;i < k; ++i){
		if(c[i] == 0){
			add_edge(a[i],b[i] + n);
			add_edge(b[i],a[i] + n);
		}else if(c[i] == 1){
			add_edge(a[i],b[i]);
			add_edge(b[i],a[i]);
			add_edge(a[i] + n,b[i] + n);
			add_edge(b[i] + n,a[i] + n);
		}else{
			add_edge(a[i] + n,b[i]);
			add_edge(b[i] + n,a[i]);
		}
	}
	
}
inline bool check(){
	for(int i = 0;i < 2*n; ++i)
		if(dfn[i] == -1) Tarjan(i);
	for(int i = 0;i < n; ++i)
		if(belong[i] == belong[i+n]) return false;
	return true;
}
inline void binary(){
	int l = 1, r = m, mid;
	while(r >= l){
		mid = (l + r) >> 1;
		init();
		build(mid);
		Tarjan_init();
		if(check()) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n",l-1);

}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i = 0;i < m; ++i)
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
		binary();
	}
	
}
