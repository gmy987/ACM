#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//int dir2[4][2] = {}
char road[50][50],step,m,n,xs,ys;
bool vis[50][50];

struct Node{
    int x,y,dist;
};

int bfs( int x, int y)
{
    memset(vis,0,sizeof(vis));
    queue<Node> q;
    Node u;
    u.x = x;
    u.y = y;
    vis[x][y] = true;
    u.dist =1;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if( road[u.x][u.y]=='E')
            return u.dist;
        for( int i = 0 ; i < 4 ; i++ )
        {
            Node v;
            v.x = u.x+dir[i][0];
            v.y = u.y + dir[i][1];
            if( v.x>=0 && v.y >= 0 && v.x < n && v.y < m && road[v.x][v.y]!='#' && !vis[v.x][v.y] ){
                vis[v.x][v.y] = true;
                v.dist = u.dist+1;
                q.push(v);
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while( t-- )
    {
        memset(road,0,sizeof(road));
        scanf("%d%d",&m,&n);
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%s",road[i]);
            for( int j = 0 ; j < m ; j++ )
                if( road[i][j]=='S')
                {
                    xs = i;
                    ys = j;
                }
        }
        printf("%d\n",bfs(xs,ys));
    }
}
