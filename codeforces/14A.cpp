/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-21 14:22
*
* Filename: 14A.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 60

using namespace std;
char board[maxn][maxn];
int n,m;
int sx,sy,ex,ey;

int main(){
    while(~scanf("%d%d",&n,&m)){
        for( int i = 0 ; i < n ; i++ )
            scanf("%s",board[i]);
        ex = ey = 0;
        sx = n-1;
        sy = m-1;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ ){
                if(board[i][j]=='*'){
                    sx = min(sx,i);
                    sy = min(sy,j);
                    ex = max(ex,i);
                    ey = max(ey,j);
                }
            }
        for( int i = sx ; i <= ex ; i++ ){
            for( int j = sy ; j <= ey ; j++ )
                cout<<board[i][j];
            cout<<endl;
        }
    }
    return 0;
} 
