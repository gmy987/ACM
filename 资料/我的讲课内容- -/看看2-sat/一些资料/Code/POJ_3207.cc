#include <cstdio>
#include <cstring>
#define MAXN 1200

using namespace std;

int head[MAXN], size;
int n, m, belong[MAXN];
bool vis[MAXN];
int depth, bcnt, tail, stack[MAXN];
int dfn[MAXN], low[MAXN];

struct Edge{
	int v, next;
	Edge(){}
	Edge(int _v,int _next):v(_v),next(_next){}
}edge[MAXN*MAXN];

struct Line{
	int x, y;
	Line(){}
	Line(int _x,int _y):x(_x),y(_y){}
}line[MAXN];

inline void swap(int &a,int &b){
	int tmp = a; a = b; b = tmp;
}
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
inline bool cut(int i,int j){
	if(line[i].x < line[j].x && line[j].x < line[i].y && line[i].y < line[j].y)return true;
	if(line[j].x < line[i].x && line[i].x < line[j].y && line[j].y < line[i].x)return true;
	return false;
}
inline void build(){
	init();
	for(int i = 1;i < m; ++i)
		for(int j = i + 1;j <= m; ++j){
			if(cut(i,j)){
				add_edge(i,j + m); add_edge(i + m,j);
				add_edge(j,i + m); add_edge(j + m,i);
			}
		}
}
inline bool check(){
	Tarjan_init();
	for(int i = 1;i <= 2*m; ++i)
		if(dfn[i] == -1) Tarjan(i);
	for(int i = 1;i <= m; ++i)
		if(belong[i] == belong[i+m]) return false;
	return true;
}

int main()
{
	while(scanf("%d%d",&n,&m) != EOF){
		for(int i = 1;i <= m; ++i){
			scanf("%d %d",&line[i].x,&line[i].y);
			if(line[i].x > line[i].y) swap(line[i].x,line[i].y);
		}
		build();
		if(check())  printf("panda is telling the truth...\n");
		else printf("the evil panda is lying again\n");
	}

}
