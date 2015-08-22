#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string b;
    while( getline( cin , b ))
    {
        if(b=="ENDOFINPUT" )
            break;
        if( b== "START"||b=="END")
            continue;
        int len = b.length();
        for( int i = 0 ; i < len ; i++ )
        {
            if( isalpha(b[i]))
                b[i] = b[i]-5 < 'A' ? b[i]-5+26 : b[i]-5;
        }
        cout<<b<<endl;
    }
    return 0;

}
