#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 50005

using namespace std;
int sum[MAXN<<2];
void pushup( int t )
{
    sum[t] = sum[t<<1]+sum[t<<1|1];
}
void build( int t , int l , int r )
{
    if( l == r )
    {
        scanf("%d",&sum[t]);
        return;
    }
    int mid = l + r >> 1;
    build( t<<1 , l , mid );
    build( t<<1|1, mid+1 , r );
    pushup(t);
}

void update( int t , int l , int r , int p , int val )
{
    if( l == r )
    {
        sum[t] += val;
        return;
    }
    int mid = l + r >> 1;
    if( p <= mid ) update( t<<1 , l , mid , p , val );
    else update( t<<1|1 , mid+1 , r , p , val );
    pushup(t);
}
int query( int t, int l , int r , int x , int y )
{
    if( x <= l &&  y>=r  )
        return sum[t];
    int mid = l + r >> 1;
    int ans = 0;
    if( x <= mid )
        ans+=query( t<<1 , l , mid , x , y );
    if( mid < y )
        ans+=query( t<<1|1, mid+1 , r , x , y );
    return ans;
}
int n;

int main()
{
    int t;
    char str[10];
    scanf("%d",&t);
    for( int i = 1 ; i<= t ; i++ )
    {
        scanf("%d",&n);
        build(1,1,n);
        int a,b;
        printf("Case %d:\n",i);
        while(true)
        {
            scanf("%s",str);
            if( str[0] == 'E' ) break;
            else
            {
                scanf("%d%d",&a,&b);
                if( str[0] == 'Q')
                    printf("%d\n",query(1,1,n,a,b));
                else if(str[0]=='A')
                    update(1,1,n,a,b);
                else update(1,1,n,a,-b);
            }
        }
    }
    return 0;
}
