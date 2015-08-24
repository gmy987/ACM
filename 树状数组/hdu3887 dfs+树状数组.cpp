/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-24 16:47
*
* Filename: hdu3887.cpp
*
* Description: 
*
=============================================================================*/
#pragma comment(linker,"/STACK:100000000,100000000")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxm 300005
#define maxn 200005

using namespace std;
struct Edge{
    int to,next;
}edge[maxm];
int head[maxn],cnt;
void addedge( int u , int v ){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    head[u] = cnt++;
}
int ans[maxn];
int sum[maxn];
int n;
int lowbit( int x ){
    return x&-x;
}
void update( int x , int c){
    while(x<=n){
        sum[x]+=c;
        x+=lowbit(x);
    }
}
int query( int x ){
    int ans = 0;
    while(x>0){
        ans += sum[x];
        x -= lowbit(x);
    }
    return ans;
}
void dfs( int x ,int pre) {
    ans[x] = query(x-1);
    for( int i = head[x] ; ~i ; i = edge[i].next ){
        int v = edge[i].to;
        if(v!=pre){
            update(v,1);
            dfs(v,x);
        }
    }
    ans[x] = query(x-1)-ans[x];
}

int main(){
    int t;
    int u,v;
    while(~scanf("%d%d",&n,&t)){
        if( n==0 && t == 0 ) break;
        memset(head,0xff,sizeof(head));
        memset(ans,0,sizeof(ans));
        memset(sum,0,sizeof(sum));
        cnt = 0;
        for( int i = 0 ; i < n -1 ; i++ ) {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs(t,-1);
        printf("%d",ans[1]);
        for( int i = 2 ; i <= n ; i++ ){
            printf(" %d",ans[i]);
        }
        puts("");
    }
    return 0;
}
