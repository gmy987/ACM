#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int nex[400005];
char a[400005];
int ans[400005];
int m;
void findnext()
{
    int k,q;
    nex[0] = 0;
    for( k = 0 , q = 1 ; q < m ; q++ )
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
        m = strlen(a);
        findnext();
        int cnt = 0;
        ans[cnt++] = m;
        int tmp = m;
        while(nex[tmp-1]!=0)
        {
            ans[cnt++] = nex[tmp-1];
            tmp = nex[tmp-1];
        }
        printf("%d",ans[cnt-1]);
        for( int i = cnt-2 ; i >= 0 ; i--  )
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
