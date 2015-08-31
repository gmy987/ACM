/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-31 19:15
*
* Filename: f.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 600
#define maxm 50005
using namespace std;

struct Node{
    int from,to,w;
}edge[maxm];
int set[maxn];
bool cmp( Node a,Node b){
    return a.w<b.w;
}
int n,m;
void build( int n ){
    for( int i =1 ; i <= n ; i++ )
        set[i] = i;
}
int find( int x ){
    return set[x]==x?x:set[x]=find(set[x]);
}
void unionSet( int x , int y) {
    if(set[x]!=set[y]) set[find(y)] = find(x);
}
int mark[maxm];

int main(){
    while(~scanf("%d%d",&n,&m)){
        for( int i = 0 ; i < m ; i++ ){
            scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);
        }
        sort(edge,edge+m,cmp);
        build(n);
        int sum = 0;
        int cc = 0;
        for( int i = 0 , j = 0 ; j < n-1 && i < m ; i++ ){
            if(find(edge[i].from)!=find(edge[i].to)){
                unionSet(edge[i].from,edge[i].to);
                sum += edge[i].w;
                mark[cc++] = i;
                j++;
            }
        }
        int total;
        int cnt = 0;
        int ans = 0;
        for( int i = 0 ; i < cc ; i++ ){
            build(n);
            total = 0;
            for( int j = 0 , k = 0 ; j < n-1 && k < m ; k++ ){
                if(k==mark[i]) continue;
                if(find(edge[k].from)!=find(edge[k].to)){
                    unionSet(edge[k].from,edge[k].to);
                    total += edge[k].w;
                    j++;
                }
            }
            if(sum!=total){
                cnt++;
                ans += edge[mark[i]].w;
            }
        }
        printf("%d %d\n",cnt,ans);
    }
    return 0;
}
