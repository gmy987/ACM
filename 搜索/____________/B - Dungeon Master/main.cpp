#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
struct Node
{
    int x , y , z , step;
};
int l,r,c,sx,sy,sz,vis[35][35][35];
int dir[6][3] = {{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
char map[35][35][35];
bool judge( int x , int y , int z )
{
    return x>=0&&y>=0&&z>=0&&x<l&&y<r&&z<c&&!vis[x][y][z]&&map[x][y][z]!='#';
}
int bfs()
{
    Node u;
    u.x = sx , u.y = sy , u.z = sz , u.step = 0;
    queue<Node> q;
    q.push(u);
    vis[sx][sy][sz] = 1;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if( map[u.x][u.y][u.z] == 'E' )
            return u.step;
        Node v;
        for( int i = 0 ; i < 6 ; i++ )
        {
            int ax = u.x + dir[i][0] , ay = u.y + dir[i][1] , az = u.z + dir[i][2];
            if(judge(ax,ay,az))
            {
                v.x = ax,v.y = ay,v.z = az;
                v.step = u.step + 1;
                vis[ax][ay][az] = 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{//freopen("input.txt","r",stdin);
    while(~scanf("%d%d%d",&l,&r,&c))
    {
        if(!l&&!r&&!c) break;
        memset( vis , 0 ,sizeof(vis));
        memset ( map , 0 , sizeof( map ));
        for( int i = 0 ; i < l ; i++ )
        {
            for( int j = 0 ; j < r ; j++ )
            {
                scanf("%s",map[i][j]);
                for( int k = 0 ; k < c ; k++ )
                {
                    if( map[i][j][k] == 'S')
                    {
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                }
            }
        }
        int cnt = bfs();
        if(cnt!=-1)
            printf("Escaped in %d minute(s).\n",cnt);
        else
            printf("Trapped!\n");
    }
}
