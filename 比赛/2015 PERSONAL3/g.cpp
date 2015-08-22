#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000005

using namespace std;
struct Node{
    int x,y;
}node[MAXN];
bool cmp( Node a , Node b )
{
    if( a.x == b.x )
        return a.y < b.y;
    else return a.x < b.x;
}
long long cnt;
int n,m,k;
int temp[MAXN];
void merge_( int l , int m , int r )
{
    int i1 = l , i2 = m + 1 , i3 = 0;
    while( i1 <= m && i2 <= r )
    {
        if(node[i1].y > node[i2].y)
        {
            cnt+=((long long)m)-i1+1;
            temp[i3++] = node[i2++].y;
        }
        else temp[i3++] = node[i1++].y;
    }
    while( i1 <= m )
        temp[i3++] = node[i1++].y;
    while( i2 <= r )
        temp[i3++] = node[i2++].y;
    for( int i = 0 , j = l ; i < i3 ; i++ , j++ )
        node[j].y = temp[i];
}
void mergeSort( int l , int r )
{
    if( l + 1 > r )
        return;
    int mid = (l + r)>> 1;
    mergeSort( l , mid );
    mergeSort( mid + 1 , r );
    merge_( l , mid , r );
}
int main()
{
    int t;
    scanf("%d",&t);
    int cas = 1;
    while(t--)
    {
        cnt = 0;
        scanf("%d%d%d",&n,&m,&k);
        for( int i = 0 ; i < k ; i++ )
            scanf("%d%d",&node[i].x,&node[i].y);
        sort(node,node+k,cmp);
        mergeSort(0,k-1);
        printf("Test case %d: %lld\n",cas++,cnt);
    }
    return 0;
}
