#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//E,S,W,N
int board[55][55],vis[55][55][4],sx,sy,ex,ey,n,m,sd;

struct Node{
    int x , y , d , step ;
};

int bfs()
{
    Node u;
    u.x = sx , u.y = sy , u.step = 0 , u.d = sd;
    queue<Node> q;
    q.push(u);
    vis[sx][sy][sd] = 1;
    while(!q.empty())
    {
        Node v;
        u = q.front();
        q.pop();
        if( u.x == ex && u.y == ey )
            return u.step;
        //d1,d2分别为当前方向可转向的方向。
        int d1 = ( u.d + 1 )%4 , d2 = ( u.d + 3 )%4;
        if(!vis[u.x][u.y][d1])
        {
            v.x = u.x;
            v.y = u.y;
            v.step = u.step+1;
            v.d = d1;
            q.push(v);
            vis[v.x][v.y][d1] = 1;
        }
        if(!vis[u.x][u.y][d2])
        {
            v.x = u.x;
            v.y = u.y;
            v.step = u.step+1;
            v.d = d2;
            vis[v.x][v.y][d2] = 1;
            q.push(v);
        }
        for ( int i = 1 ; i <= 3 ; i++ )
        {
            int ax = u.x + i*dir[u.d][0] , ay = u.y + i * dir[u.d][1];
            //注意不能等于零，因为机器人无法在边界行走。
            if ( ax <= 0 || ay <= 0 || ax >= n || ay >= m || board[ax][ay] == 1 ) break;
            if( !vis[ax][ay][u.d] )
            {
                v.x = ax;
                v.y = ay;
                v.step = u.step + 1;
                v.d = u.d;
                vis[ax][ay][v.d] = 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{//freopen("input.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        memset( board , 0 , sizeof(board) );
        memset( vis , 0 , sizeof(vis) );
        int temp;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ){
                scanf("%d",&temp);
                if( temp == 1 )
                    board[i][j] = board[i][j+1] = board[i+1][j] = board[i+1][j+1] = 1;
        }
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        char a[10];
        scanf("%s",a);
        switch(a[0])
        {
            case's': sd = 1; break;
            case'e': sd = 0; break;
            case'w': sd = 2; break;
            case'n': sd = 3; break;
        }
        printf("%d\n",bfs());
    }
    return 0;
}
