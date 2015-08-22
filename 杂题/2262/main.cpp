#include <iostream>
#include <cmath>

using namespace std;
bool isPrime( int a )
{
    if( a == 1 )
        return false;
    if( a == 2 )
        return true;
    for( int i = 2 ; i <= sqrt(a) ; i++ )
    {
        if( a%i == 0 )
            return false;
    }
    return true;
}

int main()
{
    int n ;
    while( cin >> n && n != 0 )
    {
        for( int i = 2 ; i < n ; i++)
        {
            if(isPrime(i)&&isPrime(n-i)){
                cout<<n<<" = "<<i<<" + "<< n-i <<endl;
                break;
            }
        }
    }
    return 0;
}
