/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-14 14:44
*
* Filename: poj2778.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define MOD 100000

using namespace std;
int cnt;
struct Node{
    Node *next[4];
    Node *fail;
    int id;
    bool flag;
    Node(){
        memset(next,0,sizeof(next));
        flag = false;
        id = cnt; 
        fail = NULL;
    }
}*qq[101];
Node *son,*tmp,*rt,*p;
struct Mat{
    long long m[101][101];
};
void init( Mat& a , int c ){
    for( int i = 0 ; i < cnt ; i++ )
        for( int j = 0 ; j < cnt ; j++ )
            a.m[i][j] = c;
}
Mat mul( Mat a , Mat b ){
    Mat c;
    init(c,0);
    for( int i = 0 ; i < cnt ; i++ )
        for( int k = 0 ; k < cnt ; k++ ){
            if(!a.m[i][k]) continue;
            for( int j = 0 ; j < cnt ; j++ )
                c.m[i][j] = (c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
        }
    return c;
}
int getChar(char a){
    if(a=='A') return 0;
    if(a=='G') return 1;
    if(a=='C') return 2;
    return 3;
}
void insert(char *s){
    int i,k;
    for( i = 0 , p = rt ; s[i] ; i++ ){
        k = getChar(s[i]); 
        if(!p->next[k]) p->next[k] = qq[cnt] = new Node(),cnt++;
        p = p->next[k];
    }
    p->flag = true;
}
void findFail(){
    queue<Node *> q;
    p = rt;
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
                if(son->fail->flag) son->flag = true;
                q.push(son);
            }
            else{
                if(tmp==rt) tmp->next[i] = rt;
                else tmp->next[i] = tmp->fail->next[i];
            }
        }
    }
}
char str[15];
Mat a;

Mat fast_mul(int n){
    Mat ans;
    init(ans,0);
    for( int i = 0 ; i < cnt ; i++ )
        ans.m[i][i] = 1;
    while(n){
        if(n&1) ans = mul(ans,a);
        a = mul(a,a);
        n>>=1;
    }
    return ans;
}

int main(){
    long long n,m;
    while(~scanf("%lld%lld",&m,&n)){
        cnt = 0;
        rt = new Node();
        cnt++;
        qq[0] = rt;
        init(a,0);
        for( int i = 0 ; i < m ; i++ ){
            scanf("%s",str);
            insert(str);
        }
        findFail();
        for( int i = 0 ; i < cnt ; i++ )
            for( int j = 0 ; j < 4 ; j++ ){
                son = qq[i]->next[j];
                if(!son->flag&&!qq[i]->flag)
                    a.m[i][son->id]++;
            } 
        Mat ans = fast_mul(n);
        long long res = 0;
        for( int i = 0 ; i < cnt ; i++ )
            res = (res+ans.m[0][i])%MOD;
        printf("%I64d\n",res);
    }
    return 0;
}
