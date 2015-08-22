#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAXN 300
#define INF 0x7fffffff

using namespace std;
int n,m;
char ma[MAXN][MAXN];
int vis[MAXN][MAXN];
int yy[MAXN][MAXN] , mm[MAXN][MAXN];
struct Node{
    int x,y,step;
};
int dir[4][2] = { 0 , 1 , 0 , -1 , -1 , 0 , 1 , 0 };

void bfs( int sx , int sy , int mark  )
{
    queue<Node> q;
    Node u;
    u.x = sx , u.y = sy , u.step = 0;
    q.push(u);
    vis[sx][sy] = 1;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        Node v;
        for( int i = 0 ; i < 4 ; i++ )
        {
            int ax = u.x + dir[i][0] , ay = u.y + dir[i][1];
            if( ax >= 0 && ay >= 0 && ax < n && ay < m && ma[ax][ay] != '#' && !vis[ax][ay] )
            {
                v.x = ax;
                v.y = ay;
                v.step = u.step + 1;
                vis[ax][ay] = 1;
                if( ma[ax][ay] == '@' )
                {
                    if( mark == 1 )
                        yy[ax][ay] = v.step;
                    else
                        mm[ax][ay] = v.step;
                }
                q.push(v);
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( yy , 0 , sizeof( yy ) );
        memset( mm , 0 , sizeof( mm ) );
        for( int i = 0 ; i < n ; i++ )
            scanf("%s",ma[i]);
        int sx,sy,sx2,sy2;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
            {
                if( ma[i][j] == 'Y' )
                {
                    sx = i;
                    sy = j;
                }
                else if( ma[i][j] == 'M')
                {
                    sx2 = i;
                    sy2 = j;
                }
            }
        memset( vis , 0 , sizeof(vis) );
        bfs( sx , sy , 1 );
        memset( vis , 0 , sizeof(vis) );
        bfs( sx2 , sy2 , 2 );
        int mini = INF;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
            {
                if( yy[i][j] && mm[i][j] )
                {
                    int temp = yy[i][j] + mm[i][j];
                    mini = min( mini , temp );
                }
            }
        printf("%d\n",mini*11);
    }
    return 0;


}
