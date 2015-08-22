/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-29 13:11
*
* Filename: l.cpp
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
#define maxn 11111
#define INF 0x7fffffff
using namespace std;
struct Node{
    int maxl,maxr,maxa,sum;
    Node operator + ( Node a )
    {
        Node tmp;
        tmp.sum = this->sum+a.sum;
        tmp.maxl = max(this->maxl,this->sum+a.maxl);
        tmp.maxr = max(a.maxr,a.sum+this->maxr);
        tmp.maxa = max(this->maxa,max(a.maxa,this->maxr+a.maxl));
        return tmp;
    }
}tree[maxn<<2];
int a;
void pushup(int l , int r , int rt )
{
    tree[rt] = tree[l]+tree[r];
}
void build( int l , int r , int rt )
{
    if( l == r )
    {
        scanf("%d",&a);
        tree[rt].maxl = tree[rt].maxr = tree[rt].maxa = tree[rt].sum = a;
        return;
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
    int t,n,q;
    int x1,x2,y1,y2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        build(1,n,1);
        scanf("%d",&q);
        int ans;
        while(q--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if( y1 < x2 )
            {
                ans = 0;
                if( y1 + 2 <= x2 )
                    ans += query(y1+1,x2-1,1,n,1).sum;
                ans += query(x1,y1,1,n,1).maxr;
                ans += query(x2,y2,1,n,1).maxl;
                printf("%d\n",ans);
            }
            else
            {
                Node a,b,c;
                a = query(x2,y1,1,n,1);
                ans = a.maxa;
                if( x1 < x2 )
                {
                    b = query(x1,x2-1,1,n,1);
                    ans = max(ans,b.maxr+a.maxl);
                }
                if( y1 < y2 )
                {
                    c = query(y1+1,y2,1,n,1);
                    ans = max(ans,c.maxl+a.maxr);
                }
                if( x1 < x2 && y1 < y2 )
                {
                    ans = max( ans , b.maxr+a.sum+c.maxl );
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
