#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 100005

using namespace std;
struct Node{
    int val,pos;
}node[MAXN];
int a,b,c;
bool cmp( Node a , Node b )
{
    return a.val<b.val;
}

int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&node[i].val);
            node[i].pos = i;
        }
        sort( node + 1 , node+1+n , cmp );
        for( int i = 0 ; i < q ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            int mid = (b-a+1)>>1;
            if( c > mid )
            {
                c = (b-a+1)-c+1;
                int k;
                for( k = n ; k>= 1 ; k-- )
                {
                    if( node[k].pos>=a&&node[k].pos<=b)
                        c--;
                    if(c==0) break;
                }
                printf("%d\n",node[k].val);
            }
            else
            {
                int k;
                for( k = 1 ; k <= n ; k++ )
                {
                    if( node[k].pos<=b && node[k].pos>=a )
                        c--;
                    if( c == 0 ) break;
                }
                printf("%d\n",node[k].val);
            }
        }
    }
    return 0;
}
