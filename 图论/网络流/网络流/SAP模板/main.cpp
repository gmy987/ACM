int gap[MAXN],cur[MAXN],aug[MAXN],pre[MAXN];
int sap( int x , int T , int S )// x = T + 1
{
    int maxflow = 0 , u = S , v;
    int id , mindis;
    aug[S] = INF;
    pre[S] = -1;
    memset( dis , 0 , sizeof(dis));
    memset( gap , 0 , sizeof(gap));
    gap[S] = x;
    for( int i = S ; i <= n ; i++ )
        cur[i] = head[i];
    while(dis[S] < x )
    {
        int flag = 0;
        if( u == T )
        {
            maxflow += aug[T];
            for( v = pre[T] ; ~v ; v = pre[v])
            {
                id = cur[v];
                edge[id].cap -= aug[T];
                edge[id^1].cap += aug[T];
                aug[v] -= aug[T];
                if( edge[id].cap == 0)
                    u = v;
            }
        }
        for( int i = cur[u] ; ~i ; i = edge[i].next )
        {
            v = edge[i].to;
            if( edge[i].cap > 0 && dis[u] == dis[v] + 1)
            {
                flag = 1;
                pre[v] = u;
                cur[u] = i;
                aug[v] = min( aug[u] , edge[i].cap );
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
                v = edge[i].to;
                if( edge[i].cap > 0 && dis[v] < mindis )
                {
                    mindis = dis[v];
                    cur[u] = i;
                }
            }
            dis[u] = mindis+1;
            gap[dis[u]]++;
            if( u != S )
                u = pre[u];
        }
    }
    return maxflow;
}
