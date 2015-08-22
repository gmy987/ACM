#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 3
using namespace std;
int dir[4][2] = {{0,-1},{1,0},{-1,0},{0,1}};
int goal[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
char op[] = { 'l' , 'd' , 'u' , 'r' };
bool flag;
int bound , sx , sy ,board[SIZE][SIZE] , mem[100];
int h ( int board[][SIZE] )
{
    int cost = 0 ;
    for( int i = 0 ; i < SIZE ; i++ )
        for ( int j = 0 ; j < SIZE ; j++ )
            if ( board[i][j] != SIZE * SIZE )
                cost += abs( i - goal[board[i][j] - 1][0] ) + abs( j - goal[board[i][j] - 1][1]);
    return cost;
}

int dfs ( int x , int y , int dv , int pre)
{
    int hv = h(board);
    if( hv == 0 )
    {
        flag = true;
        return dv;
    }
    if( hv + dv > bound ) return hv + dv;
    int next = 1e9;
    for( int i = 0 ; i < 4 ; i++ )
    {
        if( i + pre == 3 ) continue;
        int ax = x + dir[i][0] , ay = y + dir[i][1];
        if ( ax >= 0 && ay >=0 && ax < SIZE && ay < SIZE )
        {
            mem[dv] = i;
            swap ( board[ax][ay] , board[x][y] );
            int newBound = dfs ( ax , ay , dv + 1 , i );
            if( flag ) return newBound;
            swap( board[ax][ay] , board[x][y] );
            next = min( next , newBound );
        }
    }
    return next;
}
void IDA_STAR()
{
    flag = false;
    bound = h(board);
    while(!flag && bound <= 100 )
        bound = dfs ( sx , sy , 0 , -1 );
}
int main()
{
    char c;
    memset( mem , 0 , sizeof( mem ));
    for( int i = 0 ; i < SIZE ; i++ )
        for( int j = 0 ; j < SIZE ; j++)
        {
            cin >> c;
            if( c == 'x' )
            {
                board[i][j] = SIZE*SIZE ;
                sx = i ;
                sy = j ;
            }
            else
                board[i][j] = c - '0';
        }
    IDA_STAR();
    if(flag)
    {
        for( int i = 0 ; i < bound ; i++ )
            cout<<op[mem[i]];
        printf("\n");
    }
    else
        printf("unsolvable\n");
    return 0;
}
