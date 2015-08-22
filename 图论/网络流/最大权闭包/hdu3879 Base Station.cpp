#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define MAXM 1000000
#define MAXN 65000
#define INF 0x7fffffff
using namespace std;
struct Edge{
	int to,next,cap;
}edge[MAXM];
int head[MAXN],n,m,T,cnt;

void addedge( int u , int v , int cap )
{
	edge[cnt].to = v;
	edge[cnt].cap = cap;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	edge[cnt].to = u;
	edge[cnt].next = head[v];
	edge[cnt].cap = 0;
	head[v] = cnt++;
}
int dis[MAXN],cur[MAXN],gap[MAXN],aug[MAXN],pre[MAXN];
int SAP( int x , int s , int t )
{
	int maxflow = 0 , mindis;
	memset( gap , 0 , sizeof(gap));
	memset( dis , 0 , sizeof( dis ));
	int u = s;
	gap[s] = x;
	aug[s] = INF;
	pre[s] = -1;
	for( int i = s ; i <= t ; i++ )
		cur[i] = head[i];
	while( dis[s] < x )
	{
		int flag = 0;
		if( u == t )
		{
			maxflow += aug[t];
			for( int v = pre[t];~v;v = pre[v])
			{
				int id = cur[v];
				edge[id].cap -= aug[t];
				edge[id^1].cap += aug[t];
				aug[v] -= aug[t];
				if( edge[id].cap == 0 )
					u = v;
			}
		}
		for( int i = cur[u];~i ; i = edge[i].next )
		{
			int v = edge[i].to , cap = edge[i].cap;
			if( cap && dis[u] == dis[v] + 1 )
			{
				pre[v] = u;
				cur[u] = i;
				flag = 1;
				aug[v] = min( aug[u] , cap );
				u = v;
				break;
			}
		}
		if( !flag )
		{
			if(--gap[dis[u]] == 0 )
				break;
			mindis = x;
			cur[u] = head[u];
			for( int i = head[u] ; ~i ; i = edge[i].next )
			{
				int v = edge[i].to , cap = edge[i].cap;
				if( cap && dis[v] < mindis)
				{
					mindis = dis[v];
					cur[u] = i;
				}
			}
			dis[u] = mindis + 1;
			gap[dis[u]]++;
			if( u!= s )
				u = pre[u];
		}
	}
	return maxflow;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		int i , j , a ,b, c;
		cnt = 0, T = n+m+1 ; 
		int sum = 0;
		memset( head , 0xff , sizeof( head ));
		for( i = 1 ; i <= n ; i++ )
		{
			scanf( "%d",&a);
			addedge( i+m , T , a );
		}
		for( i = 1 ; i <= m ; i++ )
		{
			scanf("%d%d%d",&a,&b,&c);
			addedge( 0 , i ,  c);
			addedge( i , a+m , INF );
			addedge( i , b+m , INF);
			sum+=c;
		}
		printf("%d\n",sum-SAP(T+1,0,T));
	}
	return 0;
}
