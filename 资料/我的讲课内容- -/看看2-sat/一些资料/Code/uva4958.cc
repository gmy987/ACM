#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 40010
#define MAXM 100010

using namespace std;

int head[MAXN], size;
int n, m, depth, bcnt;
int belong[MAXN], dfn[MAXN], low[MAXN];
bool vis[MAXN];
int stack[MAXN], tail;

vector<int>T[6010];
int dist[100][100];

struct Edge{
	int v, next;
	Edge(){}
	Edge(int _v,int _next):v(_v),next(_next){}
}edge[MAXM*20];

inline void init(){
	size = 0;
	memset(head,-1,sizeof(int)*(4*n+2));
}
inline void Tarjan_init(){
	bcnt = tail = depth = 0;
	memset(vis,false,sizeof(bool)*(4*n+2));
	memset(dfn,-1,sizeof(int)*(4*n+2));
	memset(low,0,sizeof(int)*(4*n+2));
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
int main()
{
	freopen("E.in","r",stdin);
	freopen("out","w",stdout);
	int t, p;
	char c, str[MAXN];
	dist['A']['G'] = 1; dist['A']['T'] = 2; dist['A']['C'] = -1;
	dist['G']['T'] = 1; dist['G']['C'] = 2; dist['G']['A'] = -1;
	dist['T']['C'] = 1; dist['T']['A'] = 2; dist['T']['G'] = -1;
	dist['C']['A'] = 1; dist['C']['G'] = 2; dist['C']['T'] = -1;
	while(scanf("%d%d",&n,&m) != EOF){
		if(m == 0 && n == 0) break;
		scanf("%s",str);
		for(int i = 1;i <= m; ++i){
			T[i].clear();
			scanf("%d",&t);
			scanf(" %c",&c);
			for(int j = 1;j <= t; ++j){
				scanf("%d",&p);
				T[i].push_back(p);
			}
		}
		init();
		//add edge
		for(int i = 0;i < n; ++i){
			add_edge(i + 2*n, i);
			add_edge(i + 3*n, i);
			if(i + 1 < n) add_edge(i,i + 1 + n);
			if(i - 1 >=0) add_edge(i,i - 1 + n);
		}
		for(int ii = 1;ii <= m; ++ii){
			if(T[ii].size() < 2) continue;
			for(size_t i = 0, j = T[ii].size() - 1;j > i; ++i,--j){
				int u = T[ii][i], v = T[ii][j];
				int tmp = dist[str[u]][str[v]];
				if(str[u] == str[v]){
					add_edge(u,v);
					add_edge(v,u);
					add_edge(u + n, v + n);
					add_edge(v + n, u + n);
					add_edge(u +2*n,v+2*n);
					add_edge(v +2*n,u+2*n);
					add_edge(u+3*n,v+3*n);
					add_edge(v+3*n,u+3*n);
				}else if(tmp == 1 ||tmp == -1){
					if(tmp == -1) swap(u, v);
					add_edge(u, v + n);	
					add_edge(v + n, u);
					add_edge(u + n, v);
					add_edge(v, u + n);
					add_edge(u,u + 2*n);
					add_edge(v,v + 3*n);
					add_edge(v + 2*n, u);
					add_edge(u + 3*n, v);
				}else{
					add_edge(u + n, u);
					add_edge(v + n, v);
					add_edge(u + 2*n, v + 3*n);
					add_edge(v + 3*n, u + 2*n);
					add_edge(u + 3*n, v + 2*n);
					add_edge(v + 2*n, u + 3*n);
				}
			}
		}
		Tarjan_init();
		for(int i = 0;i < 4*n; ++i)
			if(dfn[i] == -1) Tarjan(i);
		bool flag = true;
		/*
		for(int i = 0,j = 2*n;i < n; ++i, ++j)
			if(belong[i] == belong[i+n] || belong[j] == belong[j+n]){
				flag = false;
				break;
			}
			*/
		for(int i = 0;i < n; ++i){
			if(belong[i] == belong[i+n] || belong[i+n] == belong[i+2*n] || belong[i+n] == belong[i+3*n]){
				flag = false;
				break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");

	}



}
