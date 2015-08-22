#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
char a[1000005],b[10005];
int nex[10005];
int cnt;
void makenext()
{
    int k,q;
    nex[0] = 0;
    for( k = 0 , q = 1; q < strlen(b) ; q++ )
    {
        while(k > 0 && b[q] != b[k])
            k = nex[k-1];
        if( b[q] == b[k] )
            k++;
        nex[q] = k;
    }
}
void kmp()
{
    makenext();
    int n = strlen(a);
    int m = strlen(b);
    int i , q;
    for( i = 0 , q = 0 ; i < n ; i++ )
    {
        while( q > 0 && b[q] != a[i] )
            q = nex[q-1];
        if( b[q] == a[i] )
            q++;
        if(q==m)
            cnt++;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cnt = 0;
        scanf("%s",b);
        scanf("%s",a);
        kmp();
        printf("%d\n",cnt);
    }
    return 0;
}
