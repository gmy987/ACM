#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100005
#define MOD 10007

using namespace std;

struct Node{
    int l,r;
    int p1,p2,p3;
    int l1,l2,l3;
}root[MAXN*6];
int n,m;
void build( int t , int a , int b )
{
    root[t].l = a;
    root[t].r = b;
    root[t].p1 = root[t].p2 = root[t].p3 = 0;
    root[t].l1 = root[t].l2 = root[t].l3 = 0;
    root[t].l2 = 1;
    if( a == b ) return;
    int m = ( root[t].l + root[t].r ) >> 1;
    build( 2*t , a , m );
    build( 2*t + 1 , m+1 , b );
}
void pushup(int t)
{
    root[t].p1 = (root[t*2].p1%MOD+root[t*2+1].p1%MOD)%MOD;
    root[t].p2 = (root[t*2].p2%MOD+root[t*2+1].p2%MOD)%MOD;
    root[t].p3 = (root[t*2].p3%MOD+root[t*2+1].p3%MOD)%MOD;
}
void change_eql(int t,int val)
{
    int len = root[t].r-root[t].l+1;
    root[t].l1 = 0;
    root[t].l2 = 1;
    root[t].l3 = val%MOD;
    root[t].p1 = (val*len)%MOD;
    root[t].p2 = (((val*len)%MOD*val)%MOD*len)%MOD;
    root[t].p3 = ((((val*len)%MOD*val)%MOD*val)%MOD*len)%MOD;
}
void change_addmul( int t , int val1 , int val2 )
{
    int len = root[t].r-root[t].l+1;
    root[t].l1 = ((root[t].l1*val2)%MOD+val1%MOD)%MOD;
    root[t].l2 = (root[t].l2*val2)%MOD;
    root[t].p3 = ((((val1*val1)%MOD*val1)%MOD*len)%MOD+(((root[t].p3*val2)%MOD*val2)%MOD*val2)%MOD+(((3*val2*val2)%MOD*val1)%MOD*root[t].p2)%MOD+(((3*val2*val1)%MOD*val1)%MOD*root[t].p1)%MOD)%MOD;
    root[t].p2 = (((val1*val1)%MOD*len)%MOD+((val2*val2)%MOD*root[t].p2)%MOD+((2*val1*val2)%MOD*root[t].p1)%MOD)%MOD;
    root[t].p1 = ((val2*root[t].p1)%MOD+(val1*len)%MOD)%MOD;
}
void pushdown_eq(int t)
{
    if( root[t].l == root[t].r ) return;
    if( root[t].l3!=0 )
    {
        change_eql(2*t,root[t].l3);
        change_eql(2*t+1,root[t].l3);
        root[t].l3 = 0;
    }
}
void pushdown_addmul( int t )
{
    if( root[t].l == root[t].r ) return;
    if( root[t].l1 != 0 || root[t].l2 != 1 )
    {
        change_addmul(2*t,root[t].l1,root[t].l2);
        change_addmul(2*t+1,root[t].l1,root[t].l2);
        root[t].l1 = 0;
        root[t].l2 = 1;
    }
}
void equal( int t , int x , int y , int val )
{
    int ll = root[t].l , rr = root[t].r;
    if( x == ll && y == rr )
    {
        change_eql(t,val);
        return;
    }
    pushdown_eq(t);
    pushdown_addmul(t);
    int mid = ( ll + rr ) >> 1;
    if( x <= mid ) equal( 2*t , x , min(mid,y) , val );
    if( mid < y ) equal ( 2*t+1 , max(mid+1,x) , y , val );
    pushup(t);
}
void addmul( int t , int x, int y , int val ,int op )
{
    int ll = root[t].l , rr = root[t].r;
    if( ll == x && rr == y )
    {
        if( op == 1 )
        {
            int len = ll-rr+1;
            root[t].l1 = (root[t].l1+val)%MOD;
            root[t].p3 = ((((val*val)%MOD*val)%MOD*len)%MOD+((3*val*val)%MOD*root[t].p1)%MOD+((root[t].p2*val)%MOD*3)%MOD+root[t].p3%MOD)%MOD;
            root[t].p2 = (((val*val)%MOD*len)%MOD+(2*val*root[t].p1)%MOD+root[t].p2%MOD)%MOD;
            root[t].p1 = (root[t].p1%MOD+(val*len)%MOD)%MOD;
        }
        else
        {
            root[t].l1 = (root[t].l1*val)%MOD;
            root[t].l2 = (root[t].l2*val)%MOD;
            root[t].p3 = (((root[t].p3*val)%MOD*val)%MOD*val)%MOD;
            root[t].p2 = ((root[t].p2*val)%MOD*val)%MOD;
            root[t].p1 = (root[t].p1*val)%MOD;
        }
        return;
    }
    pushdown_eq(t);
    pushdown_addmul(t);
    int mid = ll + rr >> 1;
    if( x <= mid ) addmul( 2*t , x , min(mid,y) , val , op );
    if( y > mid ) addmul( 2*t+1 , max(mid+1,x) , y , val , op );
    pushup(t);
}
int query( int t , int x , int y , int op )
{
    int ll = root[t].l , rr = root[t].r;
    if( ll == x && rr == y )
    {
        if( op == 1 )
            return root[t].p1%MOD;
        else if( op == 2 )
            return root[t].p2%MOD;
        else return root[t].p3%MOD;
    }
    pushdown_eq(t);
    pushdown_addmul(t);
    int mid = ll + rr >> 1;
    int ans = 0;
    if( x <= mid )
    {
        ans+=query( 2*t, x , min(mid,y) , op );
        ans%=MOD;
    }
    if( mid < y )
    {
        ans+=query( 2*t+1 , max(mid+1,x) , y , op );
        ans%=MOD;
    }
    return ans;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if( n == 0 && m == 0 )
            break;
        int a,x,y,c;
        build(1,1,n);
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d%d%d",&a,&x,&y,&c);
            if( a == 1 )
                addmul( 1 , x, y , c , 1);
            else if( a == 2 )
                addmul( 1 , x , y , c , 2 );
            else if( a == 3 )
                equal( 1 , x , y , c );
            else printf("%d\n",query(1,x,y,c));
        }
    }
    return 0;
}
