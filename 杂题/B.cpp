#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if( n < 0 )
            break;
        int sum = 0;
        int a,b;
        int pre = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d%d",&a,&b);
            sum += a*(b-pre);
            pre = b;
        }
        printf("%d miles\n",sum);
    }
    return 0;
}
