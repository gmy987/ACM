#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 20005
using namespace std;
struct Node{
    int l,r;
}node[MAXN];
int flag[MAXN<<2];
int vis[MAXN<<2];
int a[MAXN<<2];
int b[MAXN<<2];
int ans;
void pushup( int t )
{
    if( flag[t<<1] && flag[t<<1|1])
        flag[t] = 1;
}
void update( int t , int l , int r , int x , int y , int val )
{
    if( flag[t] ) return;
    if( x <= l && r <= y )
    {
        flag[t] = 1;
        if(!vis[val])
        {
            ans++;
            vis[val] = 1;
        }
        return;
    }
    int mid = l + r >> 1;
    if( x <= mid ) update( t<<1 , l , mid , x , y , val );
    if( y > mid ) update( t<<1|1 , mid+1 , r , x , y , val );
    pushup(t);
}
int find( int target , int n )
{
    int l = 1 , r = n;
    int mid;
    while( l <= r )
    {
        mid = l+r>>1;
        if(b[mid]==target) return mid;
        if( target < b[mid] ) r = mid-1;
        else l = mid+1;
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int q;
        ans = 0;
        int num = 0;
        scanf("%d",&q);
        memset( flag , 0 , sizeof(flag));
        memset( vis , 0 , sizeof(vis) );
        for( int i = 0 ; i < q ; i++ )
        {
            scanf("%d%d",&node[i].l,&node[i].r);
            a[++num] = node[i].l;
            a[++num] = node[i].r;
        }
        sort( a+1 , a+num+1 );
        b[1] = a[1];
        int cnt = 1;
        for( int i = 2 ; i <= num ; i++ )
            if(a[i] != a[i-1] ) b[++cnt] = a[i];
        for( int i = cnt ; i > 1 ; i-- )
            if( b[i] != b[i-1] + 1 ) b[++cnt] = b[i-1]+1;
        sort( b+1 , b+cnt+1 );
        for( int i = q-1 ; i >= 0 ; i-- )
        {
            int ll = find(node[i].l,cnt);
            int rr = find(node[i].r,cnt);
            update( 1 , 1 , cnt , ll , rr, i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
