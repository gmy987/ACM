#include <iostream>

using namespace std;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char m[50][50];
bool dfs(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m)
            return false;
    for( int i = 0 ; i < 4 ; i ++ )
    {
        if( m[x+dir[i][0]][y+dir[i][1]] == 'D')
            return true;
        else if( m[x+dir[i][0]][y+dir[i][1]] == '.' )
        {
            m[x+dir[i][0]][y+dir[i][1]] = '#';
            if( dfs(x+ dir[i][0],y+dir[i][1]))
                return 1;
            m[x+dir[i][0]][y+dir[i][1]] = '.';
        }
    }
    return false;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
