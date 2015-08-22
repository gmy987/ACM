#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int t,total,year;
    int n;
    int value[15],interest[15];
    int dp[1500000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&total,&year,&n);
        for( int i = 0  ; i < n ; i++ )
        {
            scanf("%d%d",&value[i],&interest[i]);
            value[i]/=1000;
        }
        int temp = total;
        while( year-- )
        {
            for( int i = 0 ; i <= temp/1000 ; i++ )
                dp[i] = 0;
            for( int i = 0 ; i < n ; i++ )
                for( int j = value[i] ; j <= temp/1000 ; j++ )
                    dp[j] = max( dp[j] , dp[j-value[i]] + interest[i] );
            temp = dp[temp/1000]+temp;
        } 
        printf("%d\n",temp);
    }
    return 0;
}
