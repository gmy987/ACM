/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-07 13:18
*
* Filename: hdu1175.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 1005

using namespace std;
int n,m;
int board[maxn][maxn];
int sx,sy,ex,ey,q;
bool vis[maxn][maxn];
int dir[4][2]={1,0,0,1,0,-1,-1,0};
bool dfs(int x,int y,int d,int pre)
{
    if(d==2&&x!=ex&&y!=ey) return false;
    if(d>2) return false;
    if(x==ex&&y==ey) return true;
    for( int i = 0 ; i < 4 ; i++ )
    {
        int ax = x+dir[i][0],ay=y+dir[i][1];
        if( ax > 0 && ay > 0 && ax <= n && ay <= m && !vis[ax][ay] && (board[ax][ay] == 0 || (ax==ex&&ay==ey)))
        {
            vis[ax][ay] = 1;
            if(dfs(ax,ay,(pre+i==3||pre==-1||pre==i)?d:d+1,i))
                return true;
            vis[ax][ay] = 0;
        }
    }
    return false;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= m ; j++ )
                scanf("%d",&board[i][j]);
        scanf("%d",&q);
        while(q--)
        {
            memset(vis,0,sizeof(vis));
            scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
            if(board[sx][sy]!=board[ex][ey]||board[sx][sy]==0||board[ex][ey]==0)
            {
                printf("NO\n");
                continue;
            }
            vis[sx][sy] = 1; 
            printf(dfs(sx,sy,0,-1)?"YES\n":"NO\n");
        }
    }

    return 0;
}
