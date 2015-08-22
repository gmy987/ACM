/*=============================================================================
*
* Author: daisy
*
* Last modified: 2015-07-29 12:37
*
* Filename: hdu1166.cpp
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

int sum[maxn<<2];
void pushup(int rt)
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void build( int l , int r , int rt )
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        return;
    }
    int m = l + r >> 1;
    build(lson); 
    build(rson);
    pushup(rt);
}
char str[7];
void update( int p , int add , int l , int r , int rt )
{
    if( l == r )
    {
        sum[rt] += add;
        return;
    }
    int m = l + r >> 1;
    if( p <= m ) update( p , add , lson );
    else update( p , add , rson );
    pushup(rt);
}
int query( int L , int R , int l , int r , int rt )
{
    if( L <= l && r <= R )
        return sum[rt];
    int m = l + r >> 1;
    int ans = 0;
    if( L <= m ) ans += query( L , R , lson );
    if( R > m ) ans += query( L , R , rson );
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    int n,a,b;
    int cas = 1;
    while(t--)
    {
        printf("Case %d:\n",cas++);
        scanf("%d",&n);
        build(1,n,1);
        while(true)
        {
            scanf("%s",str);
            if(str[0]=='E')
                break;
            else if(str[0]=='Q')
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",query(a,b,1,n,1));
            }
            else{
                scanf("%d%d",&a,&b);
                if(str[0]=='A') update(a,b,1,n,1);
                else update(a,-b,1,n,1);
            }
        }
    }
    return 0;
}
