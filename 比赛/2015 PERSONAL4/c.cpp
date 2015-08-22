#include <cstdio>
#include<cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100005

using namespace std;
int n;
struct Node{
    int x,y;
}node[MAXN];
bool cmp1( Node a , Node b )
{
    if( a.x == b.x )
        return a.y < b.y;
    else return a.x < b.x;
}
bool cmp2( Node a , Node b )
{
    if( a.y == b.y )
        return a.x < b.x;
    else return a.y < b.y;
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        for( int i = 0 ; i < n ; i++ )
            scanf("%d%d",&node[i].x,&node[i].y);
        sort( node , node + n , cmp1 );
        int ans = 0;
        for( int i = 0 ; i < n-1 ; i++ )
            if( node[i].x == node[i+1].x )
            {
                ans+=node[i+1].y-node[i].y;
                i++;
            }
        sort( node , node + n , cmp2 );
        for( int i = 0 ; i < n-1 ; i++ )
            if( node[i].y == node[i+1].y )
            {
                ans+=node[i+1].x-node[i].x;
                i++;
            }
        printf("The length of the fence will be %d units.\n",ans);
    }
    return 0;
}
