/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-21 13:39
*
* Filename: 15A.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 1005

using namespace std;
struct Node{
    int x,a;
}node[maxn];
bool cmp(Node a,Node b){
    return a.x<b.x;
}

int main(){
    int n,t;
    while(~scanf("%d%d",&n,&t)){
        for( int i = 0 ; i < n ; i++ ) scanf("%d%d",&node[i].x,&node[i].a);
        sort(node,node+n,cmp);
        int ans = 2;
        for( int i = 0 ; i < n-1 ; i++ ){
            if(node[i+1].x-node[i+1].a/2.0-node[i].x-node[i].a/2.0>t) ans += 2;
            else if(node[i+1].x-node[i+1].a/2.0-node[i].x-node[i].a/2.0==t) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
