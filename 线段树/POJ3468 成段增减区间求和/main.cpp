#include <iostream>
#include <cstring>
#include <cstdio>
#define lson l , mid , rt << 1
#define rson mid + 1 , r , rt << 1|1

using namespace std;
const int maxn = 111111;
long long sum[maxn << 2];
long long add[maxn << 2];
void pushUp ( int rt )
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushDown( int rt , int m )
{
    if( add[rt] )
    {
         add[rt<<1]+=add[rt];
         add[rt<<1|1]+=add[rt];
         sum[rt<<1]+=(m-(m>>1))*add[rt];
         sum[rt<<1|1] += (m>>1)*add[rt];
         add[rt] = 0;
    }
}
void build ( int l , int r , int rt )
{
    add[rt] = 0;
    if( l == r )
    {
        scanf("%lld",&sum[rt]);
        return;
    }
    int mid = l + r >> 1;
    build ( lson );
    build ( rson );
    pushUp ( rt );
}

void update( int L , int R , int c , int l , int r , int rt )
{
    if ( L <= l&& r <= R )
    {
        sum[rt] += (long long)c*(r - l + 1);
        add[rt] += c;
        return;
    }
    pushDown( rt , r - l + 1);
    int mid = l + r >> 1;
    if( L <= mid )
        update( L , R , c ,lson );
    if( R > mid )
        update( L , R , c , rson );
    pushUp(rt);
}

long long query ( int L , int R , int l , int r , int rt )
{
    if( L <= l && R >= r )
        return sum[rt];
    pushDown(rt,r-l+1);
    int mid = l + r >> 1;
    long long ret = 0;
    if( L <= mid )
        ret += query( L , R , lson );
    if( R > mid )
        ret += query ( L , R , rson );
    return ret;
}

int main()
{
    int n,q;
    memset( sum ,0 ,sizeof(sum));
    memset( add , 0 , sizeof(add));
    scanf("%d%d",&n,&q);
    build ( 1 , n , 1 );
    while(q--)
    {
        char op[2];
        scanf("%s",&op);
        int a,b,c;
        if(op[0]=='Q')
        {
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(a,b,1,n,1));
        }
        else
        {
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,n,1);
        }
    }
}
