/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-29 19:45
*
* Filename: a.cpp
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

struct Node {
    int sum,lazy;
}tree[maxn<<2];
int n,q,a,x,y;
void pushup(int l , int r, int rt )
{
    tree[rt].sum = tree[l].sum+tree[r].sum;
}
void build(int l , int r , int rt )
{
    tree[rt].lazy = 0;
    tree[rt].sum = 1;
    if( l == r )
        return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}
void pushdown( int rt , int m )
{
    if(tree[rt].lazy)
    {
        tree[rt<<1].lazy = tree[rt<<1|1].lazy = tree[rt].lazy;
        tree[rt<<1].sum = (m-(m>>1))*tree[rt].lazy;
        tree[rt<<1|1].sum = (m>>1)*tree[rt].lazy;
        tree[rt].lazy = 0;
    }
}
void update( int val , int L , int R , int l , int r , int rt )
{
    if( L <= l && r <= R )
    {
        tree[rt].lazy = val;
        tree[rt].sum = (r-l+1)*val;
        return;
    }
    pushdown(rt,r-l+1);
    int m = l + r >> 1;
    if( L <= m ) update(val,L,R,lson);
    if( R > m ) update(val,L,R,rson);
    pushup(rt<<1,rt<<1|1,rt);
}

int main()
{
    int t;
    scanf("%d",&t);
    for( int cas = 1 ; cas <= t ; cas++ )
    {
        scanf("%d%d",&n,&q);
        build(1,n,1);
        while(q--)
        {
            scanf("%d%d%d",&x,&y,&a);
            update(a,x,y,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",cas,tree[1].sum);
    }
    return 0;
}
