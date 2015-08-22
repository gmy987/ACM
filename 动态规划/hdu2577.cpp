#include <cstdio>
#include <cstring>
#include <iostream>
#include <cctype>
#define MAXN 105

using namespace std;
int a[MAXN],b[MAXN];
int t;
char str[MAXN];

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int len = strlen(str);
        a[0] = 0 ;
        b[0] = 1 ;
        for( int i = 0 ; i < len ; i++ )
        {
            if( islower(str[i]) )
            {
                a[i+1] = min(a[i]+1 , b[i]+2 );
                b[i+1] = min(a[i]+2, b[i]+2 );
            }
            else
            {
                a[i+1] = min( a[i]+2, b[i]+2 );
                b[i+1] = min( a[i]+2 , b[i]+1 );
            }
        }
        printf("%d\n",min(a[len],b[len]+1));
    }
    return 0;
}
