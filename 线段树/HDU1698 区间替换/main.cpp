#include <iostream>
#include <cstdio>
#include <cstring>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int maxn = 100005;
int sum[maxn<<2];
int col[maxn<<2];
void pushUp( int rt )
{
    sum[rt] = sum[rt << 1] + sum[rt<<1|1];
}

void pushDown ( int rt , int m )
{
    if(col[rt])
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        sum[rt<<1] = ( m - ( m >> 1) )*col[rt];
        sum[rt<<1|1] = (m >> 1)*col[rt];
        col[rt] = 0;
    }
}

void build ( int l , int r , int rt )
{
    col[rt] = 0 ;
    sum[rt] = 1;
    if( l == r )
        return;
    int mid = l + r >> 1;
    build ( lson );
    build ( rson );
    pushUp ( rt );
}

void update( int L , int R , int c , int l , int r , int rt )
{
    if( L <= l && R >= r )
    {
        col[rt] = c;
        sum[rt] = c*(r-l+1);
        return;
    }
    pushDown( rt , r - l + 1 );
    int mid = l + r >> 1;
    if( L <= mid )
        update( L , R , c , lson );
    if( R > mid )
        update( L , R , c , rson );
    pushUp( rt );
}

int main()
{
    int n,t,m;
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ )
    {
        memset(sum,0,sizeof(sum));
        memset(col,0,sizeof(col));
        scanf("%d%d",&t,&m);
        build(1,t,1);
        for( int j = 0 ; j < m ; j++ )
        {
            int a , b , c;
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,t,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",i,sum[1]);
    }
}
