#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 25

using namespace std;
int dir[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int ans;
int n,m;
int vis[MAXN][MAXN];
char board[MAXN][MAXN];
void dfs( int x , int y )
{
    for( int i = 0 ; i < 4 ; i++ )
    {
        int ax = x + dir[i][0] , ay = y + dir[i][1];
        if( ax >= 0 && ay >= 0 && ax < n && ay < m && (!vis[ax][ay]) && board[ax][ay] == '.')
        {
            ans++;
            vis[ax][ay] = 1;
            dfs(ax,ay);
        }
    }
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        if( n == 0 && m == 0 )
            break;
        memset( vis , 0 , sizeof(vis));
        memset( board , 0 , sizeof(board) );
        ans=1;
        int sx,sy;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%s",&board[i]);
            for( int j = 0 ; j < m ; j++ )
                if( board[i][j] == '@' )
                {
                    sx = i;
                    sy = j;
                }
        }
        dfs( sx , sy );
        printf("%d\n",ans);
    }
    return 0;
}
