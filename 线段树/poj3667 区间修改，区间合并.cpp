/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-08-02 14:01
*
* Filename: poj3667.cpp
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
#define maxn 85555

using namespace std;
struct Node{
    int maxl,maxr,maxa;
    int lv,rv;
    int lazy;
    friend Node operator + ( Node l , Node r )
    {
        Node tmp;
        tmp.lazy=-1;
        tmp.lv = l.lv;
        tmp.rv = r.rv;
        tmp.maxl = l.maxl;
        tmp.maxr = r.maxr;
        if(l.rv-l.lv+1==l.maxl) tmp.maxl += r.maxl;
        if(r.rv-r.lv+1==r.maxr) tmp.maxr += l.maxr;
        tmp.maxa = max(l.maxr+r.maxl,max(l.maxa,r.maxa));
        return tmp;
    }
}tree[maxn<<2];
void pushup( int l , int r , int rt )
{
    tree[rt] = tree[l] + tree[r];
}
void build( int l , int r , int rt )
{
    tree[rt].lazy = -1;
    if( l == r )
    {
        tree[rt].lv = tree[rt].rv = l;
        tree[rt].maxl = tree[rt].maxr = tree[rt].maxa = 1;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}
void pushdown(int rt,int m)
{
    if(tree[rt].lazy!=-1)
    {
        tree[rt<<1].lazy = tree[rt<<1|1].lazy = tree[rt].lazy;
        tree[rt<<1].maxl = tree[rt<<1].maxr = tree[rt<<1].maxa = (m-(m>>1))*tree[rt].lazy;
        tree[rt<<1|1].maxl = tree[rt<<1|1].maxr = tree[rt<<1|1].maxa = (m>>1)*tree[rt].lazy;
        tree[rt].lazy = -1;
    }
}
void update( int op , int L , int R , int l , int r , int rt )
{
    if( L <= l && r <= R )
    {
        tree[rt].lazy = op;
        tree[rt].maxl = tree[rt].maxr = tree[rt].maxa = (r-l+1)*op;
        return;
    }
    pushdown(rt,r-l+1);
    int m = l + r >> 1;
    if( L <= m ) update(op,L,R,lson);
    if( R > m ) update(op,L,R,rson);
    pushup(rt<<1,rt<<1|1,rt);
}
int query( int val , int l , int r , int rt )
{
    if( l == r )
        return l;
    pushdown(rt,r-l+1);
    int m = l + r >> 1;
    if(tree[rt<<1].maxa>=val) return query(val,lson);
    else if(tree[rt<<1].maxr+tree[rt<<1|1].maxl>=val) return m-tree[rt<<1].maxr+1;
    else return query(val,rson);
}
int n,m,ans,a,b;
int op;

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        build(1,n,1);
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d",&a);
                if(tree[1].maxa<a) printf("0\n");
                else{
                    ans = query(a,1,n,1);
                    printf("%d\n",ans);
                    update(0,ans,ans+a-1,1,n,1);
                }
            }
            else
            {
                scanf("%d%d",&a,&b);
                update(1,a,a+b-1,1,n,1);
            }
        }
    }
    return 0;
}
