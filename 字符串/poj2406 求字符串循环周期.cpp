#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
char a[1000005];
int nex[1000005];
int m;
void findnext()
{
    int k,q;
    nex[0] = 0;
    for( q = 1 , k = 0 ; q < m ; q++  )
    {
        while( k > 0 && a[q] != a[k] )
            k = nex[k-1];
        if( a[q] == a[k] )
            k++;
        nex[q] = k;
    }
}

int main()
{
    while(~scanf("%s",a))
    {
        if(a[0]=='.')
            break;
        m = strlen(a);
        findnext();
        if( m % ( m - nex[m-1] ) == 0 )
            printf("%d\n",m/(m-nex[m-1]));
        else
            printf("1\n");
    }
    return 0;
}
