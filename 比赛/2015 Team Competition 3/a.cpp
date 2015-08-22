#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int n,k;
    int cas = 1;
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("Case %d: ",cas++);
        if( k == 1 && (n&1) )
            printf("first\n");
        else if( k >= n )
            printf("first\n");
        else printf("second\n");
    }
    return 0;
}
