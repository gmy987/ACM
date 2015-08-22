#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
char map[25][25];
int vis[25][25],sx,sy,m,n;
struct Node
{
    int x,y,step;
    friend bool operator < ( Node a , Node b)
    {
        return a.step > b.step;
    }
};
int bfs( int x , int y )
{
    Node u;
    u.x = x , u.y = y , u.step = 0;
    vis[u.x][u.y] = 1;
    priority_queue<Node> q;
    q.push(u);
    while(!q.empty())
    {
        Node v;
        u = q.top();
        q.pop();
        if( map[u.x][u.y] == 'T')
            return u.step;
        for( int i = 0 ; i < 4 ; i++)
        {
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            if(v.x>=0&&v.y>=0&&v.x < m &&v.y < n&&map[v.x][v.y]!='*'&&!vis[v.x][v.y])
            {
                if(map[v.x][v.y]=='|')
                {
                    if(i==2||i==3)
                    {
                        v.step = u.step;
                        vis[v.x][v.y] = 1;
                        q.push(v);
                    }
                }
                else if( map[v.x][v.y] == '-')
                {
                    if( i == 0 || i == 1 )
                    {
                        v.step = u.step;
                        vis[v.x][v.y] = 1;
                        q.push(v);
                    }
                }
                else
                {
                    v.step = u.step + 1;
                    vis[v.x][v.y] = 1;
                    q.push(v);
                }
            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        memset( vis ,0 , sizeof(vis));
        memset ( map , 0 , sizeof( map ));
        for( int i = 0 ; i < m ; i ++ )
        {
            scanf("%s",map[i]);
            for( int j = 0 ; j < n ; j++ )
            {
                if( map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        printf("%d\n",bfs(sx,sy));
    }
}
