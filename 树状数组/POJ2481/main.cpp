#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int result[100005];
struct Node{
    int x,y,id;
}cow[100005];
int sum[100005],b[100005];
bool cmp( Node a , Node b)
{
    if(a.y!=b.y)
        return a.y>b.y;
    return a.x<b.x;
}
int lowbit( int i )
{
    return -i&i;
}

int get( int i )
{
    if(!i)
        return 0;
    return get( i-lowbit(i))+b[i];
}

void set( int i , int a)
{
    if( i > 100005)
        return;
    b[i]+=a;
    set( i+lowbit(i) , a );
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset( b , 0 , sizeof(b));
        memset( sum , 0 , sizeof(sum));
        if(!n)  break;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d%d",&cow[i].x,&cow[i].y);
            cow[i].id = i;
            cow[i].x++;
            cow[i].y++;
        }
        sort( cow , cow + n , cmp );
        sum[cow[0].id] = get(cow[0].x);
        set( cow[0].x , 1 );
        for( int i = 1 ; i < n ; i++ )
        {
            if( cow[i].x == cow[i-1].x && cow[i].y == cow[i-1].y )
                sum[cow[i].id] = sum[cow[i-1].id];
            else
                sum[cow[i].id] = get(cow[i].x);
            set( cow[i].x , 1 );
        }
        for( int i = 0 ; i < n ; i++ )
            printf("%d ",sum[i]);
        printf("\n");
    }
}
