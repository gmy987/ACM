#include <iostream>

using namespace std;

int main()
{
    string a,b;
    while( cin >> a >> b)
    {
        int sum1 = 0,sum2 = 0;
        for( int i = 0 ; i < a.length() ; i++)
            sum1+=a[i]-'0';
        for( int i = 0 ; i < b.length() ; i++ )
            sum2+=b[i]-'0';
        cout<<sum1*sum2<<endl;
    }
    return 0;
}
