#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 300

using namespace std;

struct Edge{
	int u, v, next;
	Edge(){}
	Edge(int _u,int _v,int _next):u(_u),v(_v),next(_next){}
}edge[MAXN*MAXN];

int n, m, nn;
int head[MAXN], size;
int dfn[MAXN], low[MAXN], belong[MAXN];
int bcnt, depth, tail;
int stack[MAXN];
bool vis[MAXN];

inline void init(){
	size = 0;
	memset(head,-1,sizeof(head));
}
inline void Tarjan_init(){
	bcnt = depth = tail = 0;
	memset(dfn,-1,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,false,sizeof(vis));
}
inline void add_edge(int u,int v){
	edge[size] = Edge(u,v,head[u]);
	head[u] = size ++;
}
inline void Tarjan(int u){
	dfn[u] = low[u] = depth ++;
	vis[u] = true;
	stack[++tail] = u;
	for(int i = head[u];i != -1;i = edge[i].next){
		int  v = edge[i].v;
		if(dfn[v] == -1){
			Tarjan(v);
			if(low[u] > low[v])
				low[u] = low[v];
		}else if(vis[v] && low[u] > dfn[v])
			low[u] = dfn[v];
	}
	if(low[u] == dfn[u]){
		bcnt ++;
		int j;
		do{
			j = stack[tail--];
			vis[j] = false;
			belong[j] = bcnt;
		}while(j != u);
	}
}

int partner[MAXN];
inline bool check(){
	Tarjan_init();
	for(int i = 0;i < 2*n; ++i)
		if(dfn[i] == -1) Tarjan(i);
	for(int i = 0;i < n; ++i){
		if(belong[i] == belong[i+n]) return false;
		partner[belong[i]] = belong[i+n];
		partner[belong[i+n]] = belong[i];
	}
	return true;
}

vector<int> DAG[MAXN];
int degree[MAXN];
inline void build_DAG(){
	for(int i = 1;i <= bcnt; ++i) DAG[i].clear();
	memset(degree,0,sizeof(degree));
	for(int i = 0;i < size; ++i){
		int u = edge[i].u;
		int v = edge[i].v;
		if(belong[u] != belong[v]){
			DAG[belong[v]].push_back(belong[u]);
			degree[belong[u]] ++;
		}
	}
}

int color[MAXN];
bool flag[MAXN];
inline void top_sort(){
	queue<int> Q;
	memset(color,0,sizeof(color));
	memset(flag,false,sizeof(flag));
	for(int i = 1;i <= bcnt; ++i)
		if(degree[i] == 0) Q.push(i);
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		if(color[u] == 0){
			color[u] = 1;
			color[partner[u]] = -1;
		}
		for(vector<int>::iterator i = DAG[u].begin();i != DAG[u].end(); ++i){
			int v = *i;
			degree[v] --;
			if(degree[v] == 0) Q.push(v);
		}
	}
	for(int i = 0;i < 2*n; ++i)
		if(color[belong[i]] == 1)
			flag[i] = true;
}

inline void output(int t){
	if(t&1) printf("%dh ",t/2);
	else printf("%dw ",t/2);
}
inline void put(){
	for(int i = 2;i < n; ++i)
		if(flag[i]) output(i);
	putchar('\n');
}
int main()
{
	while(scanf("%d %d",&n,&m),(n && m)){
		init();
		//-------------构图--------------------//
		/*
		 * 第i对夫妇，2*i表示妻子在左边，2*i+1表示丈夫在左边，加2n分别表示坐右边
		 */
		int u, v, _u, _v;
		char ch1, ch2;
		add_edge(2*n,0); //新娘必须坐左边
		add_edge(1,1+2*n);
		for(int i = 1;i <= n; ++i){    //夫妇必须坐对面
			add_edge(2*i,2*i+1+2*n);
			add_edge(2*i+1,2*i+2*n);
			add_edge(2*i+2*n,2*i+1);
			add_edge(2*i+1+2*n,2*i);
		}
		for(int i = 1;i <= m; ++i){
			scanf("%d%c %d%c",&u,&ch1,&v,&ch2);
			if(ch1 == 'h')
				u = 2*u + 1, _u = u + 2*n;
			else
				u = 2*u, _u = u + 2*n;
			if(ch2 == 'h')
				v = 2*v + 1, _v = v + 2*n;
			else    v = 2*v, _v = v + 2*n;
			add_edge(_u, v);
			add_edge(_v, u);
		}
		n *= 2;
		if(!check()) printf("bad luck\n");
		else{
			build_DAG();
			top_sort();
			put();
		}

	}
}
