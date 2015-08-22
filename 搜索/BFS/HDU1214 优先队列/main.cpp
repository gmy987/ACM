//优先队列在BFS中的应用
//优先队列特点：最高进先出。即优先级高的会在队列开头，先被删除。
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;
char map[250][250];
int dir[4][2] = {{-1,0},{0,1},{0,-1},{1,0}},vis[250][250],m,n,sx,sy;
struct Node
{
    int x , y , minute ;
    //将b设为优先级较高的。
    friend bool operator < ( Node a , Node b )
    {
        return a.minute > b.minute;
    }
};

bool judge ( int x , int y )
{
    return x>=0&&y>=0&&x<n&&y<m&&!vis[x][y]&&map[x][y]!='#';
}
int bfs( int x , int y)
{
    Node u;
    u.x = x;
    u.y = y;
    u.minute = 0;
    vis[x][y] = 1;
    priority_queue<Node> q;
    q.push(u);
    while(!q.empty())
    {
        Node v;
        u = q.top();
        q.pop();
        if(map[u.x][u.y]=='a')
            return u.minute;
        for( int i = 0 ; i < 4 ; i++ )
        {
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            if(judge(v.x,v.y))
            {
                vis[v.x][v.y] = 1;
                if(map[v.x][v.y] == 'x')
                    v.minute = u.minute + 2;
                else
                    v.minute = u.minute + 1;
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(!n&&!m) break;
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        for( int i = 0 ; i < n ; i ++ )
        {
            scanf("%s",map[i]);
            for( int j = 0 ; j < m ; j++ )
            {
                if( map[i][j] == 'r')
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        int m = bfs(sx,sy);
        if( m!=-1 )
            printf("%d\n",m);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
}
