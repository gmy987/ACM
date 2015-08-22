#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[105] ;
    int b[105] = {0} ;
    while( cin >> a)
    {
        if(strcmp(a , "0")==0)
            break;
        int len = strlen(a);
        for( int i = 0 ; i < len ; i++ )
        {
            b[i] += a[len-1-i]-'0';
        }
    }
    for( int i = 0 ; i < 105 ; i++ )
    {
        if( b[i] >= 10 )
        {
            b[i+1] = b[i]/10;
            b[i] = b[i]%10;
        }
    }
    int k = 105;
    while( b[--k] == 0);
    while( k>=0 )
        cout<<b[k--];
    cout<<endl;
}
