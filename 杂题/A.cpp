#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d=168;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        if( a <= d )
            printf("CRASH %d\n",a);
        else if( b <= d )
            printf("CRASH %d\n",b);
        else if( c <= d )
            printf("CRASH %d",c);
        else{
            printf("NO CRASH\n");
        }
    }
    return 0;
}
