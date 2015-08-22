/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-17 19:40
*
* Filename: hdu5024.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 150

using namespace std;
char board[maxn][maxn];
int cnt;
int a,b,c,d;
int array[6];

int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        for( int i = 0 ; i < n ; i++ )
            scanf("%s",board[i]);
        int ans = 0;
        int tmp;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ){
                if(board[i][j]=='.'){
                    tmp = 1;
                    a=b=c=d=0;
                    for( int k = i-1 ; k >= 0 ; k-- ){
                        if(board[k][j]=='#') break;
                        a++;
                    }
                    array[0] = a;
                    for( int k = i+1 ; k < n ; k++ ){
                        if(board[k][j]=='#') break;
                        b++;
                    }
                    array[1] = b;
                    for( int k = j+1 ; k < n ; k++ ){
                        if(board[i][k]=='#') break;
                        c++;
                    }
                    array[2] = c;
                    for( int k = j-1 ; k >= 0 ; k-- ){
                        if(board[i][k]=='#') break;
                        d++;
                    }
                    array[3] = d;
                    sort(array,array+4);
                    tmp+=array[2]+array[3];
                    ans = max(ans,tmp);
                    a = b = c = d = 0;
                    tmp = 1;
                    for( int k = i-1 , l = j-1 ; k >=0 && l >= 0 ; k-- , l-- ){
                        if(board[k][l]=='#') break;
                        a++;
                    }
                    array[0] = a;
                    for( int k = i+1 , l = j+1 ; k < n && l < n ; k++,l++ ){
                        if(board[k][l]=='#') break;
                        b++;
                    }
                    array[1] = b;
                    for( int k = i+1,l=j-1; k < n && l >= 0 ; k++ , l-- ){
                        if(board[k][l]=='#') break;
                        c++;
                    }
                    array[2] = c;
                    for( int k = i-1 , l = j+1 ; k >= 0 && l < n ; k--,l++ ){
                        if(board[k][l]=='#') break;
                        d++;
                    }
                    array[3] = d;
                    sort(array,array+4);
                    tmp+=array[2]+array[3];
                    ans = max( ans , tmp );
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}
