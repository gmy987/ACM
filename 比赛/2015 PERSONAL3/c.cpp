#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int a,b,c;
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if( a > (b-c) ) printf("do not advertise\n");
        else if( a < (b-c) ) printf("advertise\n");
        else printf("does not matter\n");
    }
    return 0;
}
