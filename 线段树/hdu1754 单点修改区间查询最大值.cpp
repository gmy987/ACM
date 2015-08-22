#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 200005

using namespace std;
int n,m;
int sum[MAXN<<2];
int a,b;
void pushup( int t )
{
    sum[t] = max( sum[t<<1],sum[t<<1|1]);
}
void build( int t , int l ,int r )
{
    if( l == r )
    {
        scanf("%d",&sum[t]);
        return;
    }
    int mid = l + r >> 1 ;
    build( t<<1 , l , mid );
    build( t<<1|1 , mid+1 , r );
    pushup(t);
}
void update( int t , int l , int r ,int p , int val )
{
    if( l == r )
    {
        sum[t] = val;
        return;
    }
    int mid = l + r >> 1;
    if( p <= mid ) update( t<<1 , l , mid , p , val );
    else update( t<<1|1 , mid+1 , r , p , val );
    pushup(t);
}
int query( int t , int l , int r , int x, int y )
{
    if( x <= l && r <= y )
        return sum[t];
    int mid = l + r >> 1;
    int ans = -1;
    if( x <= mid ) ans = max( ans , query(t<<1,l,mid,x,y));
    if( y > mid ) ans = max( ans , query(t<<1|1,mid+1,r,x,y)); 
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( sum , 0 , sizeof(sum));
        build(1,1,n);
        char str[3];
        while(m--)
        {
            scanf("%s",str);
            scanf("%d%d",&a,&b);
            if( str[0] == 'Q' )
                printf("%d\n",query(1,1,n,a,b));
            else update(1,1,n,a,b);
        }
    }
    return 0;
}
