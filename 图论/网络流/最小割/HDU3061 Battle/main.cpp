#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 0x7fffffff
#define MAXM 600000
#define MAXN 2000

using namespace std;
int head[MAXN],dis[MAXN],cnt,T;
int m,n;
struct Edge{
	int to,next,cap;
}edge[MAXM];
void addedge( int u , int v , int cap )
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	edge[cnt].cap = cap;
	head[u] = cnt++;
	edge[cnt].to = u;
	edge[cnt].next = head[v];
	edge[cnt].cap = 0;
	head[v] = cnt++;
}
bool bfs()
{
	memset( dis , 0xff , sizeof(dis));
	dis[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for( int i = head[u] ; ~i ; i = edge[i].next )
		{
			int v = edge[i].to , cap = edge[i].cap;
			if( dis[v] < 0 && cap )
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
	if( x == T )
		return low;
	int a , i ;
	for( i = head[x] ; ~i ; i = edge[i].next )
	{
		int v = edge[i].to , cap = edge[i].cap;
		if( dis[v] == dis[x] + 1 && cap && ( a = dfs( v , min(low,cap))))
		{
			edge[i].cap -= a;
			edge[i^1].cap += a;
			return a;
		}
	}
	return 0;
}
int dinic()
{
	int ans = 0;
	while(bfs())
		ans += dfs( 0 ,  INF );
	return ans;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		cnt = 0 , T = n+1;
		memset( head , 0xff , sizeof(head));
		int i , j , a , b , sum = 0;
		for( i = 1 ; i <= n ; i++ )
		{
			scanf("%d",&a);
			if( a > 0 )
			{
				sum += a;
				addedge( i , T , a );
			}
			else
				addedge( 0 , i , -a );
		}
		for( i = 1 ; i <= m ; i++ )
		{
			scanf("%d%d",&a,&b);
		addedge( a , b ,INF );
		}
	}
}
