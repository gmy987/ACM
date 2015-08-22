/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-29 20:20
*
* Filename: o.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 111111
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

int a,x,y;
struct Node{
    int maxl,maxr,maxa,l,r;
    friend Node operator + ( Node a , Node b )
    {
        Node tmp;
        tmp.l = a.l;
        tmp.r = b.r;
        tmp.maxa = max(a.maxa,b.maxa);
        tmp.maxl = a.maxl;
        tmp.maxr = b.maxr;
        if(a.r==b.l)
        {
            if(a.l==a.r) tmp.maxl = a.maxl+b.maxl;
            if(b.l==b.r) tmp.maxr = b.maxr+a.maxr;
            tmp.maxa = max(tmp.maxa,a.maxr+b.maxl);
        }
        return tmp;
    }
}tree[maxn<<2];

void pushup(int l , int r, int rt )
{
    tree[rt] = tree[l] + tree[r];
}
void build( int l , int r, int rt )
{
    if( l == r )
    {
        scanf("%d",&a);
        tree[rt].l = tree[rt].r = a;
        tree[rt].maxl = tree[rt].maxr = tree[rt].maxa = 1;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}
Node query(int L,int R ,int l, int r , int rt )
{
    if( L <= l & r <= R )
        return tree[rt];
    int m = l + r >> 1;
    if( R <= m ) return query(L,R,lson);
    else if( L > m ) return query(L,R,rson);
    else return query(L,R,lson) + query(L,R,rson);
}
int n,q;

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d",&q);
        build(1,n,1);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",query(x,y,1,n,1).maxa);
        }
    }
    return 0;
}
