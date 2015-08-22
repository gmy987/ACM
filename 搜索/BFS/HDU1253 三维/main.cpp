#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int dir[6][3] = {{-1,0,0},{1,0,0},{0,1,0},{0,-1,0},{0,0,-1},{0,0,1}};
int vis[55][55][55],t,a,b,c,k;
int map[55][55][55];
struct Node
{
    int x , y , z , step;
};
bool judge ( int x , int y , int z )
{
    return x>=0&&y>=0&&z>=0&&x<a&&y<b&&z<c&&map[x][y][z]!=1&&!vis[x][y][z];
}
int bfs( int x , int y , int z )
{
    memset( vis , 0 , sizeof(vis));
    Node u;
    u.x = x , u.y = y , u.z = z , u.step = 0;
    vis[x][y][z] = 1;
    queue<Node> q;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if( u.x == a-1 && u.y == b-1 && u.z == c-1 && u.step <= t)
            return u.step;
        Node v;
        for( int i = 0 ; i < 6 ; i ++ )
        {
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            v.z = u.z + dir[i][2];
            if(judge(v.x,v.y,v.z))
            {
                vis[v.x][v.y][v.z] = 1;
                v.step = u.step+1;
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&t);

        for( int i = 0 ; i < a ; i++ )
            for ( int j = 0 ; j < b ; j++ )
                for( int m = 0 ; m < c ; m++ )
                    scanf("%d",&map[i][j][m]);
        printf("%d\n",bfs(0,0,0));
    }
}
