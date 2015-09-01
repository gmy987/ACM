/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-09-01 20:18
*
* Filename: 500A.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 30005

using namespace std;
int n,m;
int a[maxn];
bool dfs( int cur ){
    if(cur==m) return true;
    if(cur>m ) return false;
    if(dfs(cur+a[cur])) return true;
    else return false;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        for( int i = 1 ; i <= n-1 ; i++ )
            scanf("%d",&a[i]);
        if(dfs(1)) puts("YES");
        else puts("NO");
    }
    return 0;
}
