#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int y,n,k;
    while(scanf("%d%d%d",&y,&k,&n)!=EOF)
    {
        bool flag = false;
        for( int i = k ; i<=n ; i+=k )
        {
            if( i > y )
            {
                printf("%d ", i - y);
                flag = true;
            }
        }
        if( flag == false )
            printf("-1");
        printf("\n");
    }
    return 0;
}


