/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-21 12:27
*
* Filename: 12A.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
char board[5][5];

int main(){
    while(~scanf("%s",board[0])){
        scanf("%s",board[1]);
        scanf("%s",board[2]);
        if(board[0][0]!=board[2][2]||board[0][1]!=board[2][1]||board[0][2]!=board[2][0])
            puts("NO");
        else if(board[1][0]!=board[1][2])
            puts("NO");
        else puts("YES");
    }
    return 0;
}
