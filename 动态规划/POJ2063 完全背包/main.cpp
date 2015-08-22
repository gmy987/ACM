#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int dp[50000];
int main()
{
    int n;
    scanf("%d",&n);
    while( n-- )
    {
        int start,year,d;
        scanf("%d%d%d",&start,&year,&d);
        int value[15],interest[15];
        int temp = start;
        for( int i = 1 ; i <= d ; i++ )
        {
            scanf("%d%d",&value[i],&interest[i]);
            value[i]/=1000;
        }
        while(year--)
        {
            memset(dp , 0 ,sizeof(dp));
            start = temp/1000;
            for( int i = 1 ; i <= d ; i++ )
                for( int j = value[i] ; j<= start ; j++)
                    dp[j] = max(dp[j] , dp[j-value[i]]+interest[i]);
            temp+=dp[start];
        }
        printf("%d\n",temp);
    }
    return 0;
}
