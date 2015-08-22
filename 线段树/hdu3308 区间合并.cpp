/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-31 18:18
*
* Filename: hdu3308.cpp
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
#define maxn 111111

using namespace std;
int a,x,y,n,m;
char op[5];
struct Node
{
    int maxa;
    int maxl,maxr;
    int lv,rv;
    int ll,rr;
    friend Node operator + (Node l,Node r)
    {
        Node tmp;
        tmp.ll = l.ll;
        tmp.rr = r.rr;
        tmp.lv = l.lv;
        tmp.rv = r.rv;
        tmp.maxl = l.maxl;
        tmp.maxr = r.maxr;
        tmp.maxa = max(l.maxa,r.maxa);
        if(r.lv>l.rv) tmp.maxa = max(tmp.maxa,l.maxr+r.maxl);
        if(l.rr-l.ll+1==l.maxa&&r.lv>l.rv)
            tmp.maxl = l.maxa+r.maxl;
        if(r.rr-r.ll+1==r.maxa&&r.lv>l.rv)
            tmp.maxr = r.maxa+l.maxr;
        return tmp;
    }
}tree[maxn<<2];
void pushup( int l ,int r , int rt )
{
    tree[rt] = tree[l] + tree[r];
}
void build( int l , int r , int rt )
{
    if( l == r )
    {
        scanf("%d",&a);
        tree[rt].ll = tree[rt].rr = l;
        tree[rt].lv = tree[rt].rv = a;
        tree[rt].maxa = tree[rt].maxl = tree[rt].maxr = 1;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}
void update( int p , int val , int l , int r, int rt )
{
    if( l == r )
    {
        tree[rt].lv = tree[rt].rv = val;
        tree[rt].maxa = tree[rt].maxl = tree[rt].maxr = 1;
        return;
    }
    int m = l + r >> 1;
    if( p <= m ) update(p,val,lson);
    else update(p,val,rson);
    pushup(rt<<1,rt<<1|1,rt);
}
Node query( int L , int R , int l , int r , int rt )
{
    if( L <= l && r <= R )
        return tree[rt];
    int m = l + r >> 1;
    if( R <= m ) return query(L,R,lson);
    else if( L > m ) return query(L,R,rson);
    else return query(L,R,lson)+query(L,R,rson);
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        build(1,n,1);
        while(m--)
        {
            scanf("%s%d%d",op,&x,&y);
            if( op[0] == 'U' )
                update(x+1,y,1,n,1);
            else printf("%d\n",query(x+1,y+1,1,n,1).maxa);
        }
    }
    return 0;
}
