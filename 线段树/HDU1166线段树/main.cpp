#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 50005;
int sum[maxn<<2];

void pushUp( int rt )
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}

void build( int l , int r , int rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        return;
    }
    int mid = l + r >> 1;
    build( l , mid , rt << 1);
    build( mid + 1 , r , rt << 1 | 1);
    pushUp(rt);
}

void update( int p , int add , int l , int r , int rt )
{
    if( l == r ){
        sum[rt] += add;
        return;
    }
    int mid = l + r >> 1;
    if( p <= mid )
        update( p , add , l , mid ,rt << 1);
    else
        update( p , add , mid+1 , r , rt << 1 | 1 );
    pushUp(rt);
}

int query( int L , int R ,int l , int r , int rt )
{
    if( L <= l && r <= R )
        return sum[rt];
    int mid = l + r >> 1;
    int ret = 0;
    if( L <= mid )
        ret +=  query( L , R , l , mid , rt << 1 );
    if( R > mid )
        ret += query( L, R , mid+1 , r , rt << 1 | 1);
    return ret;
}

int main()
{
    int t,n,cnt = 1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",cnt);
        cnt++;
        scanf("%d",&n);
        build(1,n,1);
        char op[10];
        while(~scanf("%s",&op))
        {
            if(op[0]== 'E')
                break;
            int i,j;
            scanf("%d%d",&i,&j);
            if(op[0]=='Q')
                printf("%d\n",query(i,j,1,n,1));
            else if(op[0] == 'A')
                update(i,j,1,n,1);
            else
                update(i,-j,1,n,1);
        }
    }
    return 0;
}
