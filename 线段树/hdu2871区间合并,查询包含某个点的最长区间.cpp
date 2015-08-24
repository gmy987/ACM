/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-24 15:01
*
* Filename: hdu2871.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#define maxn 50005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;
struct Node{
    int maxl,maxr,maxa;
    int lv,rv;
    friend Node operator + (Node l,Node r){
        Node tmp;
        tmp.lv = l.lv; 
        tmp.rv = r.rv;
        tmp.maxl = l.maxl;
        tmp.maxr = r.maxr;
        if(l.rv-l.lv+1==l.maxa) tmp.maxl = l.maxl+r.maxl;
        if(r.rv-r.lv+1==r.maxa) tmp.maxr = r.maxr+l.maxr;
        tmp.maxa = max(l.maxr+r.maxl,max(l.maxa,r.maxa));
        return tmp;
    }
}tree[maxn<<2];
void pushup( int l , int r , int rt ){
    tree[rt] = tree[l]+tree[r];
}
void build( int l , int r , int rt ){
    if(l==r){
        tree[rt].maxl = tree[rt].maxr = tree[rt].maxa = 1;
        tree[rt].lv = tree[rt].rv = l;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}

void update( int p , int op , int l , int r , int rt ){
    if( l == r ){
        tree[rt].maxl = tree[rt].maxr = tree[rt].maxa = op;
        return;
    }
    int m = l + r >> 1;
    if( p <= m ) update(p,op,lson);
    else update(p,op,rson);
    pushup(rt<<1,rt<<1|1,rt);
}
int query( int x , int l , int r , int rt ){
    if( l == r || tree[rt].maxa == 0 || tree[rt].maxa == r-l + 1 ) return tree[rt].maxa;
    int m = l + r >> 1;
    int ans = 0;
    if( x <= m ){
        if( x >= m-tree[rt<<1].maxr+1 ) ans+= query(x,lson)+query(m+1,rson);
        else ans+=query(x,lson);
    }
    else{
        if( x <= m + tree[rt<<1|1].maxl ) ans+= query(m,lson)+query(x,rson);
        else ans+=query(x,rson);
    }
    return ans;
}
stack<int> st;


int main(){
    int n,m,x;
    char str[5];
    while(~scanf("%d%d",&n,&m)){
        while(!st.empty()) st.pop();
        build(1,n,1);
        for( int i = 0 ; i < m ; i++ ){
            scanf("%s",str);
            if(str[0]=='D'){
                scanf("%d",&x);
                st.push(x);
                update(x,0,1,n,1);
            }
            else if(str[0]=='Q'){
                scanf("%d",&x);
                printf("%d\n",query(x,1,n,1));
            }
            else{
                x = st.top();
                st.pop();
                update(x,1,1,n,1);
            }
        }
    }
    return 0;
}
