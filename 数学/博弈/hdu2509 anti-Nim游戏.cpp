#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a;
        int sg = 0;
        bool flag = false;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d",&a);
            sg ^= a;
            if( a  > 1 )
                flag = true;
        }
        if(!sg&&flag)
            printf("No\n");
        else if(sg&&!flag)
            printf("No\n");
        else printf("Yes\n");

    }
    return 0;
}
