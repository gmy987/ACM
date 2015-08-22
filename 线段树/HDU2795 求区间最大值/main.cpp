#include <iostream>
#include <cstdio>
#include <algorithm>
#define lson l , mid , rt<<1
#define rson mid+1 , r , rt<<1|1
using namespace std;
int w,h,n;
const int maxn = 200005;
int m[maxn<<2];

void pushUp( int rt )
{
    m[rt] = max( m[ rt << 1] , m[ rt << 1 | 1 ]);
}

void build( int l , int r , int rt )
{
    m[rt] = w;
    if( l == r ) return;
    int mid = l + r >> 1;
    build( lson );
    build( rson );
}

int query ( int x , int l , int r , int rt )
{
    if( l == r )
    {
        m[rt]-=x;
        return l;
    }
    int mid = r + l >> 1;
    int ret = (m[rt<<1]>=x)?query(x,lson):query(x,rson);
    pushUp(rt);
    return ret;
}

int main()
{
    while(~scanf("%d%d%d",&h,&w,&n))
    {
        if( h >= n ) h = n;
        build ( 1 , h , 1 );
        while(n--)
        {
            int x;
            scanf("%d",&x);
            if(m[1]<x) printf("-1\n");
            else
                printf("%d\n",query(x,1,h,1));
        }
    }
    return 0;
}
