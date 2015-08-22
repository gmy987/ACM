#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int dir[8][2] = {{-1,0},{1,0},{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1}};
int vis[105][105];
int cnt,m,n;
char map[105][105];
bool dfs(int i, int j)
{
    if(i<0||j<0||i>=m||j>=n||vis[i][j]||map[i][j] =='*')
        return false;
    vis[i][j] = 1;
    for( int k = 0 ; k < 8 ; k++ )
    {
        dfs(i+dir[k][0],j+dir[k][1]);
    }
    return true;
}
int main()
{
    while(~scanf("%d%d",&m,&n)&&m&&n)
    {
        cnt = 0;
        memset(map,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        for(int i = 0 ; i < m ; i++ )
            scanf("%s",&map[i]);
        for( int i = 0 ; i < m ; i++ )
            for( int j = 0 ; j < n ; j++ )
                if( dfs(i,j))
                    cnt++;
        printf("%d\n",cnt);
    }
}
