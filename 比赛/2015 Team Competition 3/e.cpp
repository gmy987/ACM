#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define maxn 105

using namespace std;
int dir1[6][2]={{0,-1},{0,1},{-1,0},{1,0},{-1,1},{1,1}};
int dir2[6][2]={{0,-1},{0,1},{-1,-1},{1,-1},{-1,0},{1,0}};
struct Node{
    int x,y,turn;
    int mp;
};
int state[maxn][maxn][10],board[maxn][maxn],vis[maxn][maxn];
void make(int x, int y , int num)
{
    if( num > 512 )
    {
        state[x][y][2] = 1;
        num-=512;
    }
    if( num > 256 )
    {
        state[x][y][0] = 1;
        num-=256;
    }
    if( num > 128 )
    {
        state[x][y][3] = 1;
        num-=128;
    }
    if( num > 64 )
    {
        state[x][y][5] = 1;
        num-=64;
    }
    if( num > 32 )
    {
        state[x][y][1] = 1;
        num -= 32;
    }
    if( num > 16 )
    {
        state[x][y][4] = 1;
        num -= 16;
    }
    if( num > 8 )
    {
        state[x][y][7] = 1;
        for( int i = 0 ; i < 6 ; i++ )
        {
            if(x&1) state[x+dir1[i][0]][y+dir1[i][1]][6] = 1;
            else state[x+dir2[i][0]][y+dir2[i][1]][6] = 1;
        }
        num -=8;
    }
    if( num > 4 )
    {
        state[x][y][8] = 1;
        num-=4;
    }
    if( num == 2 )
        board[x][y] = 200;
    else board[x][y] = 100;
}
int n,m,mps,sx,sy,ex,ey;
struct cmp{
    bool operator()(Node a, Node b )
    {
        return a.turn > b.turn || (a.turn == b.turn && a.mp < b.mp  );
    }
};
int bfs( int sx , int sy )
{
    priority_queue<Node,vector<Node>,cmp> q;
    Node u,v;
    u.x = sx , u.y = sy;
    u.turn = 1;
    u.mp = mps;
    vis[sx][sy] = 1;
    q.push(u);
    while(!q.empty())
    {
        u = q.top();
        q.pop();
        for( int i = 0 ; i < 6 ; i++ )
        {
            int ax,ay;
            if(u.x&1) ax = u.x + dir1[i][0],ay = u.y + dir1[i][1];
            else ax = u.x + dir2[i][0] , ay = u.y + dir2[i][1];
            if( ax == ex && ay == ey )
                return u.turn;
            if( ax >= 0 && ay >= 0 && ax < n && ay < m && !vis[ax][ay] )
            {
                vis[ax][ay] = 1;
                if( state[ax][ay][7] )
                    continue;
                if( state[u.x][u.y][6] && state[ax][ay][6])
                {
                    v.x = ax,v.y=ay,v.mp = mps,v.turn = u.turn+1;
                    q.push(v);
                }
                else if(state[u.x][u.y][8]&&state[ax][ay][8])
                {
                    v.x = ax,v.y = ay;
                    if( u.mp - 25 <= 0 )
                    {
                        v.turn = u.turn + 1;
                        v.mp = mps;
                        q.push(v);
                    }
                    else
                    {
                        v.mp = u.mp - 25;
                        v.turn = u.turn;
                        q.push(v);
                    }
                }
                else if(state[u.x][u.y][i])
                {
                    v.x = ax,v.y=ay,v.turn=u.turn+1,v.mp=mps;
                    q.push(v);
                }
                else
                {
                    v.x = ax,v.y = ay;
                    if(u.mp-board[ax][ay]<=0)
                    {
                        v.turn = u.turn+1;
                        v.mp = mps;
                        q.push(v);
                    }
                    else
                    {
                        v.mp = u.mp - board[ax][ay];
                        v.turn = u.turn;
                        q.push(v);
                    }
                }
            }
        }
    }
    return -1;
}


int main()
{
    int t,num;
    scanf("%d",&t);
    for( int l = 1 ; l <= t ; l++ )
    {
        scanf("%d%d%d",&n,&m,&mps);
        memset( state , 0 , sizeof(state) );
        memset( vis , 0 , sizeof(vis) );
        mps*=100;
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ; j < m ; j++ )
            {
                scanf("%d",&num);
                make(i,j,num);
            }
        }
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        printf("Case %d: ",l);
        printf("%d\n",bfs(sx,sy));
    }
    return 0;
}
