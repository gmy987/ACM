#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int l,r,c,sx,sy,sz;
char map[35][35][35];
int dir[6][3] = {{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
bool vist[35][35][35];
struct Node{
    int x,y,z,minute;
};
bool judge( int x,int y,int z)
{
    return !vist[x][y][z]&&x>=0&&x<l&&y>=0&&y<r&&z>=0&&z<c&&map[x][y][z]!='#';
}

int bfs(int x,int y,int z)
{
    memset(vist,0,sizeof(vist));
    queue<Node> q;
    Node u;
    u.x = x , u.y = y , u.z = z , u.minute = 0;
    q.push(u);
    vist[u.x][u.y][u.z] = true;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if( map[u.x][u.y][u.z] == 'E')
            return u.minute;
        for( int i = 0 ; i < 6 ; i++ )
        {
            Node v;
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            v.z = u.z + dir[i][2];
            if(judge(v.x,v.y,v.z))
            {
                vist[v.x][v.y][v.z] = true;
                v.minute = u.minute+1;
                q.push(v);
            }
        }
    }
    return 0;
}

int main()
{
    while(~scanf("%d%d%d",&l,&r,&c))
    {
        memset( map,0,sizeof(map));
        if(!l&&!r&&!c)  break;
        for(int i = 0 ; i < l ; i++ )
            for( int j = 0 ; j < r ; j++ )
            {
                scanf("%s",&map[i][j]);
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
        int step = bfs(sx,sy,sz);
        if(step)
            printf("Escaped in %d minute(s).\n",step);
        else
            printf("Trapped!\n");
    }
}
