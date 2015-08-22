#include <iostream>
#include <cstdio>

using namespace std;

int n , m , mid;

bool compare( int mid , int money[] )
{
    int sum = 0 , cnt = 1;
    for( int i = 0 ; i < n ; i++ )
    {
        if( sum + money[i] <= mid )
            sum+=money[i];
        else
        {
            cnt++;
            sum = money[i];
        }
    }
    return ( cnt > m ? true : false );
}

int main()
{
    while( scanf("%d%d",&n,&m)!=EOF)
    {
        int *money = new int[n];
        int low = 0,high = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d",&money[i]);
            high+=money[i];
            if( low < money[i] )
                low = money[i];
        }
        mid = ( low + high)/2;
        while( low < high )
        {
            if( compare( mid , money ))
                low = mid + 1;
            else
                high = mid - 1;
            mid = ( low + high )/2;
        }
        printf("%d\n",mid);
        delete []money;

    }
}
