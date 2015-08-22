/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-15 19:22
*
* Filename: hdu2243.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 36
#define ULL unsigned long long

using namespace std;
int cnt;
struct Node{
    Node *next[26];
    Node *fail;
    bool mark;
    int id;
    Node(){
        memset(next,0,sizeof(next));
        fail = NULL;
        mark = false;
        id = cnt++;
    }
}*qq[maxn],*rt,*p,*son,*tmp;
struct Mat{
    ULL m[100][100];
    int row;
};
void init(Mat &a,ULL num){
    for( int i = 0 ; i < a.row ; i++  )
        for( int j = 0 ; j < a.row ; j++ )
            a.m[i][j] = num;
}
void insert(char *s){
    int i,k;
    for( i = 0 , p = rt ; s[i] ; i++ ){
        k = s[i]-'a';
        if(!p->next[k]) p->next[k] = qq[cnt-1] = new Node();
        p = p->next[k];
    }
    p->mark = true;
}
void findFail(){
    queue<Node *> q;
    p = rt;
    q.push(p); 
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        for( int i = 0 ; i < 26 ; i++ ){
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
char str[40];
Mat mul(Mat a,Mat b){
    Mat c;
    c.row = a.row;
    init(c,0);
    for( int i = 0 ; i < a.row ; i++ )
        for( int k = 0 ; k < a.row ; k++ )
            if(a.m[i][k])
                for( int j = 0 ; j < a.row ; j++ )
                    c.m[i][j] += a.m[i][k]*b.m[k][j];
    return c;
}
Mat fast_mul(Mat a, long long n){
    Mat ans;
    ans.row = a.row;
    for( int i = 0 ; i < ans.row ; i++ )
        for( int j = 0 ; j < ans.row ; j++ )
            if(i==j) ans.m[i][j] = 1;
            else ans.m[i][j] = 0;
    while(n){
        if(n&1) ans = mul(ans,a);
        a = mul(a,a);
        n>>=1;
    }
    return ans;
}

int main(){
    long long m;
    int n;
    while(~scanf("%d%lld",&n,&m)){
        if(!n){
            puts("0");
            continue;
        }
        cnt = 0;
        rt = new Node();
        qq[0] = rt;
        for( int i = 0 ; i < n ; i++ ){
            scanf("%s",str);
            insert(str);
        }
        findFail();
        Mat a;
        a.row = cnt*2;
        init(a,0);
        for( int i = 0 ; i < cnt ; i++ )
            for( int j = 0 ; j < 26 ; j++ ){
                if(!qq[i]->mark&&!qq[i]->next[j]->mark)
                    a.m[i][qq[i]->next[j]->id]++;
            }
        for( int i = 0 ; i < cnt ; i++ )
            for( int j = 0 ; j < cnt ; j++ )
                if(i==j) a.m[i][j+cnt] = 1,a.m[i+cnt][j+cnt] = 1;
        Mat b;
        b.row = 2;
        b.m[0][0] = 26,b.m[0][1] = 1,b.m[1][0] = 0,b.m[1][1] = 1;
        Mat res = fast_mul(b,m+1);
        ULL total = res.m[0][1]-1;
        res = fast_mul(a,m+1);
        ULL part = 0;
        for( int i = cnt ; i < a.row ; i++ )
            part += res.m[0][i];
        part--;
        printf("%I64u\n",total-part);
    }
    return 0;
}

