#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
int n;
struct Node{
    int x,y,z;
}node[200];
int dp[200];
bool cmp( Node a , Node b )
{
    if( a.x != b.x )
        return a.x > b.x;
    else
        return a.y > b.y;
}

int main()
{
    int t = 1;
    while(~scanf("%d",&n)&&n)
    {
        int a,b,c;
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            node[cnt].x = a;
            node[cnt].y = b;
            node[cnt++].z = c;
            node[cnt].x = b;
            node[cnt].y = a;
            node[cnt++].z = c;
            node[cnt].x = a;
            node[cnt].y = c;
            node[cnt++].z = b;
            node[cnt].x = c;
            node[cnt].y = a;
            node[cnt++].z = b; 
            node[cnt].x = b;
            node[cnt].y = c;
            node[cnt++].z = a;
            node[cnt].x = c;
            node[cnt].y = b;
            node[cnt++].z = a;
        }
        sort( node , node+cnt , cmp );
        for( int i = 0 ; i < cnt ; i++ )
            dp[i] = node[i].z;
        for( int i = 1 ; i < cnt ; i++ )
            for( int j = 0 ; j < i ; j++ )
            {
                if( node[j].x > node[i].x && node[j].y > node[i].y ) 
                    dp[i] = max( dp[i] , dp[j]+node[i].z );
            }
        int ans = 0;
        for( int i = 0 ; i < cnt ; i++ )
            ans = max( ans , dp[i] );
        printf("Case %d: maximum height = %d\n",t++,ans);
    }
    return 0;
}
