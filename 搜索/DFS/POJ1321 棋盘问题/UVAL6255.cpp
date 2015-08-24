/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-23 15:55
*
* Filename: a.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#define maxn 25

using namespace std;
int dp[1<<20]={0};
int a[maxn][maxn];
int sum[maxn];
int vis[maxn];
int n,t;
set<int> s;
void dfs( int st , int cnt ,int x){
    if(cnt==n) return;
    if(dp[st]==t) return;
    dp[st] = t; 
    vis[x] = 1;
    for( int i = 0 ; i < n ; i++ ) sum[i]+=a[x][i];
    for( int i = 0 ; i < n ; i++ ){
        if(!vis[i]){
            if(cnt==n-1&&sum[i]<=0){ s.insert(i); break; }
            if(sum[i]>0) dfs(st|1<<i,cnt+1,i);
        }
    }
    for( int i = 0 ; i < n ; i++ ) sum[i]-=a[x][i];
    vis[x] = 0;
}
set<int>::iterator it;

int main(){
    int T;
    scanf("%d",&T);
    for( t = 1 ; t <= T ; t++ ){
        s.clear();
        scanf("%d",&n);
        memset(sum,0,sizeof(sum));
        for(int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                scanf("%d",&a[i][j]);
                sum[i]+=a[i][j];
            }
        }
        if(n==1&&a[0][0]<=0){puts("1");continue;}
        else if(n==1){puts("0");continue;}
        for( int i = 0 ; i < n ; i++ ){
            memset(vis,0,sizeof(vis));
            if(sum[i]>0) dfs(1<<i,1,i);
        } 
        if(s.empty()){puts("0");continue;}
        for( it = s.begin();it!=s.end();it++){
            if(it==s.begin()) printf("%d",(*it)+1);
            else printf(" %d",(*it)+1);
        }
        puts("");
    }
    return 0;
} 
