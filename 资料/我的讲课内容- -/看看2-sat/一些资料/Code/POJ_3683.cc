#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 2200

using namespace std;

struct Edge{
	int u, v, next;
	Edge(){}
	Edge(int _u,int _v,int _next):u(_u),v(_v),next(_next){}
}edge[MAXN*MAXN];int head[MAXN], size;

struct Person{
	int s, e, d;
	Person(){}
	Person(int _s,int _e,int _d):s(_s),e(_e),d(_d){}
}a[MAXN];

int n, m, belong[MAXN];
bool vis[MAXN];
int depth, bcnt, tail, stack[MAXN];
int dfn[MAXN], low[MAXN];

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
	edge[size] = Edge(u,v,head[u]);
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
inline bool cut(int s1,int e1,int s2,int e2){
	if(e2 <= s1 || e1 <= s2) return false;
	return true;
}

int partner[MAXN];    //每个缩点对应的和它矛盾的缩点
inline bool check(){
	Tarjan_init();
	for(int i = 1;i <= 2*n; ++i)
		if(dfn[i] == -1) Tarjan(i);
	for(int i = 1;i <= n; ++i){
		if(belong[i] == belong[i+n]) return false;
		partner[belong[i]] = belong[i+n];
		partner[belong[i+n]] = belong[i];
	}
	return true;
}
inline void build(){
	init();
	for(int i = 1;i < n; ++i)
		for(int j = i + 1;j <= n; ++j){
			if(cut(a[i].s,a[i].s + a[i].d,a[j].s,a[j].s + a[j].d)){ //i和j不能同时在前
				add_edge(i,j + n);
				add_edge(j,i + n);
			}
			if(cut(a[i].e - a[i].d,a[i].e,a[j].e - a[j].d,a[j].e)){ //i和j不能同时在后
				add_edge(i + n,j);
				add_edge(j + n,i);
			}
			if(cut(a[i].s,a[i].s + a[i].d,a[j].e - a[j].d,a[j].e)){ //i在前，j在后
				add_edge(i,j);
				add_edge(j + n,i + n);
			}
			if(cut(a[i].e - a[i].d,a[i].e,a[j].s,a[j].s + a[j].d)){ //i在后，j在前
				add_edge(i + n,j + n);
				add_edge(j,i);
			}

		}
}

vector<int> DAG[MAXN];        //缩点后的DAG图的逆图
int degree[MAXN];

inline void build_DAG(){         //缩点建立具有拓扑结构的逆图DAG
	memset(degree,0,sizeof(degree));
	for(int i = 0;i <= bcnt; ++i) DAG[i].clear();
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
bool first[MAXN];
inline void top_sort(){
	queue<int> Q;
	memset(color,0,sizeof(color));
	for(int i = 1;i <= bcnt; ++i)
		if(degree[i] == 0)
			Q.push(i);
	while(!Q.empty()){
		int t = Q.front();  Q.pop();
		if(color[t] == 0){
			color[t] = 1;
			color[partner[t]] = -1;
		}
		for(vector<int>::iterator i = DAG[t].begin();i != DAG[t].end(); ++i){
			int v = *i;
			degree[v] --;
			if(degree[v] == 0) Q.push(v);
		}
	}
}

inline void solve(){
	build_DAG();
	top_sort();
	memset(first,false,sizeof(first));
	for(int i = 1;i <= n; ++i){
		if(color[belong[i]] == 1)
			first[i] = true;
	}
}

inline void output(int s,int e){
	int hour, mini;
	hour = s/60; mini = s%60;
	printf("%d%d:%d%d ",hour/10,hour%10,mini/10,mini%10);
	hour = e/60; mini = e%60;
	printf("%d%d:%d%d\n",hour/10,hour%10,mini/10,mini%10);
}
inline void put(int type,int i){
	int s, e;
	if(type == 0){
		s = a[i].s;
		e = a[i].s + a[i].d;
	}else{
		s = a[i].e - a[i].d;
		e = a[i].e;
	}
	output(s,e);
}

int main()
{
	char ch1[20], ch2[20];
	while(scanf("%d",&n) != EOF){
		for(int i = 1;i <= n; ++i){
			scanf("%s %s %d",ch1,ch2,&a[i].d);
			a[i].s = (ch1[0]-'0')*10*60 + (ch1[1]-'0')*60 + (ch1[3]-'0')*10 + ch1[4]-'0';
			a[i].e = (ch2[0]-'0')*10*60 + (ch2[1]-'0')*60 + (ch2[3]-'0')*10 + ch2[4]-'0';
		}
		build();
		if(!check()) printf("NO\n");
		else{
			printf("YES\n");
			solve();
			for(int i = 1;i <= n; ++i){
				if(first[i]) put(0,i);
				else         put(1,i);
			}
		}
	}
}
