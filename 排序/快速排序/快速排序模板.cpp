#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
void quicksort( int *a , int low , int high )
{
    if(low<high)
    {
        int i = low , j = high , pivotloc = a[i];
        while( i < j )
        {
            while( i < j && a[j] >= pivotloc )
                j--;
            a[i] = a[j];
            while( i < j && a[i] <= pivotloc )
                i++;
            a[j] = a[i];
        }
        a[i] = pivotloc;
        quicksort(a,low,i-1);
        quicksort(a,i+1,high);
    }
}


int main()
{
    //length of a is 7
    quicksort(a,0,6);
    return 0;
}
