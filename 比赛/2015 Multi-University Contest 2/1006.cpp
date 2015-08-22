#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int board[10][10];
int n,m;
int vis[10];
int ans;
void dfs( int x , int y )
{
    if( x > n ) ans++;
    else if( y > n ) 
    {
        if( vis[x] )
            return;
        dfs(x+1,x+2);
    }
    else
    {
        if(board[x][y])
        {
            vis[x]++;
            vis[y]++;
            dfs(x,y+1);
            vis[x]-=2;
            vis[y]-=2;
            dfs(x,y+1);
            vis[x]++;
            vis[y]++;
        }
        else dfs(x,y+1);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(board,0,sizeof(board));
        int u,v;
        for( int i = 0;  i < m ; i++ )
        {
            scanf("%d%d",&u,&v);
            board[u][v] = board[v][u] = 1;
        }
        memset( vis , 0 , sizeof(vis) );
        ans = 0;
        dfs(1,2);
        printf("%d\n",ans);
    }
    return 0;
}
