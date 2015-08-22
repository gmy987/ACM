#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int w,h,vis[25][25],cnt,sx,sy;
char map[25][25];
void dfs( int x , int y )
{
    for( int i = 0 ; i < 4 ; i++ )
    {
        int ax = x + dir[i][0];
        int ay = y + dir[i][1];
        if( !vis[ax][ay] && ax >=0 && ay >=0 && ax < h && ay < w && map[ax][ay] == '.')
        {
            vis[ax][ay] = 1;
            cnt++;
            dfs(ax,ay);
        }
    }
}
int main()
{
    while(~scanf("%d%d",&w,&h)&&w&&h)
    {
        cnt = 1;
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        for( int i = 0 ; i < h ; i++ ){
            scanf("%s",&map[i]);
            for( int j = 0 ; j < w ; j++ )
                if(map[i][j]=='@')
                {
                    sx = i;
                    sy = j;
                }
        }
        dfs(sx,sy);
        printf("%d\n",cnt);
    }
}
