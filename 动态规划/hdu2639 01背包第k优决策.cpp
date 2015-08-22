#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;
int t,n,v,k;
int value[120],weight[120],dp[1200][32];
int a[32],b[32];

int main()
{
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d%d%d",&n,&v,&k);
            memset( dp , 0 , sizeof(dp) );
            for( int i = 0 ; i < n ; i++ )
                scanf("%d",&value[i]);
            for( int i = 0 ;i < n ; i++ )
                scanf("%d",&weight[i]);
            for( int i = 0 ; i < n ; i++ )
                for( int j = v ; j >= weight[i] ; j-- )
                {
                    int l,a,b,c;
                    for( l = 1 ; l <= k ; l++ )
                    {
                        A[l] = dp[j-weight[i]][l]+value[i];
                        B[l] = dp[j][l];
                    }
                    A[l] = -1 , B[l] = -1;
                    a=b=c=1;
                    while( c <= k && (A[a]!=-1||B[b]!=-1))
                    {
                        if(A[a] > B[b])
                            dp[j][c] = A[a++];
                        else
                            dp[j][c] = B[b++];
                        if( dp[j][c] != dp[j][c-1] )
                            c++;
                    }
                }
            printf("%d\n",dp[v][k]);
         }
    }
    return 0;
}
