#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 50005

using namespace std;
int lsum[MAXN<<2],rsum[MAXN<<2],sum[MAXN<<1];
int lazy[MAXN<<2];
void pushup( int t , int l , int r )
{
    int m = r-l+1;
    lsum[t] = lsum[t<<1];
    rsum[t] = rsum[t<<1|1];
    if( lsum[t<<1] == (m-(m>>1)))
        lsum[t]+=lsum[t<<1|1];
    if( rsum[t<<1|1] == (m>>1) )
        rsum[t] += rsum[t<<1];
    sum[t] = max(max(sum[t<<1],sum[t<<1|1]),rsum[t<<1]+lsum[t<<1|1]);
}
void build(int t,int l ,int r)
{
    lazy[t] = -1;
    sum[t] = lsum[t] = rsum[t] = r-l+1;
    if(l==r) return;
    int mid = l+r>>1;
    build(t<<1,l,mid);
    build(t<<1|1,mid+1,r);
}
void pushdown( int t , int m )
{
    if(lazy[t]!=-1)
    {
        lazy[t<<1] = lazy[t<<1|1] = lazy[t];
        if(lazy[t]==1)
        {
            sum[t<<1] = lsum[t<<1] = rsum[t<<1] = 0;
            sum[t<<1|1] = lsum[t<<1|1] = rsum[t<<1|1] = 0;
        }
        else
        {
            sum[t<<1] = lsum[t<<1] = rsum[t<<1] = m-(m>>1);
            sum[t<<1|1] = lsum[t<<1|1] = rsum[t<<1|1] = (m>>1);
        }
        lazy[t] = -1;
    }
}
void update( int t ,int l , int r ,int x , int y , int op )
{
    if( x <= l && r <= y )
    {
        lazy[t] = op;
        if( op == 1 )
        {
            sum[t] = lsum[t] = rsum[t] = 0;
        }
        else
        {
            sum[t] = lsum[t] = rsum[t] = r-l+1;
        }
        return;
    }
    pushdown( t , r-l+1); 
    int mid = l+r>>1;
    if( x <= mid ) update( t<<1 , l , mid , x , y , op );
    if( y > mid ) update( t<<1|1 , mid+1 , r , x , y , op );
    pushup( t , l , r );
}
int query( int t , int l , int r , int val )
{
    if( l == r )
        return l;
    pushdown( t , r-l+1 );
    int mid = l + r >> 1;
    if( sum[t<<1]>=val ) return query( t<<1 , l , mid , val );
    else if( rsum[t<<1]+lsum[t<<1|1] >= val ) return mid-rsum[t<<1]+1;
    else return query(t<<1|1,mid+1,r,val);
}
int n,m,op,a,b;

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        build(1,1,n);
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d",&a);
                if(sum[1]<a)
                    printf("0\n");
                else
                {
                    int ans = query(1,1,n,a);
                    printf("%d\n",ans);
                    update(1,1,n,ans,ans+a-1,op);
                }
            }
            else
            {
                scanf("%d%d",&a,&b);
                update(1,1,n,a,a+b-1,op);
            }
        }
    }
    return 0;
}
