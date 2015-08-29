/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-29 08:51
*
* Filename: hdu1495.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define maxn 105
using namespace std;
struct Node{
    int step;
    int a,b,c;
};
int a,b,c,tmp;
bool judge( Node x ){
    int cnt = 0;
    if(x.a*2==a) cnt++;
    if(x.b*2==a) cnt++;
    if(x.c*2==a) cnt++;
    if(cnt>=2) return true;
    return false;
}
int vis[maxn][maxn][maxn];
int bfs( int a , int b , int c ){
    Node u,v;
    queue<Node> q;
    u.a = a;
    u.b = u.c = 0;
    u.step = 0;
    vis[a][0][0] = 1;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        if(judge(u)) return u.step;
        if(u.a>0){
            if(u.b!=b){
                tmp = b-u.b;
                if(tmp>u.a){
                    v.a = 0;
                    v.b = u.b+u.a;
                }
                else{
                    v.a = u.a-tmp;
                    v.b = b;
                }
                v.c = u.c;
                v.step = u.step+1;
                if(!vis[v.a][v.b][v.c]){
                        vis[v.a][v.b][v.c] = 1;
                        q.push(v);
                }
            }
            if(u.c!=c){
                tmp = c-u.c;
                if(tmp>u.a){v.a=0;v.c=u.c+u.a;}
                else{v.a=u.a-tmp;v.c=c;}
                v.b=u.b;v.step=u.step+1;
                if(!vis[v.a][v.b][v.c]){vis[v.a][v.b][v.c]=1;q.push(v);}
            }
        }
        if(u.b>0){
            if(u.a!=a){
                tmp = a-u.a;
                if(tmp>u.b){v.b=0;v.a=u.a+u.b;}
                else{v.b=u.b-tmp;v.a=a;}
                v.c=u.c;v.step=u.step+1;
                if(!vis[v.a][v.b][v.c]){vis[v.a][v.b][v.c]=1;q.push(v);};
            }
            if(u.c!=c){
                tmp=c-u.c;
                if(tmp>u.b){v.b=0;v.c=u.c+u.b;}
                else{v.b=u.b-tmp;v.c=c;}
                v.a=u.a;v.step=u.step+1;
                if(!vis[v.a][v.b][v.c]){vis[v.a][v.b][v.c]=1;q.push(v);}
            }
        }
        if(u.c>0){
            if(u.a!=a){
                tmp=a-u.a;
                if(tmp>u.c){v.c=0;v.a=u.a+u.c;}
                else{v.c=u.c-tmp;v.a=a;}
                v.b=u.b;v.step=u.step+1;
                if(!vis[v.a][v.b][v.c]){vis[v.a][v.b][v.c]=1;q.push(v);}
            }
            if(u.b!=b){
                tmp=b-u.b;
                if(tmp>u.c){v.c=0;v.b=u.b+u.c;}
                else{v.c=u.c-tmp;v.b=b;}
                v.a=u.a;v.step=u.step+1;
                if(!vis[v.a][v.b][v.c]){vis[v.a][v.b][v.c]=1;q.push(v);}
            }
        }
    }
    return -1;
}

int main(){
    while(~scanf("%d%d%d",&a,&b,&c)){
        if(a+b+c==0) break;
        if(b*2<a&&c*2<a) { puts("NO"); continue; }
        memset(vis,0,sizeof(vis));
        int ans = bfs(a,b,c);
        if(ans==-1) puts("NO");
        else printf("%d\n",ans);
    }
    return 0;
}
