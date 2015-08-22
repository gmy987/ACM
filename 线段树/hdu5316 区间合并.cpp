/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-31 15:56
*
* Filename: 
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
#define LL long long 
#define INF 0x7fffffff

using namespace std;
LL a;
struct Node{
    LL oo,ee,oe,eo;
    LL maxa;
    friend Node operator + ( Node l , Node r )
    {
        Node tmp;
        tmp.oo = max(max(l.oe+r.oo,l.oo+r.eo),max(l.oo,r.oo));
        tmp.ee = max(max(l.eo+r.ee,l.ee+r.oe),max(l.ee,r.ee));
        tmp.eo = max(max(l.ee+r.oo,l.eo+r.eo),max(l.eo,r.eo));
        tmp.oe = max(max(l.oe+r.oe,l.oo+r.ee),max(l.oe,r.oe));
        tmp.maxa = max(tmp.oo,max(tmp.ee,max(tmp.eo,tmp.oe)));
        return tmp;
    }
}tree[maxn<<2];
void pushup( LL l , LL r , LL rt )
{
    tree[rt] = tree[l] + tree[r];
}
void build( LL l ,LL r , LL rt )
{
    if( l == r )
    {
        scanf("%lld",&a);
        tree[rt].maxa = a;
        if(l&1)         
        {
            tree[rt].oo = a;
            tree[rt].ee = tree[rt].oe = tree[rt].eo = -INF;
        }
        else         
        {
            tree[rt].ee = a;
            tree[rt].oo = tree[rt].eo = tree[rt].oe = -INF;
        }
        return;
    }
    LL m = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}
void update( LL p , LL val , LL l , LL r , LL rt )
{
    if( l == r )
    {
        tree[rt].maxa = val;
        if(l&1) tree[rt].oo = (LL)val,tree[rt].ee = tree[rt].eo = tree[rt].oe = -INF;
        else tree[rt].ee = val,tree[rt].oo = tree[rt].oe = tree[rt].eo = -INF;
        return;
    }
    LL m = l + r >> 1;
    if( p <= m ) update(p,val,lson);
    else update(p,val,rson);
    pushup(rt<<1,rt<<1|1,rt);
}
Node query( LL L , LL R , LL l , LL r , LL rt )
{
    if( L <= l && r <= R )
        return tree[rt];
    LL m = l + r >> 1;
    if( R <= m ) return query(L,R,lson);
    else if( L > m ) return query(L,R,rson);
    else return query(L,R,lson)+query(L,R,rson);
}
LL m,n,x,y;
int op;
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        build(1,n,1);
        while(m--)
        {
            scanf("%d%lld%lld",&op,&x,&y);
            if(op) update(x,y,1,n,1);
            else printf("%lld\n",query(x,y,1,n,1).maxa);
        }
    }
    return 0;
}
