#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;
int dir[8][2] = {{2,-1},{-2,1},{2,1},{-2,-1},{1,-2},{1,2},{-1,-2},{-1,2}};
struct Node
{
    int x,y,step;
};

int vis[10][10];
int sx,sy,ex,ey;
bool judge(int x, int y)
{
    return x>0&&x<=8&&y>0&&y<=8&&!vis[x][y];
}
int bfs()
{
    memset(vis,0,sizeof(vis));
    Node u;
    u.x = sx,u.y = sy,u.step = 0;
    queue<Node> q;
    q.push(u);
    vis[sx][sy] = 1;
    while(!q.empty())
    {
        Node v;
        u = q.front();
        q.pop();
        if( u.x == ex && u.y == ey )
            return u.step;
        for( int i = 0 ; i < 8 ; i++ )
        {
            int ax = u.x + dir[i][0];
            int ay = u.y + dir[i][1];
            if(judge(ax,ay))
            {
                v.x = ax;
                v.y = ay;
                vis[v.x][v.y] = 1;
                v.step = u.step + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    char m[2],n[2];
    while(~scanf("%s%s",&m,&n))
    {
        sy = m[0]-'a'+1;
        sx = m[1]-'0';
        ey = n[0]-'a'+1;
        ex = n[1]-'0';
        printf("To get from %s to %s takes %d knight moves.\n",m,n,bfs());
    }
}
