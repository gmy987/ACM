jj#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>

using namespace std;

long long cnt = 0;
int temp[500001] , a[500001];

void merge_( int a[] , int left , int mid , int right )
{
    int i1 = left , i2 = mid + 1 , i3 = 0;
    while( i1 <= mid && i2 <= right )
    {
        if( a[i1] > a[i2] )
        {
            cnt+=mid-i1+1;
            temp[i3++] = a[i2++];
        }
        else
            temp[i3++] = a[i1++];
    }

    while( i1 <= mid )
        temp[i3++] = a[i1++];
    while( i2<= right)
        temp[i3++] = a[i2++];
    for( int i = 0 , j = left + i ; i < i3 ; i++ , j++ )
        a[j] = temp[i];
}

void mergeSort( int a[] , int left , int right )
{
    if( left + 1 > right )
        return;
    int mid = left + right >> 1;
    mergeSort( a , left , mid );
    mergeSort( a , mid+1 , right );
    merge_( a , left , mid , right );
}

int main()
{
    int num;
    while( scanf( "%d" , &num ) && num!=0 )
    {
        cnt = 0;
        for( int i = 0 ; i < num ; i++ )
            scanf( "%d" , &a[i] );
        mergeSort( a , 0 , num-1 );
        printf( "%lld\n" , cnt );
    }
    return 0;
}
