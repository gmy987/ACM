#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int dir[8][2] = {{-1,1},{0,1},{1,1},{1,-1},{0,-1},{1,0},{-1,0},{-1,-1}};
int cnt,n,m;
bool flag;
char map[150][150];

void dfs( int x , int y )
{
    for( int i = 0 ; i < 8 ; i++ )
    {
        int ax = x + dir[i][0] , ay = y + dir[i][1];
        if(ax >= 0 && ay >= 0 && ax < n && ay < m && map[ax][ay] == 'W' )
        {
            map[ax][ay] = '.';
            dfs(ax,ay);
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        cnt = 0;
        //memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        for( int i = 0 ; i < n ; i++ )
            scanf("%s",map[i]);
        //for( int i = 0 ; i < n ; i++ )
          //  cout<<map[i]<<endl;

        for( int i = 0 ; i < n ; i++ )
            for ( int j = 0 ; j < m ; j ++ )
            {
                if(map[i][j] =='W' )
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        //for( int i = 0 ; i< n ; i++ )
           // cout<<map[i]<<endl;

        printf("%d\n",cnt);
    }
}
