/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-29 19:24
*
* Filename: j.cpp
*
* Description: 
*
=============================================================================*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 55555
using namespace std;
struct Node{
    int maxl,maxr,maxa,sum;
    friend Node operator + (Node l,Node r)
    {
        Node tmp;
        tmp.sum = l.sum+r.sum;
        tmp.maxa = max(l.maxr+r.maxl,max(l.maxa,r.maxa));
        tmp.maxl = max(l.maxl,l.sum+r.maxl);
        tmp.maxr = max(r.maxr,r.sum+l.maxr);
        return tmp;
    }
}tree[maxn<<2];
int n,op,x,y,q,a;

void pushup( int l , int r , int rt )
{
    tree[rt] = tree[l] + tree[r];
}
void build( int l , int r ,int rt )
{
    if( l == r )
    {
        scanf("%d",&a);
        tree[rt].sum = tree[rt].maxl = tree[rt].maxr = tree[rt].maxa = a;
        return ;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
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
void update( int p , int x ,int l , int r , int rt )
{
    if( l == r )
    {
        tree[rt].sum = tree[rt].maxl = tree[rt].maxr = tree[rt].maxa = x;
        return;
    }
    int m = l + r >> 1;
    if( p <= m ) update(p,x,lson);
    else update(p,x,rson);
    pushup(rt<<1,rt<<1|1,rt);
}

int main()
{
    while(~scanf("%d",&n))
    {
        build(1,n,1);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d",&op,&x,&y);
            if(op)
                printf("%d\n",query(x,y,1,n,1).maxa);
            else update(x,y,1,n,1);
        }
    }
    return 0;
}

