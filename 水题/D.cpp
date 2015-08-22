#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for( int i = 0 ; i < n ; i++ )
    {
        string a;
        getline(cin,a);
        int mem = 0;
        bool flag = false;
        for( int k = 0 ; k < a.length() ; k++ )
        {
            if( a[k] == ' ')
            {
                if( mem != 0 )
                    printf(" ");
                for( int l = k-1 ; l >= mem ; l-- )
                    printf("%c",a[l]);
                mem = k+1;
            }
        }
        if(mem)
            printf(" ");
        for( int k = a.length()-1 ; k >= mem ; k-- )
            printf("%c",a[k]);
        printf("\n");
    }
    return 0;
}
