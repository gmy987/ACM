#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool chess[9][9],col[9];
int cnt,n,k;
void dfs( int row , int step )
{
    if(step==k)
    {
        cnt++;
        return;
    }
    if(row >= n )
        return;
    for( int j = 0 ; j < n ; j++ )
    {
        if(chess[row][j]&&!col[j])
        {
            col[j] = 1;
            dfs(row+1,step+1);
            col[j] = 0;
        }
    }
    dfs(row+1,step);
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n==-1&&k==-1) break;
        cnt = 0;
        memset(chess,0,sizeof(chess));
        memset(col,0,sizeof(col));
        for( int i = 0 ; i < n ; i++ )
        {
            char a[9];
            scanf("%s",&a);
            for( int j = 0 ; j < n ; j++ ){
                if( a[j] =='#')
                    chess[i][j] = true;
            }
        }

        dfs(0,0);
        printf("%d\n",cnt);
    }
}
