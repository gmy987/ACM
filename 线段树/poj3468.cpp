#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100005

using namespace std;
int n,q;
long long sum[MAXN<<2];
long long lazy[MAXN<<2];
void pushup( int t )
{
    sum[t] = sum[t<<1] + sum[t<<1|1];
}
void build( int t, int l , int r)
{
    lazy[t] = 0;
    if( l == r )
    {
        scanf("%lld",&sum[t]);
        return;
    }
    int mid = (l+r) >> 1;
    build(t<<1,l,mid);
    build(t<<1|1,mid+1,r);
    pushup(t);
}
void pushdown( int t , int m )
{
    if(lazy[t])
    {
        lazy[t<<1] += lazy[t];
        lazy[t<<1|1] += lazy[t];
        sum[t<<1] += (m-(m>>1))*lazy[t];
        sum[t<<1|1] += (m>>1)*lazy[t];
        lazy[t] = 0;
    }
}
void update( int t , int l , int r, int x , int y , int val )
{
    if( x <= l && r <= y )
    {
        sum[t] += (long long)(r-l+1)*val;
        lazy[t] += (long long)val;
        return;
    }
    pushdown( t , r-l+1 );
    int mid = ( l+r) >>1;
    if( x <= mid ) update( t<<1 , l , mid , x , y , val );
    if ( y > mid ) update( t<<1|1 , mid + 1 , r , x , y , val );
    pushup(t);
}
long long query( int t, int l , int r , int x , int y )
{
    if( x <= l && r <= y )
    {
        return sum[t];
    }
    pushdown( t , r-l+1 );
    int mid = ( l + r ) >> 1;
    long long ans = 0;
    if( x <= mid ) ans += query(t<<1,l,mid,x,y);
    if( y > mid ) ans += query( t<<1|1,mid+1,r,x,y);
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&q))
    {
        build(1,1,n);
        char str[5];
        int a,b,c;
        while(q--)
        {
            scanf("%s",str);
            if(str[0]=='Q')
            {
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(1,1,n,a,b));
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                update(1,1,n,a,b,c);
            }
        }
    }
    return 0;
}
