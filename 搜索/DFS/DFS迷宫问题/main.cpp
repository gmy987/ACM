#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char Map[52][52];
const int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};//方向，在走迷宫的时候经常用到
int m = 0 ,n = 0;
int zx = 0 , zy = 0;//起点的横纵坐标

int dfs(int x,int y)
{
    if( x < 0 || y < 0 || x >= n || y >= m )
        return 0;
    for( int i = 0 ; i < 4 ; i++ )
    {
        if('L'==Map[x+dir[i][0]][y+dir[i][1]])
            return 1;
        else if( Map[x+dir[i][0]][y+dir[i][1]]=='.')
        {
            Map[x+dir[i][0]][y+dir[i][1]] = '#';
            if( dfs( x+ dir[i][0] , y+dir[i][1]))
                return 1;
            Map[x+dir[i][0]][y+ dir[i][1]] = '.';
        }

    }
    return 0;
}

int main()
{
    while( ~scanf("%d%d",&n,&m))
    {
        getchar();
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < m ; j++ ){
                scanf("%c",&Map[i][j]);
                if(Map[i][j]=='Z')
                {
                    zx = i;
                    zy = j;
                }
            }
            getchar();
        }
        if( dfs(zx,zy))
            printf("LK has a good life\n");
        else
            printf("Mission Failed\n");
    }
}
