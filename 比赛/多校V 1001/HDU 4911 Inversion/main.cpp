/*
#include <iostream>
#include <cstdio>
#include <cstring>
#define lson l , mid , rt << 1
#define rson mid + 1 , r , rt << 1|1
#define MAX 100005
using namespace std;
int sum[MAX << 2];
void pushUp( int rt )
{
    sum[rt] = sum[rt << 1] + sum[rt <<1|1];
}

void build( int l , int r , int rt )
{
    sum[0] = 0;
    if( l == r )
        return ;
    int mid = l + r >> 1;
    build( lson );
    build( rson );
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
        update( p , lson);
    else
        update( p , rson );
    pushUp(rt);
}

long long query ( int L , int R ,int l , int r ,int rt )
{
    if( L <= l && r <= R )
        return sum[rt];
    int mid = l + r >> 1;
    long long ret = 0;
    if( L <= mid )
        ret += query( L , R , lson );
    if( R > mid )
        ret += query( L , R , rson );
    return ret;
}
int n,k,x[MAX];
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        memset( sum , 0 ,sizeof( sum ));
        build( 0 , n-1 , 1);
        long long ans = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d",&x[i]);
            ans += query( x[i] , n - 1 , 0 , n - 1 , 1);
            update( x[i] , 0 , n - 1 , 1 );
        }
        cout << ans << endl;
        if( ans >= k)
            printf("%lld\n",ans-(long long )k);
        else
            printf("0\n");
    }
}
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 100005
using namespace std;

int temp[MAX] , a[MAX];
long long cnt = 0;

void merge_( int left , int mid , int right )
{
    int i1 = left , i2 = mid + 1 , i3 = 0;
    while( i1 <= mid && i2 <= right )
    {
        if( a[i1] > a[i2] )
        {
            cnt += mid - i1 + 1;
            temp[i3++] = a[i2++];
        }
        else
            temp[i3++] = a[i1++];
    }
    while( i1 <= mid )
        temp[i3++] = a[i1++];
    while( i2 <= right )
        temp[i3++] = a[i2++];
    for( int i = 0 , j = left + i ; i < i3 ; i++,j++)
        a[j] = temp[i];
}

void mergeSort( int left , int right )
{
    if( left + 1 > right )
        return;
    int mid = left + right >> 1;
    mergeSort( left , mid );
    mergeSort( mid + 1 , right );
    merge_( left , mid , right);
}

int n , k ;

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        mergeSort( 0 , n - 1 );
        if ( cnt > k )
            printf("%I64d\n",cnt-(long long)k);
        else
            printf("0\n");
    }
    return 0;
}







