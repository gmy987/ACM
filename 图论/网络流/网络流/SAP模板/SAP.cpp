int dis[MAXN],gap[MAXN],aug[MAXN],pre[MAXN],cur[MAXN];
int SAP( int x , int s , int t)
{
	int mindis , maxflow = 0 , id , u = s;
	memset( dis , 0 , sizeof( dis ));
	memset( gap , 0 , sizeof( gap ));
	gap[s] = x;
	aug[s] = INF;
	pre[s] = -1;
	for( int i = s ; i <= t ; i++ )
		cur[i] = head[i];
	while( dis[s] < x )
	{
		int flag = 1;
		if( u == t )
		{
			maxflow += aug[t];
			for( int v = pre[t] ; ~v ; v = pre[v])
			{
				id = cur[v];
				edge[id].cap -= aug[t];
				edge[id^1].cap += aug[t];
				aug[v] -= aug[t];
				if( edge[id].cap == 0 )
					u = v;
			}
		}
		for( int i = cur[u] ; ~i ; i = edge[i].next )
		{
			int v = edge[i].to , cap = edge[i].cap;
			if( cap && dis[u] == dis[v] + 1 )
			{
				flag = 1;
				pre[v] = u;
				cur[u] = i;
				aug[v] = min( cap , aug[u]);
				u = v;
				break;
			}
		}
		if( !flag )
		{
			if( --gap[dis[u]] == 0 )
				break;
			cur[u] = head[u];
			mindis = x;
			for( int i = head[u] ; ~i ; i = edge[i].next )
			{
				int v = edge[i].to , cap = edge[i].cap;
				if( cap && dis[v] > mindis )
				{
					mindis = dis[v];
					cur[u] = i;
				}
			}
			dis[u] = mindis + 1;
			gap[dis[u]]++;
			if( u!=s )
				u = pre[u];
		}
	}
	return maxflow;
}
