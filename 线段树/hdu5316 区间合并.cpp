/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-09-03 14:29
*
* Filename: hdu5316.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x7fffffff
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define maxn 100005
#define LL long long 

using namespace std;
struct Node{
    LL eo,oe,oo,ee;
    LL maxa;
    friend Node operator + ( Node a , Node b ){
        Node tmp;
        tmp.eo = max(max(a.eo,b.eo),max(a.ee+b.oo,a.eo+b.eo));
        tmp.oe = max(max(a.oe,b.oe),max(a.oe+b.oe,a.oo+b.ee));
        tmp.ee = max(max(a.ee,b.ee),max(a.ee+b.oe,a.eo+b.ee));
        tmp.oo = max(max(a.oo,b.oo),max(a.oe+b.oo,a.oo+b.eo));
        tmp.maxa = max(max(tmp.eo,tmp.oe),max(tmp.ee,tmp.oo));
        return tmp;
    }
}tree[maxn<<2];
int a,op,b;
void pushup( int l , int r , int rt ){
    tree[rt] = tree[l]+tree[r];
}
void build( int l , int r , int rt ){
    if(l==r){
        scanf("%d",&a);
        if(l&1){
            tree[rt].maxa = tree[rt].oo = (LL)a;
            tree[rt].oe = tree[rt].eo = tree[rt].ee = -INF;
        }
        else{
            tree[rt].maxa = tree[rt].ee = (LL)a;
            tree[rt].oe = tree[rt].eo = tree[rt].oo = -INF;
        }
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}
void update( int p , LL c , int l , int r , int rt ){
    if( l == r ){
        tree[rt].maxa = c;
        if(p&1){
            tree[rt].oo = c;
            tree[rt].eo = tree[rt].oe = tree[rt].ee = -INF;
        }
        else {
            tree[rt].ee = c;
            tree[rt].eo = tree[rt].oe = tree[rt].oo = -INF;
        }
        return;
    }
    int mid = l + r >> 1;
    if( p <= mid ) update(p,c,lson);
    else update(p,c,rson);
    pushup(rt<<1,rt<<1|1,rt);
}
Node query( int L , int R , int l , int r, int rt ){
    if( L <= l && r <= R ) return tree[rt];
    int mid = l + r >> 1;
    if( R <= mid ) return query(L,R,lson);
    else if( L > mid ) return query(L,R,rson);
    else return query(L,R,lson)+query(L,R,rson);
}

int main(){
    int T;
    scanf("%d",&T);
    int n,m;
    while(T--){
        scanf("%d%d",&n,&m);
        build(1,n,1);
        while(m--){
            scanf("%d%d%d",&op,&a,&b);
            if(op) update(a,(LL)b,1,n,1);
            else printf("%lld\n",query(a,b,1,n,1).maxa);
        }
    }
    return 0;
}
