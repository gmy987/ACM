/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-31 09:55
*
* Filename: k.cpp
*
* Description: 
*
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 111111
#define LL long long 

using namespace std;
struct Node{
    LL sum;
    int ll,rr; 
}tree[maxn<<2];
void pushup( int l , int r , int rt )
{
    tree[rt].sum = tree[l].sum+tree[r].sum;
}
long long a;
int n,q,op,x,y;
void build(int l, int r, int rt )
{
    tree[rt].ll = l,tree[rt].rr = r;
    if( l == r )
    {
        scanf("%lld",&a);
        tree[rt].sum = a;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt<<1,rt<<1|1,rt);
}
void update(int L , int R , int l , int r , int rt )
{
    if( tree[rt].rr-tree[rt].ll+1==tree[rt].sum) return;
    if( l == r )
    {
        tree[rt].sum = (LL)sqrt(tree[rt].sum+0.0);
        return;
    }
    int m = l + r >> 1;
    if( L <= m ) update(L,R,lson);
    if( R > m ) update(L,R,rson);
    pushup(rt<<1,rt<<1|1,rt);
}
LL query( int L , int R , int l , int r , int rt )
{
    if( L <= l && r <= R )
        return tree[rt].sum;
    LL ans = 0LL;
    int m = l + r >> 1;
    if ( L <= m ) ans += query(L,R,lson);
    if ( R > m ) ans += query(L,R,rson);
    return ans;
}
int main()
{
    int t = 1;
    while(~scanf("%d",&n))
    {
        build(1,n,1);
        printf("Case #%d:\n",t++);
        scanf("%d",&q);
        for( int i = 0 ; i < q ; i++ )
        {
            scanf("%d%d%d",&op,&x,&y);
            if(x>y) swap(x,y);
            if(op) printf("%lld\n",query(x,y,1,n,1));
            else update(x,y,1,n,1);
        }
        printf("\n");
    }
    return 0;
}

