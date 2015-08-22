#include <iostream>
#include <cstdio>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#include <algorithm>

using namespace std;
const int maxn = 200005;
int MAX[ maxn << 2 ];

void pushUp(int rt)
{
    MAX[rt] = max(MAX[rt<<1],MAX[rt<<1|1]);
}

void build( int l , int r , int rt )
{
    if( l == r )
    {
        scanf("%d",&MAX[rt]);
        return;
    }
    int mid = l+r>>1;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int p , int rc, int l , int r , int rt )
{
    if( l == r )
    {
        MAX[rt] = rc;
        return;
    }
    int mid = l+r>>1;
    if( p <= mid )
        update( p , rc , lson );
    else
        update( p , rc , rson );
    pushUp(rt);
}

int query( int L, int R , int l , int r , int rt )
{
    if( L <= l && R >= r )
        return MAX[rt];
    int mid = l + r >> 1;
    int ret = 0;
    if( L <= mid )
        ret = max( ret , query( L , R ,lson ));
    if( R > mid )
        ret = max( ret , query( L , R , rson ));
    return ret;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        build(1,n,1);
        while(m--)
        {
            char op[2];
            int a , b;
            scanf("%s%d%d",&op,&a,&b);
            if( op[0] == 'Q' )
                printf("%d\n",query(a,b,1,n,1));
            else
                update( a , b , 1 , n , 1 );
        }
    }
    return 0;
}
