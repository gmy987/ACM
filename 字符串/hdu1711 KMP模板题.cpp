#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int n,m;
int a[1000005],b[10005],nex[10005];
void findnext(const int p[],int next[] , int len )
{
    int q,k;
    next[0] = 0;
    for( q = 1 , k = 0 ; q < len ; q++  )
    {
        while( k > 0 && p[q] != p[k] )
            k = next[k-1];
        if( p[q] == p[k] )
            k++;
        next[q] = k;
    }
}
int kmp( const int t[] , const int p[] , int next[] )
{
    int i,q;
    findnext( p , next , m );
    for( int i = 0 , q = 0 ; i < n ; i++ )
    {
        while( q > 0 && p[q] != t[i] )
            q = next[q-1];
        if( p[q] == t[i] )
            q++;
        if( q == m )
            return i+2-m;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        for( int i = 0 ; i < m ; i++ )
            scanf("%d",&b[i]);
        printf("%d\n",kmp(a,b,nex));
    }
    return 0;
}
