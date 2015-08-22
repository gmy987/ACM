/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-29 18:30
*
* Filename: h.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 55555
using namespace std;
int n,a,q,x,y;
struct Node{
    int maxl,maxr,maxa,sum;
    friend Node operator + ( Node l , Node r )
    {
        Node tmp;
        tmp.sum = l.sum+r.sum;
        tmp.maxa = max(l.maxr+r.maxl,max(l.maxa,r.maxa));
        tmp.maxl = max(l.maxl,l.sum+r.maxl);
        tmp.maxr = max(r.maxr,r.sum+l.maxr);
        return tmp;
    }
}tree[maxn<<2];
void pushup( int l , int r , int rt )
{
    tree[rt] = tree[l]+tree[r];
}
void build(int l , int r , int rt )
{
    if( l == r )
    {
        scanf("%d",&a);
        tree[rt].maxl = tree[rt].maxr = tree[rt].maxa = tree[rt].sum = a;
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
int main()
{
    while(~scanf("%d",&n))
    {
        build(1,n,1);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            Node ans = query(x,y,1,n,1);
            printf("%d\n",ans.maxa);
        }
    }
    return 0;
}
