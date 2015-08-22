#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n , k ,cnt ,col[10];
char map[10][10];

void dfs(int row,int number)
{
    if( number == k  )
    {
        cnt++;
        return;
    }
    if( row >= n )
        return;
    for( int j = 0 ; j < n ; j++ )
    {
        if( map[row][j] == '#' && !col[j] )
        {
            col[j] = 1;
            dfs( row + 1 , number + 1 );
            col[j] = 0;
        }
    }
    dfs( row + 1 , number );
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n==-1&&k==-1) break;
        memset( map , 0 , sizeof( map ));
        memset( col , 0 , sizeof( col ));
        cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            scanf("%s",map[i]);
        dfs(0,0);
        printf("%d\n",cnt);
    }
}
