#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;
int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
char map[105][105];
int vis[105][105],n,m;
bool flag;
struct Node{
    int x , y , time,stay;
    friend bool operator < ( Node a , Node b)
    {
        return a.time > b.time;
    }
}pre[105][105];

void print( Node u ,Node v, int step )
{
    if( step == 1)
    {
        printf("%ds:(%d,%d)->(%d,%d)\n",step,v.x,v.y,u.x,u.y);
    }
    else if( u.stay != 0 )
    {
        u.stay-=1;
        print(u,v,step-1);
        printf("%ds:FIGHT AT (%d,%d)\n",step,u.x,u.y);
    }
    else
    {
        print( pre[u.x][u.y],pre[v.x][v.y],step-1);
        printf("%ds:(%d,%d)->(%d,%d)\n",step,v.x,v.y,u.x,u.y);
    }
}

void bfs ( int x , int y )
{
    Node u;
    u.x = x;
    u.y = y;
    u.stay = 1;
    u.time = 0;
    priority_queue<Node> q;
    q.push(u);
    vis[x][y] = 1;
    while(!q.empty())
    {
        Node v;
        u = q.top();
        q.pop();
        if( u.x == n -1 && u.y == m-1 )
        {
            flag = true;
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",u.time);
            print(u,pre[u.x][u.y],u.time);
            return;
        }
        for( int i = 0 ; i < 4 ; i++ )
        {
            int ax = u.x + dir[i][0];
            int ay = u.y + dir[i][1];
            if(ax>=0&&ay>=0&&ax<n&&ay<m&&map[ax][ay]!='X'&&!vis[ax][ay])
            {
                v.x = ax;
                v.y = ay;
                vis[ax][ay] = 1;
                pre[ax][ay] = u;
                if(map[ax][ay] == '.')
                {
                    v.stay = 0;
                    v.time = u.time + 1;
                }
                else
                {
                    v.stay = map[ax][ay] - '0';
                    v.time = u.time + 1 + v.stay;
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
        flag = false;
        memset(pre , 0 , sizeof(pre));
        memset(map , 0 , sizeof(map));
        memset(vis , 0 , sizeof(vis));
        for( int i = 0 ; i < n ; i ++ )
        {
            scanf("%s",map[i]);
        }
        bfs(0,0);
        if(!flag)
            printf("God please help our poor hero.\n");
        printf("FINISH\n");
    }
}
