#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool col[11],map[11][11];
int n,step,cnt;

bool judge( int i , int j , int n)
{
    if(col[j])  return false;
    int k , m ;

    for( k = i+1 , m = j+1 ; k < n && m < n ; k++, m++ )
        if( map[k][m] )
            return false;

    for( k = i - 1 , m = j - 1 ; k>=0 && m >=0 ; k-- ,m-- )
        if( map[k][m] )
            return false;

    for( k = i - 1 , m = j + 1 ; k >= 0 && m < n ; k-- , m++ )
        if( map[k][m])
            return false;

    for( k = i + 1 , m = j - 1 ; k < n && m >= 0 ; k++ , m-- )
        if( map[k][m] )
            return false;

    return true;
}

void dfs( int row , int step ,int n)
{
    if( row >= n)
        return;

    for( int i = 0 ; i < n ; i++ )
    {
        if( !map[row][i] && judge(row,i,n))
        {
            step++;
            if( step == n)
            {
                cnt++;
                return;
            }
            col[i] = 1;
            map[row][i] = 1;
            dfs( row + 1 , step , n );
            col[i] = 0;
            map[row][i] = 0;
            step--;
        }
    }

}

int main()
{
    int board[11];
    for( int i = 1 ; i <= 10 ; i++ ){
        memset(map,0,sizeof(map));
        memset(col,0,sizeof(col));
        cnt = 0;
        dfs(0,0,i);
        board[i] = cnt ;
    }

    while(~scanf("%d",&n)&&n)
    {
        printf("%d\n",board[n]);
    }
    return 0;
}
