/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-17 16:40
*
* Filename: hdu4417.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 100005

using namespace std;
struct Node{
    int mmax,mmin;
    int l,r;
    friend Node operator + ( Node l , Node r ){
        Node tmp;
        tmp.mmax = max(l.mmax,r.mmax);
        tmp.mmin = min(l.mmin,r.mmin);
        tmp.l = l.l;
        tmp.r = r.r;
        return tmp;
    }
}tree[maxn<<2]; 
int a,n,m,h;
void pushup( int l , int r , int rt ){
    tree[rt] = tree[l]+tree[r];
}
void build( int l , int r , int rt ){
    if( l == r ){
        scanf("%d",&a);
        tree[rt].mmax = tree[rt].mmin = a;
        tree[rt].l = tree[rt].r = l;
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}
int query( int L , int R , int l , int r , int rt ){
    if( L <= l && r <= R ){
        if( tree[rt].mmax <= h ) return tree[rt].r-tree[rt].l+1;
        if( tree[rt].mmin > h ) return 0;
    }
    int m = l + r >> 1;
    if( R <= m ) return query(L,R,lson);
    else if( L > m ) return query(L,R,rson);
    else return query(L,R,lson)+query(L,R,rson);
}

int main(){
    int t;
    scanf("%d",&t);
    int cas = 1;
    int l,r;
    while(t--){
        printf("Case %d:\n",cas++);
        scanf("%d%d",&n,&m);
        build(1,n,1);
        while(m--){
            scanf("%d%d%d",&l,&r,&h);
            printf("%d\n",query(l+1,r+1,1,n,1));
        }
    }
    return 0;
}
