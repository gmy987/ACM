/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-08 19:04
*
* Filename: hdu2102.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 15

using namespace std;
char board[2][maxn][maxn];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int sx,sy,ex,ey,sz,ez;
int n,m;
bool vis[2][maxn][maxn];
int t;
bool dfs( int x , int y , int z , int time )
{
    if(time>t) return false;
    if(x==ex&&y==ey&&z==ez) return true;
    for( int i = 0 ; i < 4 ; i++ )
    {
        int ay = y+dir[i][0],az = z+dir[i][1],ax;
        if(ay<n&&az<m&&ay>=0&&az>=0&&!vis[x][ay][az]&&board[x][ay][az]!='*')
        {
            vis[x][ay][az] = 1;
            if(board[x][ay][az] =='#')
            {
                ax=x^1;
                if(!vis[ax][ay][az]&&board[ax][ay][az]!='*'&&board[ax][ay][az]!='#')
                {
                    vis[ax][ay][az] = 1;
                    if(dfs(ax,ay,az,time+1)) return true;
                    vis[ax][ay][az] = 0;
                }
            }
            else if(dfs(x,ay,az,time+1)) return true;
            vis[x][ay][az] = 0;
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&t);
        for( int i = 0 ;i < 2 ; i++ )
            for( int j = 0 ; j < n ; j++ )
                scanf("%s",board[i][j]);
        for( int i = 0 ; i < 2 ; i++ )
            for( int j = 0 ; j < n ; j++ )
                for( int k = 0 ; k < m ; k++ )
                    if(board[i][j][k]=='S') sx=i,sy=j,sz=k;
                    else if(board[i][j][k]=='P') ex=i,ey=j,ez=k;
        memset(vis,0,sizeof(vis));
        vis[sx][sy][sz]=1;
        printf(dfs(sx,sy,sz,0)?"YES\n":"NO\n");
    }
    return 0;
}
