/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-12 20:09
*
* Filename: hdu2547.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 10000
#define INF 0x7f7f7f7f 

using namespace std;
int cnt;
int dp[maxn][maxn];
struct Node{
    Node *next[4];
    Node *fail;
    int id;
    bool mark;
    Node(){
        memset(next,0,sizeof(next));
        fail = NULL;
        mark = false;
        id = cnt;
    }
};
int getId(char a){
    switch(a){
        case 'A': return 0;
        case 'G': return 1;
        case 'C': return 2;
        case 'T': return 3;
    }
    return 0;
}
Node *p,*rt,*tmp,*son;
Node *qq[maxn];
void insert(char *s){
    int i,k;
    for( i = 0 , p = rt ; s[i] ; i++ ){
        k = getId(s[i]);
        if(!p->next[k]) p->next[k] = qq[cnt] = new Node();
        cnt++;
        p = p->next[k];
    }
    p->mark = true;
}
void findFail(){
    p = rt;
    queue<Node *> q;
    q.push(p);
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        for( int i = 0 ; i < 4 ; i++ ){
            son = tmp->next[i];
            if(son){
                if(tmp==rt) son->fail = rt;
                else{
                    p = tmp->fail;
                    while(p){
                        if(p->next[i]){
                            son->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(!p) son->fail = rt;
                }
                if(son->fail->mark) son->mark = true;
                q.push(son);
            }
            else{
                if(tmp==rt) tmp->next[i] = rt;
                else{
                    tmp->next[i] = tmp->fail->next[i];
                }
            } 
        }
    }
}

int main(){
    char str[maxn];
    int cas = 1;
    int n;
    while(~scanf("%d",&n)&&n){
        cnt = 0;
        rt = new Node();
        cnt++;
        qq[0] = rt;
        for( int i = 0 ; i < n ; i++ ){
            scanf("%s",str);
            insert(str);
        }
        findFail();
        scanf("%s",str);
        memset(dp,0x7f,sizeof(dp)); 
        dp[0][0] = 0;
        for( int i = 0 ; i < strlen(str) ; i++ )
            for( int j = 0 ; j < cnt ; j++ )
                if(dp[i][j]==INF) continue;
                else{
                    for( int k = 0 ; k < 4 ; k++ ){
                        if(qq[j]->next[k]->mark) continue;
                        dp[i+1][qq[j]->next[k]->id] = min(dp[i+1][qq[j]->next[k]->id],dp[i][j]+(getId(str[i])!=k));
                    }
                }
        int ans = INF;
        for( int i = 0 ; i < cnt ; i++ )
            ans = min(ans,dp[strlen(str)][i]);
        printf("Case %d: %d\n",cas++,ans==INF?-1:ans);
    }
    return 0;
}
