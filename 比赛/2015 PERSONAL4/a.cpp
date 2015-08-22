#include <cstdio>
#include <cstring>
#include <iostream>
#define maxn 55

using namespace std;
int a[maxn];
int vis[maxn];
struct Node{
    int l,r;
}node[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        memset( vis , 0 , sizeof(vis) );
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d",&a[i]);
        node[1].l = 0 , node[1].r = 2*a[1];
        for( int i = 2 ; i <=n ; i++ )
        {
            node[i].l = 0;
            for( int k = 1 ; k < i ; k++ )
            {
                int tmp;
                if( a[k] >= a[i] ) tmp = node[k].l+a[k]+a[i];
                else tmp = node[k].l+3*a[k]-a[i];
                if( tmp > node[i].l ) node[i].l = tmp; 
            }
            node[i].r = node[i].l+2*a[i];
        }
        for( int i = 2 ; i <= n ; i++ )
            for( int k = 1 ; k < i ; k++ )
            {
                if( a[i] > a[k] && node[i].l < node[k].r )
                    node[k].r = node[i].l;
                else if( a[i] < a[k] && node[k].r > node[i].l )
                    node[i].l = node[k].r;
            }
        bool flag = true;
        for( int i = 1 ; i <= n ; i++ )
            if( node[i].l < node[i].r && flag )
                printf("%d",i),flag = false;
            else if( node[i].l < node[i].r )
                printf(" %d",i);
        printf("\n");
        
    }
    return 0;
}
