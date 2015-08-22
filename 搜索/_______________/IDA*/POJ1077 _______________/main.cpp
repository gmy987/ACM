#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define SIZE 3
using namespace std;
int board[SIZE][SIZE],mem[1000];
bool flag;
int sx ,sy , bound;//上界

int dir[4][2] = { { -1 , 0 } , { 0 , 1 } , { 0 , -1 } , { 1 , 0 }};//移动方向，u,r,l,d，且相对方向index相加为3
char op[4] = {'u','r','l','d'};//与上面方向对应

//要达到的目标状态,分别与数字1-8对应,应用于启发式搜索，用于计算估值函数
int goal_state[9][2] = { {0,0} , {0,1} , {0,2} , {1,0} , {1,1} , {1,2} , {2,0} , {2,1} ,{2,2}};
int h(int board[][SIZE])
{
    int cost = 0 ;
    for( int i = 0 ; i < SIZE ; i++ )
        for( int j = 0 ; j < SIZE ; j++ )
        {
            if( board[i][j] != SIZE*SIZE )
                cost+=abs( i - goal_state[board[i][j]-1][0] ) + abs( j - goal_state[ board[i][j] - 1 ][1]);
        }
    return cost;
}
int dfs ( int x , int y , int dv , int preOp )//返回nextbound,dv代表当前深度
{
    int hv = h( board );//到达最终状态需要的花费

    if( hv == 0 )
    {
        flag = true;
        return dv;//返回当前深度，即走的步数
    }

    //当前局面的估价函数值+当前的搜索深度 > 预定义的最大搜索深度,然后加大预定义搜索深度再进行搜索
    if ( hv + dv > bound )
        return hv + dv ;

    int next_bound = 1e9;
    for( int i = 0 ; i < 4 ; i++ )
    {
        if( i + preOp == 3 )//与上一次操作互为逆操作，则跳过
            continue;
        int ax = x + dir[i][0] , ay = y + dir[i][1] ;
        if( ax >= 0 && ay >= 0 && ax < SIZE && ay < SIZE )
        {
            mem[dv] = i;
            swap ( board[x][y] , board[ax][ay] );
            int new_bound = dfs ( ax , ay , dv + 1 , i );
            if( flag )
                return new_bound;
            next_bound = min ( new_bound , next_bound );
            swap( board[x][y] , board[ax][ay] );
        }
    }

    return next_bound;
}
void IDA_STAR ()
{
    flag = false;
    bound = h(board);//初始代价
    while(!flag && bound <= 100 )//上限
        bound = dfs( sx , sy , 0 , -10 );
}

int main()
{
    //freopen("input.txt" , "r" , stdin );
    char c;
    //flag = false;
    //memset ( board , 0 , sizeof( board ) );
    memset ( mem , 0 , sizeof( mem ) );
    for( int i = 0 ; i < SIZE ; i++ )
        for( int j = 0 ; j < SIZE ; j++ )
        {
            cin>>c;
            if( c == 'x' )
            {
                sx = i;
                sy = j;
                board[i][j] = SIZE*SIZE;
            }
            else
                board[i][j] = c - '0';
        }
    //for( int i = 0 ; i < 3 ; i++ )
        //for( int j = 0 ; j < 3 ; j++ )
            //cout<< board[i][j] <<" ";
    IDA_STAR();

    if(flag)
    {
        for( int i = 0 ; i < bound ; i++ )
            cout << op[mem[i]] ;
    }
    else
        printf("unsolvable\n");
    return 0;
}
