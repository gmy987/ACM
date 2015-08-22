#include <iostream>

using namespace std;

int inverseCnt( int unsorted[] , int left , int right )
{
    if( left + 1 > right )
        return 0;
    int mid = (left+right)/2;
    int inverstCount = 0;
    inverstCount+=inverseCnt( unsorted , left , mid );
    inverstCount+=inverseCnt( unsorted , mid+1 , right );

    int i1 = left ,i2 = mid+1 , i3 = 0;
    int *tmp = new int[ right - left + 1 ];
    while( i1<=mid && i2 <= right)
    {
        if( unsorted[i1]>unsorted[i2])
        {
            for(int i = i1 ; i<=mid ; i++)
            {
                inverstCount++;
                cout<< unsorted[i] << " " << unsorted[i2] <<endl;
            }
            tmp[i3++] = unsorted[i2++];
        }
        else
            tmp[i3++] = unsorted[i1++];
    }
    if( i1 <= mid)
    {
        for( int i = i1 ; i<= mid ; i++)
            tmp[i3++] = unsorted[i];
    }
    if( i2 <= right )
    {
        for( int i = i2 ; i<=right ; i++)
            tmp[i3++] = unsorted[i];
    }
    for( int i = 0 , j = left + i ; i<i3 ; i++,j++ )
        unsorted[j] = tmp[i];

    return inverstCount;

}

int main()
{
    int num;
    while( cin >> num )
    {
        int a[100000];
        for( int i = 0 ; i < num ; i++ )
            cin>>a[i];
        int cnt = 0 ;
        cnt = inverseCnt( a , 0 , num-1 );
        cout << cnt << endl ;
    }
    return 0 ;

}
