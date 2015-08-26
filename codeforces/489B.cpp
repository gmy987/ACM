/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-26 15:16
*
* Filename: 489B.cpp
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
int board[maxn][maxn];
int n,m;
int a[maxn],b[maxn];
int vis[maxn],match[maxn];
bool dfs( int x ){
    int t;
    for( int i = 0 ; i < m ; i++ ){
        if(board[x][i]&&!vis[i]){
            vis[i] = true;
            t = match[i];
            match[i] = x;
            if(t==-1||dfs(t)) return true;
            match[i] = t;
        }
    }
    return false;
}

int main(){
    while(~scanf("%d",&n)){
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for( int i = 0 ; i < m ; i++ )
            scanf("%d",&b[i]);
        memset(board,0,sizeof(board));
        memset(match,0xff,sizeof(match));
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(abs(a[i]-b[j])<=1) board[i][j] = 1;
        for( int i = 0 ; i < n ; i++ ){
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
