#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int r,c,sx,sy,bx,by,visp[25][25],visb[25][25];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char push[] = {'E' , 'W' , 'S' ,'N' };
char walk[] = {'e','w','s','n'};
string a;
struct Node
{
    int px,py,bx,by;
    string ans;
};
string path;

bool judge ( int x , int y )
{
    return x >=0 && x < r && y>=0 && y < c;
}
char board[25][25];

bool bfs2( int sx , int sy , int ex , int ey , int bx , int by )
{
    memset(visp,0,sizeof(visp));
    Node u;
    u.px = sx , u.py = sy , u.ans = "";
    queue<Node> q;
    q.push(u);
    visp[bx][by] = 1;
    visp[sx][sy] = 1;
    while(!q.empty())
    {
        Node v;
        u = q.front();
        q.pop();
        if( u.px == ex && u.py == ey )
        {
            a = u.ans;
            return true;
        }
        for( int i = 0 ; i < 4 ; i++ )
        {
            int ax = u.px + dir[i][0] , ay = u.py + dir[i][1];
            if( judge(ax,ay) && !visp[ax][ay] && board[ax][ay] != '#' )
            {
                visp[ax][ay] = 1;
                v.px = ax , v.py = ay;
                v.ans = u.ans + walk[i];
                q.push(v);
            }
        }
    }
    return false;
}
bool bfs1()
{
    Node u;
    u.px = sx , u.py = sy , u.bx = bx , u.by = by , u.ans = "";
    queue<Node> q;
    q.push(u);
    visb[u.bx][u.by] = 1;
    while(!q.empty())
    {
        Node v;
        u = q.front();
        q.pop();
        if(board[u.bx][u.by] == 'T')
        {
            path = u.ans;
            return true;
        }
        for( int i = 0 ; i < 4 ; i++ )
        {
            int nextx = u.bx + dir[i][0] , nexty = u.by + dir[i][1];
            int prex = u.bx - dir[i][0] , prey = u.by - dir[i][1];
            a = "";
            if(judge(nextx,nexty)&&judge(prex,prey)&&board[nextx][nexty]!='#'&&board[prex][prey]!='#'&&!visb[nextx][nexty])
            {
                if(bfs2(u.px,u.py,prex,prey,u.bx,u.by))
                {
                    visb[nextx][nexty] = 1;
                    v.px = u.bx , v.py = u.by;
                    v.bx = nextx , v.by = nexty;
                    v.ans = u.ans + a + push[i];
                    q.push(v);
                }
            }
        }
    }
    return false;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int cnt = 1;
    while(~scanf("%d%d",&r,&c)&&r&&c)
    {
        memset( board , 0 , sizeof( board ));
        memset( visb , 0 , sizeof( visb ));
        for( int i = 0 ; i < r ; i++ )
        {
            scanf("%s",board[i]);
            for( int j = 0 ; j < c ; j++ )
            {
                if(board[i][j] == 'S' )
                {
                    sx = i;
                    sy = j;
                }
                if(board[i][j] == 'B' )
                {
                    bx = i;
                    by = j;
                }
            }
        }
        //for( int i = 0 ; i < r ; i++ )
          //  cout<<board[i]<<endl;
        path = "";
        printf("Maze #%d\n",cnt);
        cnt++;
        if(bfs1())
            cout<<path<<endl;
        else
            printf("Impossible.\n");
        printf("\n");
    }
}
