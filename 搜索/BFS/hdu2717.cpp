#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define maxn 300005

using namespace std;
struct Node{
    int x,step;
};
int n,k;
int vis[maxn];
int bfs( int a ){
    Node u,v;
    u.x= a;
    u.step = 0;
    queue<Node> q;
    q.push(u);
    vis[a] = 1;
    while(!q.empty()){
        u = q.front();
        q.pop();
        if(u.x==k) return u.step;
        v.x = u.x+1;
        v.step = u.step+1;
        if(v.x>=0&&v.x<=300000&&!vis[v.x]){
            vis[v.x] = 1;
            q.push(v);
        }
        v.x = u.x-1;
        if(v.x>=0&&v.x<=300000&&!vis[v.x]){
            vis[v.x] = 1;
            q.push(v);
        }
        v.x = u.x*2;
        if(v.x>=0&&v.x<=300000&&!vis[v.x]){
            vis[v.x] = 1;
            q.push(v);
        }
    }
    return -1;
}

int main(){
    while(~scanf("%d%d",&n,&k)){
        memset(vis,0,sizeof(vis));
        printf("%d\n",bfs(n));
    }
    return 0;
}
