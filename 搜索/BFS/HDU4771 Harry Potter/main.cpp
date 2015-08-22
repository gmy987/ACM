#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
struct Node
{
    int x , y , step;
}node[10];
int n,m,k,vis[250][250],ans;
char map[250][250];
int tab[10][10],vist[10];
int bfs( int a , int b )
{
    memset( vis , 0 , sizeof(vis) );
    queue<Node> q;
    Node u;
    u.x = node[a].x , u.y = node[a].y , u.step = 0;
    vis[u.x][u.y] = 1;
    q.push(u);
    while(!q.empty())
    {
        Node v;
        u = q.front();
        q.pop();
        if( u.x == node[b].x && u.y == node[b].y )
            return u.step;
        for( int i = 0 ; i < 4 ; i++ )
        {
            int ax = u.x + dir[i][0] , ay = u.y + dir[i][1];
            if( ax >= 0 && ay >= 0 && ax < n && ay < m && map[ax][ay] !='#'&&!vis[ax][ay])
            {
                v.x = ax , v.y = ay , v.step = u.step + 1;
                vis[ax][ay] = 1;
                q.push(v);
            }
        }
    }
    return -1;
}
void dfs( int index , int sum , int cnt )
{
    if( cnt == k )
    {
        ans = min( ans , sum );
        return;
    }
    for( int i = 1 ; i <= k ; i++ )
        if(!vist[i])
        {
            vist[i] = 1;
            dfs( i , sum + tab[index][i] , cnt + 1);
            vist[i] = 0;
        }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(!n&&!m) break;
        int i , j ;
        for( i = 0 ; i < n ; i++ )
        {
            scanf("%s",map[i]);
            for( j = 0 ; j < m ; j++ )
            {
                if( map[i][j] == '@')
                {
                    node[0].x = i;
                    node[0].y = j;
                }
            }
        }
        scanf("%d",&k);
        for( i = 1 ; i <= k ; i++ )
        {
            scanf("%d%d",&node[i].x,&node[i].y);
            node[i].x--,node[i].y--;
        }
        bool flag = false;
        for( i = 0 ; i <= k ; i++ )
            for( j = i + 1 ; j <= k ; j++ )
            {
                tab[i][j] = tab[j][i] = bfs(i,j);
                if(tab[i][j] == -1)
                {
                    flag = true;
                    break;
                }
            }
        if(flag)
            printf("-1\n");
        else
        {
            ans = INF;
            memset( vist , 0 , sizeof(vist));
            vist[0] = 1;
            dfs(0,0,0);
            printf("%d\n",ans);
        }
    }
}
