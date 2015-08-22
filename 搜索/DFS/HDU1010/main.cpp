#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int m,n,t,step,vis[10][10],sx,sy,flag,ex,ey;
char map[10][10];

void dfs( int x , int y )
{
    if( step == t && map[x][y] == 'D')
    {
        flag = true;
        return;
    }
    if(flag)
        return;
    int temp = abs(x-ex)+abs(y-ey)-abs(step-t);
    if( temp>0||temp&1) return;
    for( int i = 0 ; i < 4 ; i++ )
    {
        int ax = x + dir[i][0];
        int ay = y + dir[i][1];
        if( !vis[ax][ay]&&ax>=0&&ay>=0&&ax<n&&ay<m&&step<t&&map[ax][ay]!='X')
        {
            step++;
            vis[ax][ay] = 1;
            dfs(ax,ay);
            if(flag)
                return;
            step--;
            vis[ax][ay] = 0;
        }
    }
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&t)&&n&&m&&t)
    {
        flag = false;
        step = 0;
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%s",&map[i]);
            for( int j = 0 ; j < m ; j++ )
            {
                if(map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                if(map[i][j]== 'D')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        //注意这里，要标记起点。因为这个一直WA，以后要注意。
        vis[sx][sy] = 1;
        dfs(sx,sy);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
