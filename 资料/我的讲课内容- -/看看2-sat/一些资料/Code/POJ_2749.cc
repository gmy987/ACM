#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 1200
using namespace std;

int n ;            // 顶点个数
int belong[MAXN]; //记录点属于第几个强连通分量
bool vis[MAXN];
int depth;                 //DFS的深度
int bcnt;                  //记录强连通分量个数，下标从1开始
int dfn[MAXN], low[MAXN];  //dfn[u]表示u搜索的次序号(时间戳);
                           //low[u]表示u或者u的子树能够追溯到的最早的栈中节点的次序号
int A, B;
int X1,Y1,X2,Y2;
int hate[MAXN][2], like[MAXN][2];
int x[MAXN], y[MAXN];
int dist[MAXN], dist2[MAXN], D;
int stack[MAXN], tail ;
struct Edge{
	int v,next;
	Edge(){}
	Edge(int _v,int _next):v(_v),next(_next){}
}edge[MAXN*MAXN];

int head[MAXN], size;
inline void init(){
	memset(head,-1,sizeof(head));
	size = 0;
}
inline void Tarjan_init(){
	memset(low,0,sizeof(low));
	memset(dfn,-1,sizeof(dfn));
	memset(vis,0,sizeof(vis));
	depth = tail = bcnt = 0;
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

inline int dis(int i){
	return abs(x[i] - X1) + abs(y[i] - Y1);
}
inline int dis2(int i){
        return abs(x[i] - X2) + abs(y[i] - Y2);
}
inline bool Check(){
        Tarjan_init();
	for(int i = 1;i <= n*2; ++i)
		if(dfn[i] == -1) Tarjan(i);

	for(int i = 1;i <= n; ++i)
		if(belong[i] == belong[i + n])
			return false;
	return true;
}

inline void Build(int S){
	init();
	for(int i = 1;i <= A; ++i){
		int u = hate[i][0];
		int v = hate[i][1];
		add_edge(u,v+n); add_edge(v,u+n);
		add_edge(v+n,u); add_edge(u+n,v);
	}
	for(int i = 1;i <= B; ++i){
		int u = like[i][0];
		int v = like[i][1];
		add_edge(u,v); add_edge(v,u);
		add_edge(u+n,v+n); add_edge(v+n,u+n);
	}
	for(int i = 1;i <= n; ++i)
		for(int j = i + 1;j <= n; ++j){
			if(dist[i] + dist[j] > S){
				add_edge(i,j + n);
				add_edge(j,i + n);

			}
			if(dist2[i] + dist2[j] > S){
				add_edge(i + n,j);
				add_edge(j + n,i);
			}
			if(dist[i] + dist2[j] + D > S){
				add_edge(i,j);
				add_edge(j + n,i + n);
			}
			if(dist2[i] + dist[j] + D > S){
				add_edge(i + n,j + n);
				add_edge(j,i);
			}
		}
}

inline int Binary_search(){
	int right = 4000000, left = 0, mid, ans;
	while(right >= left){
		mid = (right + left) >> 1;
		Build(mid);
		if(Check()){
			ans = mid;
			right = mid - 1;
		}
		else        left = mid + 1;
	}
	if(left >= 4000000) return -1;
	return left;
}

int main()
{
	while(scanf("%d %d %d",&n,&A,&B) != EOF){
		scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
		D = abs(X1-X2) + abs(Y1-Y2);

		for(int i = 1;i <= n; ++i){
			scanf("%d %d",&x[i],&y[i]);
			dist[i] = dis(i);
			dist2[i] = dis2(i);
		}
		for(int i = 1;i <= A; ++i)
			scanf("%d %d",&hate[i][0],&hate[i][1]);
		for(int i = 1;i <= B; ++i)
			scanf("%d %d",&like[i][0],&like[i][1]);
		int ans = Binary_search();
		printf("%d\n",ans);
	}
}
