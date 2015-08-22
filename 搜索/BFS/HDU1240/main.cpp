#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int dir[6][3] = {{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0}};
struct Node
{
    int x , y,z,step;
};
char map[11][11][11];
int sx,sy,sz,ex,ey,ez,n,vis[11][11][11];
bool judge ( int x , int y , int z )
{
    return x>=0&&y>=0&&z>=0&&x<n&&y<n&&z<n&&map[x][y][z]!='X'&&!vis[x][y][z];
}
int bfs( int x , int y , int z )
{
    Node u;
    u.x = x,u.y = y,u.z = z,u.step = 0;
    vis[x][y][z] = 1;
    queue<Node> q;
    q.push(u);
    while(!q.empty())
    {
        Node v;
        u = q.front();
        q.pop();
        if( u.x == ex && u.y == ey && u.z == ez )
            return u.step;
        for( int i = 0 ; i < 6 ; i++ )
        {
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            v.z = u.z + dir[i][2];
            if(judge(v.x,v.y,v.z))
            {
                v.step = u.step + 1;
                vis[v.x][v.y][v.z] = 1;
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    char a[10];
    while(~scanf("%s%d",a,&n))
    {
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                scanf("%s",map[i][j]);
        scanf("%d%d%d%d%d%d",&sz,&sy,&sx,&ez,&ey,&ex);
        scanf("%s",a);
        int result = bfs(sx,sy,sz);
        if( result!=-1)
            printf("%d %d\n",n,result);
        else
            printf("NO ROUTE\n");
    }

}
