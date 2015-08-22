#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int map[30][30];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int sx,sy,w,h,step,ex,ey,steps;

bool judge( int x , int y )
{
    return x>=0&&x<h&&y>=0&&y<w&&map[x][y]!=1;
}

void dfs( int x , int y )
{
    if( step > 10 )
        return;
    for( int i = 0 ; i < 4 ; i++ )
    {
        bool ok = false;
        int ax = x + dir[i][0],ay = y + dir[i][1];
        while( judge( ax , ay ))
        {
            ok = true;
            if( ax == ex && ay == ey )
                if( steps > step ){
                    steps = step;
            }
            ax+=dir[i][0];
            ay+=dir[i][1];
        }
        if( map[ax][ay] == 1 && ok )
        {
            map[ax][ay] = 0;
            step++;
            dfs( ax - dir[i][0] , ay - dir[i][1] );
            step--;
            map[ax][ay] = 1;
        }
    }
}

int main()
{
    while(~scanf("%d%d",&w,&h))
    {
        if(!w&&!h) break;
        memset(map,0,sizeof(map));
        for( int i = 0 ; i < h ; i++ )
            for( int j = 0 ; j < w ; j++ )
            {
                scanf("%d",&map[i][j]);
                if( map[i][j] == 2 )
                {
                    sx = i;
                    sy = j;
                }
                if( map[i][j] == 3 )
                {
                    ex = i;
                    ey = j;
                }
            }

        step = 1;
        steps = 1000000;
        dfs(sx,sy);
        printf("%d\n",steps>10?-1:steps);
    }

}
