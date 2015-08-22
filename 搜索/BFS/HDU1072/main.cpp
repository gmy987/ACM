#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}},map[10][10],t,m,n,sx,sy,vis[10][10];
struct Node{
    int x,y,minute,step;
};
int bfs( int x, int y )
{
    Node u;
    u.x = x,u.y = y;
    u.minute = 6,u.step = 0;
    queue<Node> q;
    q.push(u);
    //vis[u.x][u.y] = 1;
    while(!q.empty())
    {
        Node v;
        u = q.front();
        q.pop();
        if( map[u.x][u.y] == 3 && u.minute > 0)
            return u.step;
        if( u.minute == 1 ) continue;
        for( int i = 0 ; i < 4; i ++ )
        {
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            if( v.x >= 0 && v.y >= 0 && v.x < n && v.y < m && !vis[v.x][v.y] && map[v.x][v.y] != 0)
            {
                v.minute = u.minute - 1;
                //vis[v.x][v.y] = 1;
                v.step = u.step + 1;
                if( map[v.x][v.y] ==4 ){
                    vis[v.x][v.y] = 1;
                    v.minute = 6;
                }
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        for( int i = 0 ; i < n ; i ++ )
            for( int j = 0 ; j < m ; j ++ )
            {
                scanf("%d",&map[i][j]);
                if(map[i][j] == 2)
                {
                    sx = i;
                    sy = j;
                }
            }
        printf("%d\n",bfs(sx,sy));
    }
}
