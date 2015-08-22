#include <cstring>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int vis[9][9],board[9][9],sx,sy,ex,ey;
int dir[8][2] = {{-1,2},{1,-2},{1,2},{-1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
struct Node{
    int step,x,y;
};
int bfs()
{
    if(sx==ex&&sy==ey)
        return 0;
    memset( vis , 0 , sizeof( vis ));
    memset ( board , -1 , sizeof( board ));
    Node f , b ;
    f.x = sx , f.y = sy , f.step = 0;
    b.x = ex , b.y = ey,b.step = 1;
    queue<Node> front_q;
    queue<Node> back_q;
    vis[sx][sy] = 1;
    vis[ex][ey] = 2;
    board[sx][sy] = 0;
    board[ex][ey] = 1;
    front_q.push(f);
    back_q.push(b);
    while(!front_q.empty()||!back_q.empty())
    {
        if(!front_q.empty())
        {
            Node v;
            f = front_q.front();
            front_q.pop();
            for( int i = 0 ; i < 8 ; i++ )
            {
                int ax = f.x + dir[i][0];
                int ay = f.y + dir[i][1];
                if( ax >= 0 && ax < 8 && ay >=0 && ay < 8 && vis[ax][ay] != 1)
                {
                    if(vis[ax][ay]==0)
                    {
                        v.x = ax , v.y = ay;
                        v.step = f.step+1;
                        board[ax][ay] = v.step;
                        vis[ax][ay] = 1;
                        front_q.push(v);
                    }
                    else
                        return f.step+board[ax][ay];
                }
            }
        }
        if(!back_q.empty())
        {
            Node v;
            b = back_q.front();
            back_q.pop();
            for( int i= 0 ; i < 8 ; i++ )
            {
                int ax = b.x + dir[i][0];
                int ay = b.y + dir[i][1];
                if( ax >= 0 && ay >= 0 && ax < 8 && ay < 8 && vis[ax][ay] != 2 )
                {
                    if( vis[ax][ay] == 0 )
                    {
                        v.x = ax , v.y = ay;
                        v.step = b.step + 1;
                        board[ax][ay] = v.step;
                        vis[ax][ay] = 2;
                        back_q.push(v);
                    }
                    else
                        return b.step + board[ax][ay];
                }
            }
        }
    }
    return -1;
}
int main()
{
    //freopen( "input.txt","r",stdin);
    char a[2],b[2];
    while(~scanf("%s",a))
    {
        scanf("%s",b);
        sx = a[1] - '1';
        sy = a[0] - 'a';
        ex = b[1] - '1';
        ey = b[0] - 'a';
        //cout<<a<<" "<<b<<endl;
        printf("To get from %s to %s takes %d knight moves.\n",a,b,bfs());
    }
}
