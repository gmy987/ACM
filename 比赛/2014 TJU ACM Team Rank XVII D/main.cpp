#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool board[500][500];
char op[55];

int main()
{
    while(~scanf("%s",op))
    {
        memset( board , 0 , sizeof(board));
        bool isUp = false;
        int len = strlen(op) , nowx = 200 , nowy = 200 ;
        int minx = 200 , miny = 200 , maxx = 200 , maxy = 200;
        for( int i = 0 ; i < len ; i++ )
        {
            if(op[i] == 'u')
                isUp = true;
            else if( op[i] == 'd')
                isUp = false;
            else if( op[i] == 'U' )
            {
                if(!isUp)
                    board[nowx-1][nowy] = 1;
                nowx -= 2;
                minx = min( minx , nowx );
            }
            else if( op[i] == 'D' )
            {
                if(!isUp)
                    board[nowx+1][nowy] = 1;
                nowx += 2;
                maxx = max( maxx , nowx );
            }
            else if( op[i] == 'L' )
            {
                if(!isUp)
                    board[nowx][nowy-1] = 1;
                nowy-=2;
                miny = min( miny , nowy );
            }
            else if( op[i] == 'R' ){
                if(!isUp)
                    board[nowx][nowy+1] = 1;
                nowy+= 2;
                maxy = max( maxy , nowy );
            }
        }
        if( maxy == miny )
        {
            printf("1\n");
            continue;
        }
        bool Up = false , Down = false , UpperLeft = false , UpperRight = false;
        bool DownLeft = false , DownRight = false ;
        if( board[minx][miny+1] == 1)
            Up = true;
        if( board[maxx][miny+1] == 1)
            Down = true;
        if( ( !Up )&& (!Down) ){
            printf("4\n");
            continue;
        }
        if( Up && !Down ){
            printf("7\n");
            continue;
        }
        if( board[minx+1][miny] == 1)
            UpperLeft = true;
        if( board[maxx-1][miny] == 1 )
            DownLeft = true;
        if( (!UpperLeft) && (!DownLeft))
        {
            printf("3\n");
            continue;
        }
        if( (!UpperLeft)&&DownLeft)
        {
            printf("2\n");
            continue;
        }
        if( board[minx+1][maxy] == 1 )
            UpperRight = true;
        if( board[maxx - 1 ][maxy] == 1)
            DownRight = true;
        if( UpperLeft && UpperRight && DownRight &&(!DownLeft))
        {
            printf("9\n");
            continue;
        }
        if( UpperLeft && DownLeft && (!UpperRight)&&DownRight)
        {
            printf("6\n");
            continue;
        }
        if((!DownLeft)&&(!UpperRight))
        {
            printf("5\n");
            continue;
        }
        int mid = (minx+maxx)/2;
        if( board[mid][miny+1] == 1 )
            printf("8\n");
        else
            printf("0\n");
    }
    return 0;
}
