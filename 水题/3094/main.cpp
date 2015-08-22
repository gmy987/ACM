#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string msg;
    while( getline( cin , msg ))
    {
        if( msg == "#" )
            break;
        int len = msg.length(),sum = 0;
        for( int i = 0 ; i < len ; i++ )
        {
            if(isalpha(msg[i]))
                sum=sum+(msg[i]-'A' + 1)*(i+1);
        }
        cout<<sum<<endl;
    }
}
