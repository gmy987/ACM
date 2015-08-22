#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    char a[200];
    int n;
    cin >> n;
    gets(a);
    int cas = 1;
    for( int i = 0 ; i < n ; i++ )
    {
        gets(a);
        int temp = 0;
        int m = 0;
        cout << a;
        for( int j = 0 ; j < strlen(a) ; j++ )
        {
            m = max( m , temp );
            if( a[j] == '[')
                temp++;
            else
                temp--;
        }
        printf("%d %d\n",cas++,1<<m);
    }
    return 0;
}
