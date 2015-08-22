#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 20
using namespace std;

struct Node
{
    int num,id;

}frog[MAXN];

bool cmp( Node a , Node b )
{
    return a.num > b.num;
}

int map[MAXN][MAXN],n;

int main()
{//freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset( map , 0 , sizeof( map ));
        memset( frog , 0 , sizeof( frog ));
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&frog[i].num);
            frog[i].id = i;
        }
        bool flag = true;
        while( true )
        {
            sort( frog + 1 , frog+ n + 1 , cmp );
            if( frog[1].num == 0 ) break;
            for( int i = 1 ; i <= frog[1].num ; i++ )
            {
                frog[i+1].num--;
                if( frog[i+1].num < 0 )
                {
                    flag = false;
                    break;
                }
                map[frog[1].id][frog[1+i].id] = 1;
                map[frog[i+1].id][frog[1].id] = 1;
            }
            frog[1].num = 0;
            if(!flag) break;
        }

        if(flag)
        {
            printf("YES\n");
            for( int i = 1 ; i <= n ; i++ )
            {
                for( int j = 1 ; j <= n ; j++ )
                {
                    if( j==1 )
                        printf("%d",map[i][j]);
                    else
                        printf(" %d",map[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        else
            printf("NO\n\n");
    }
    return 0;
}
