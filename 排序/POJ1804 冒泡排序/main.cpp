#include <iostream>

using namespace std;

int bubbleSort ( int a[] , int n )
{
    int cnt = 0 ;
    for( int j = 0 ; j < n - 1 ; j++  )
    {
        for( int i = 0 ; i < n - j - 1 ; i++ )
        {
            if( a[i] > a[i+1] )
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                cnt++;
            }
        }
    }
    return cnt;
}

int reverseBubbleSort( int a[] , int n )
{
    int cnt = 0 ;
    for ( int j = 0 ; j < n - 1 ; j++ )
    {
        for( int i = n - 1 ; i > j ; i-- )
        {
            if( a[i] < a[i-1])
            {
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin>>n;
    for( int i = 0 ; i < n ; i++ )
    {
        int num;
        cin>>num;
        int *a = new int[num];
        int *b = new int[num];
        for( int j = 0 ; j < num ; j++ )
            cin>>a[j];
        for( int i = 0 ; i < num ; i++ )
            b[i] = a[i];
        int cnt1 = bubbleSort( a , num );
        int cnt2 = reverseBubbleSort( b , num );
        cout<<"Scenario #"<<i+1<<":"<<endl;
        cout<<(cnt1<cnt2?cnt1:cnt2)<<endl<<endl;
        delete []a;
        delete []b;
    }
    return 0;
}
