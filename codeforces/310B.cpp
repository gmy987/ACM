#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1005

using namespace std;
int a[MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int cnt = 0,num = 0;
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        while( cnt++ <= n )
        {
            num = 0;
            for( int i = 0 ; i < n ; i++ )
            {
                if( i%2 )
                {
                    a[i] = (a[i] ? a[i]-1 : n-1);
                }
                else{
                    a[i] = (a[i] == n-1?0:a[i]+1);
                }
                if(a[i]==i)
                    num++;
            }
            if( num == n )
                break;
        }
        if( num == n )
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
