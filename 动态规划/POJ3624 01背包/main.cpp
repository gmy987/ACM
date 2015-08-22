#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int w[3500],d[3500];
        for( int i = 0 ; i < n ; i++ )
            scanf("%d%d",&w[i],&d[i]);
        int f[13000] = {0};
        for( int i = 0 ; i < n ; i++ )
            for( int j = m ; j >= w[i] ; j--  )
                f[j] = max(f[j] , f[j - w[i]]+d[i]);
        printf("%d\n",f[m]);
    }
}
