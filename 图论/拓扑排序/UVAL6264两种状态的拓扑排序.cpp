/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-23 15:11
*
* Filename: b.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define maxm 1000005
#define maxn 100005

using namespace std;
struct Edge{
    int to,next;
}edge[maxm];
int head[maxn],cnt;
int in[maxn],in2[maxn];
int a[maxn];
int i;
void addedge( int u , int v ){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
queue<int> q1,q2;

int main(){
    int t;
    scanf("%d",&t);
    int n,m;
    int u,v;
    while(t--){
        scanf("%d%d",&n,&m);
        memset(head,0xff,sizeof(head));
        cnt = 0;
        for( i = 1 ; i <= n ; i++) {
            in[i] = 0;
            in2[i] = 0;
            scanf("%d",&a[i]);
        }
        for( i = 0 ; i < m ; i++ ){
            scanf("%d%d",&u,&v);
            addedge(u,v);
            in[v]++;
            in2[v]++;
        }
        int ans = 0;
        for( i = 1 ; i <= n ; i++ ){
            if(!in[i]&&a[i]==1) q1.push(i);
            else if(!in[i]&&a[i]==2) q2.push(i);
        }
        while(true){
            if(q1.empty()&&q2.empty()) break;
            while(!q1.empty()){
                u = q1.front();
                q1.pop();
                for( i = head[u] ; ~i ; i = edge[i].next ){
                    v = edge[i].to;
                    if(--in[v]==0){
                        if(a[v]==2) q2.push(v);
                        else q1.push(v);
                    }
                }
            }
            if(q2.empty()) break;
            ans++;
            while(!q2.empty()){
                u = q2.front();
                q2.pop();
                for( i = head[u] ; ~i ; i = edge[i].next ){
                    v = edge[i].to;
                    if(--in[v]==0){
                        if(a[v]==2) q2.push(v);
                        else q1.push(v);
                    }
                }
            }
            if(q1.empty()) break;
            ans++;
        }
        int res = 0;
        for( i = 1 ; i <= n ; i++ ){
            if(!in2[i]&&a[i]==1) q1.push(i);
            else if(!in2[i]&&a[i]==2) q2.push(i);
        }
        while(true){
            if(q1.empty()&&q2.empty()) break;
            while(!q2.empty()){
                u = q2.front();
                q2.pop();
                for( i = head[u] ; ~i ; i = edge[i].next ){
                    v = edge[i].to;
                    if(--in2[v]==0){
                        if(a[v]==2) q2.push(v);
                        else q1.push(v);
                    }
                }
            }
            if(q1.empty()) continue;
            res++;
            while(!q1.empty()){
                u = q1.front();
                q1.pop();
                for( i = head[u] ; ~i ; i = edge[i].next ){
                    v = edge[i].to;
                    if(--in2[v]==0){
                        if(a[v]==2) q2.push(v);
                        else q1.push(v);
                    }
                }
            }
            if(q2.empty()) break;
            res++;
        }
        printf("%d\n",min(res,ans));
    }
    return 0;
} 

