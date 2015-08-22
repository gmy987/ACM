#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 3
using namespace std;

int bound , sx , sy ,board[SIZE][SIZE] , mem[100];

int dir[4][2] = { {-1,0} , {0,1} , {0,-1} , {1,0}};
char op[] = {'u','r','l','d'};
int goal_state[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,1}};
bool flag;

int h( int board[][SIZE] )
{
    int cost = 0;
    for( int i = 0 ; i < SIZE ; i++ )
        for( int j = 0 ; j < SIZE ; j++ )
            if( board[i][j] != SIZE*SIZE )
                cost += abs ( i - goal_state[ board[i][j] - 1 ][0] ) + abs( j - goal_state[ board[i][j] - 1 ][1] );
    return cost;
}
int dfs ( int x , int y , int dv , int pre )
{
    int hv = h(board);
    if( hv == 0 )
    {
        flag = true;
        return dv;
    }
    if ( hv + dv > bound )
        return hv + dv ;
    int next = 1e9;
    for ( int i = 0 ; i < 4 ; i++ )
    {
        if( pre + i == 3 )
            continue;
        int ax = x + dir[i][0] , ay = y + dir[i][1];
        if( ax >=0 && ay>=0 && ax < SIZE && ay < SIZE )
        {
            mem[dv] = i;
            swap ( board[x][y] , board[ax][ay] );

            int new_bound = dfs ( ax , ay , dv + 1 , i );
            if( flag )
                return new_bound;
            next = min ( new_bound , next );
            swap ( board[x][y] , board[ax][ay] );
        }
    }
    return next;
}

//用于判断是否可以到达最终状态,求逆序对数，当逆序对为偶数时可以，为奇数时不可以
bool judge ( int board[][SIZE] )
{
    int i , j , sum = 0 , b[10] , k = 0;
    for( i = 0 ; i < SIZE ; i++ )
        for( j = 0 ; j < SIZE ; j++ )
            if( board[i][j] != SIZE*SIZE )
                b[++k] = board[i][j];
    for ( i = 1 ; i < SIZE*SIZE ; i++ )
        for( j = 1 ; j < i ; j++ )
            if( b[i] < b[j])
                sum++;
    if( sum % 2 == 0 )
        return true;
    return false;
}

void IDA_STAR()
{
    flag = false;
    bound = h(board);
    while( !flag && bound <= 100 )
        bound = dfs ( sx , sy , 0 , -1 );
}

int main()
{
    char c;
    while ( cin >> c )
    {
        memset ( board , 0 , sizeof( board ));
        memset ( mem , 0 , sizeof ( mem ) );
        if( c == 'x' ){
            board[0][0] = SIZE*SIZE;
            sx = 0;
            sy = 0;
        }
        else
            board[0][0] = c - '0';

        for( int i = 0 ; i < SIZE ; i++ )
            for( int j = 0 ; j < SIZE ; j++ )
            {
                if(i||j)
                {
                    cin >> c;
                    if( c == 'x' ){
                        board[i][j] = SIZE*SIZE;
                        sx = i;
                        sy = j;
                    }
                    else
                        board[i][j] = c - '0';
                }
            }
        if( !judge( board ) ){
            printf("unsolvable\n");
            continue;
        }
        IDA_STAR();
        if(flag)
        {
            for( int i = 0 ; i < bound ; i++ )
                printf("%c",op[mem[i]]);
            printf("\n");
        }
        else
            printf("unsolvable\n");
    }
    return 0;
}
