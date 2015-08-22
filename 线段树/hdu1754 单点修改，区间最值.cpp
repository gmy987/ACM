/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-30 09:32
*
* Filename: b.cpp
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
#define maxn 222222

using namespace std;
int m,n,x,y,a;
char str[4];
struct Node{
    int val;
    friend Node operator + (Node l,Node r)
    {
        Node tmp;
        tmp.val = max(l.val,r.val);
        return tmp;
    }
}tree[maxn<<2];
void pushup( int l , int r , int rt )
{
    tree[rt].val = max(tree[l].val,tree[r].val);
}
void build( int l , int r , int rt )
{
    tree[rt].val = -1;
    if( l == r )
    {
        scanf("%d",&a);
        tree[rt].val = a;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}
void update( int p , int val , int l , int r , int rt )
{
    if(l==r)
    {
        tree[rt].val = val;
        return;
    }
    int m = l + r >> 1;
    if( p <= m ) update(p,val,lson);
    else update(p,val,rson);
    pushup(rt<<1,rt<<1|1,rt);
}
Node query(int L,int R,int l , int r ,int rt )
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
    while(~scanf("%d%d",&n,&m))
    {
        build(1,n,1);
        while(m--)
        {
            scanf("%s%d%d",str,&x,&y);
            if(str[0]=='U')
                update(x,y,1,n,1);
            else printf("%d\n",query(x,y,1,n,1).val);
        }
    }
    return 0;
}
