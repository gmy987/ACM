#include <iostream>
#include <cstdio>
#include <cstring>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

using namespace std;
const int maxn = 5005;
int sum[maxn<<2];

void pushUp( int rt )
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];//因为rt<<1为偶数，所以|1相当于+1
}

void build( int l , int r , int rt )
{
    sum[0] = 0;
    if( l == r )
        return;
    int mid = r + l >> 1;
    build(lson);
    build(rson);
}

void update( int p , int l , int r , int rt )
{
    if( l == r )
    {
        sum[rt]++;
        return;
    }
    int mid = l + r >> 1;
    if( p <= mid )
        update(p,lson);
    else
        update(p,rson);
    pushUp(rt);
}

int query( int L , int R , int l , int r , int rt )
{
    if( L <= l && R >= r )
        return sum[rt];
    int mid = l + r >> 1;
    int ret = 0;
    if( L <= mid )
        ret+=query(L,R,lson);
    if( R > mid )
        ret += query(L,R,rson);
    return ret;
}

int x[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(sum,0,sizeof(sum));
        build( 0 , n-1 , 1 );
        int sum = 0;
        //算最初数组的逆序数
        for( int i = 0 ; i < n ; i ++ )
        {
            scanf("%d",&x[i]);
            sum += query( x[i] , n - 1 , 0 , n - 1 , 1 );
            update( x[i] , 0 , n - 1 , 1 );
        }
        int ret = sum;

        //每个循环算新的逆序数
        //原来逆序数为sum , 则新的逆序数 = sum + n - x[i] - x[i] - 1
        for ( int i = 0 ; i < n ; i++ )
        {
            sum += n - x[i] - x[i] - 1;
            ret = min( ret , sum );
        }
        printf("%d\n",ret);
    }
}
