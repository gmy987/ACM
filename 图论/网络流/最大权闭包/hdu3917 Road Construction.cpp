#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
#define maxn 50010
#define maxm 1000000
#define INF 0x7fffffff
using namespace std;
struct Edge{
	int to,next,cap;
}edge[maxm];
int head[maxn],dis[maxn],gap[maxn],cur[maxn],pre[maxn],aug[maxn];
int cnt , n , m ,k;
void addedge( int u , int v , int cap )
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	edge[cnt].cap = cap;
	head[u] = cnt++;
	edge[cnt].to = u;
	edge[cnt].cap = 0;
	edge[cnt].next = head[v];
	head[v] = cnt++;
}
vector<int> st[maxn],to[maxn];
int val[maxn];
int SAP( int x , int s , int t)
{
	int maxflow = 0 , mindis , id , u = s;
	memset( dis , 0 , sizeof(dis));
	memset( gap , 0 , sizeof(gap));
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
			for( int v = pre[t]; ~v ; v = pre[v])
			{
				id = cur[v];
				edge[id].cap -= aug[t];
				edge[id^1].cap += aug[t];
				aug[v] -= aug[t];
				if( edge[id].cap == 0   )
					u = v;
			}
		}
		for( int i = cur[u] ; ~i ; i = edge[i].next )
		{
			int v = edge[i].to , cap = edge[i].cap;
			if( cap && dis[u] == dis[v] + 1 )
			{
				flag = 1;
				cur[u] = i;
				pre[v] = u;
				aug[v] = min( cap , aug[u]);
				u = v;
				break;
			}
		}
		if(!flag)
		{
			if(--gap[dis[u]] == 0 )
				break;
			mindis = x;
			cur[u] = head[u];
			for( int i = head[u] ; ~i ; i = edge[i].next )
			{
				int v = edge[i].to;
				if( edge[i].cap  && dis[v] < mindis )
				{
					mindis = dis[v];
					cur[u] = i;
				}
			}
			dis[u] = mindis + 1;
			gap[dis[u]]++;
			if( u!= s)
				u = pre[u];
		}
	}
	return maxflow;
}
int main()
{
	while(~scanf("%d%d",&n,&m) && (n+m))
	{
		for( int i = 1 ; i <= n ; i++ )
		{
			st[i].clear();
			to[i].clear();
		}
		memset( head , 0xff , sizeof(head));
		cnt = 0 ;
		int a , b, d , c;
		int sum = 0, t = m+1;
		for( int i = 1 ; i <= m ; i++ )
			scanf("%d",&val[i]);
		scanf("%d",&k);
		for( int i = 1 ; i <= k ; i++ )
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			st[a].push_back(c);
			to[b].push_back(c);
			val[c] -= d;
		}
		for( int i = 1 ; i <= m ; i++ )
			if( val[i] > 0 )
			{
				sum += val[i];
				addedge( 0 , i , val[i]);
			}
			else
				addedge( i , t , -val[i]);
		for( int i = 1 ; i <= n ;i++)
		{
			for( int j = 0 ; j < st[i].size();j++)
				for( int l = 0 ; l < to[i].size() ; l++ )
				{
					addedge( to[i][l] , st[i][j] , INF);
				}
		}
//		cout << " aaaa " << endl;
		printf( "%d\n",sum-SAP(t+1,0,t));
	}
	return 0;
}
