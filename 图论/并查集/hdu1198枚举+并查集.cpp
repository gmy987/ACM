#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100
#define MAXM 10000
char map[MAXN][MAXN];
int set[MAXM];
int n , m ;
void build( int n )
{
    for( int i = 0 ; i < n ; i++ )
        set[i] = i;
}
int find( int x )
{
    return set[x] == x ? x : set[x] = find(set[x]);
}
void unionSet( int x , int y )
{
    if( find(x) != find(y) )
        set[find(y)] = find(x);
}
bool judgeR( int i , int j )
{
    if( map[i][j+1] == 'C' || map[i][j+1] == 'F' || map[i][j+1] == 'G'||map[i][j+1] == 'H'||map[i][j+1] == 'I' || map[i][j+1] == 'K' || map[i][j+1] == 'A')
        return true;
    return false;
}
bool judgeL( int i , int j )
{
    if( map[i+1][j] == 'A' || map[i+1][j] == 'B' || map[i+1][j] == 'E' || map[i+1][j] == 'G' || map[i+1][j] == 'H' || map[i+1][j] == 'J' || map[i+1][j] == 'K')
        return true;
    return false;
}

using namespace std;

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        build( MAXM );
        int cnt = 0;
        if( m < 0 && n < 0 )
            break;
        for( int i = 0 ; i < m ; i++ )
            scanf("%s",map[i]);
        for( int i = 0 ; i < m ; i++ )
            for( int j = 0 ; j < n - 1 ; j++ )
            {
                if( map[i][j] == 'B' || map[i][j] == 'D' || map[i][j] == 'F' || map[i][j] == 'G' || map[i][j] == 'I' || map[i][j] == 'J' || map[i][j] == 'K'  )
                {
                    if( judgeR( i , j ) )
                        unionSet( i*n + j , i*n+j+1 );
                }
            }
        for( int i = 0 ; i < m - 1 ; i++ )
            for( int j = 0 ; j < n ; j++)
            {
                if( map[i][j] == 'C' || map[i][j] == 'D' || map[i][j] == 'E' || map[i][j] == 'H' || map[i][j] == 'I' || map[i][j] == 'J' || map[i][j] == 'K')
                    if( judgeL(i,j) )
                        unionSet( (i+1)*n+j , i*n+j );
            }

        for( int i = 0 ; i < n*m ; i++ )
            if( set[i] == i )
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;

}
