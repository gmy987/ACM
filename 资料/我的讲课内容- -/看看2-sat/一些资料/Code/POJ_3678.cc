#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 2010

using namespace std;

int n;
int belong[MAXN];
bool vis[MAXN];
int depth, bcnt;

int dfn[MAXN], low[MAXN];
int stack[MAXN], tail;

int head[MAXN], size;
struct Edge{
	int v, next;
	Edge(){}
	Edge(int _v,int _next):v(_v),next(_next){}
}edge[MAXN*MAXN];

void initial(){
	size = 0;
	memset(head,-1,sizeof(head));
}

inline void add_edge(int u,int v){
	edge[size] = Edge(v,head[u]);
	head[u] = size ++;
}

inline void Tarjan(int u){
	dfn[u] = low[u] = depth ++;
	vis[u] = 1;
	stack[++tail] = u;
	for(int i = head[u];i != -1;i = edge[i].next){
		int v = edge[i].v;
		if(dfn[v] == -1){
			Tarjan(v);
			if(low[u] > low[v])
				low[u] = low[v];
		}else  if(vis[v] && low[u] > dfn[v]){
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
	int m, u, v, w;
	char str[4];
	while(scanf("%d %d",&n, &m) != EOF){
		initial();
		for(int i = 1;i <= m; ++i){
			scanf("%d %d %d %s",&u,&v,&w,str);
			if(str[0] == 'A'){
				if(w){
					add_edge(u,u+n);
					add_edge(v,v+n);
				}else{
					add_edge(u+n,v);
					add_edge(v+n,u);
				}

			}else if(str[0] == 'O'){
				if(w){
					add_edge(u,v+n);
					add_edge(v,u+n);

				}else{
					add_edge(u+n,u);
					add_edge(v+n,v);

				}

			}else{
				if(w){
					add_edge(u+n,v);
					add_edge(v+n,u);
					add_edge(u,v+n);
					add_edge(v,u+n);

				}else{
					add_edge(u,v);
					add_edge(u+n,v+n);
					add_edge(v,u);
					add_edge(v+n,u+n);

				}

			}
		}
		bcnt = tail = depth = 0;
		memset(dfn,-1,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(vis,0,sizeof(vis));
		memset(belong,0,sizeof(belong));
		for(int i = 0;i < 2*n; ++i){
			if(dfn[i] == -1)
				Tarjan(i);
		}
		bool mark = true;
		for(int i = 0;i < n; ++i)
			if(belong[i] == belong[i+n]){
				mark = false;
				break;
			}
		if(!mark) printf("NO\n");
		else printf("YES\n");
	}

}
