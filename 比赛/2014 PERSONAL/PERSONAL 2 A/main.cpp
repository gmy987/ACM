#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double calculate( double x )
{
    return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}

int main()
{
    int t;
    scanf("%d" ,&t);
    while(t--)
    {
        double num;
        scanf("%lf" , &num);
        if( calculate( 0 ) > num || calculate( 100 ) < num )
        {
            printf( "No solution!\n");
            continue;
        }
        double left = 0 , right = 100;
        double mid = ( left + right)/2;
        while( fabs(calculate(mid)-num )> 1e-5 )
        {
            if( calculate( mid ) < num )
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right)/2;
        }
        printf( "%.4lf\n" , mid);
    }
    return 0;
}
