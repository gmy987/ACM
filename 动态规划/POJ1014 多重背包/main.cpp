#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int dp[120002];

int main()
{
    int a[7];
    int t = 0;
    while( scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6])!=EOF &&
           (a[1]!=0||a[2]!=0||a[3]!=0||a[4]!=0||a[5]!=0||a[6]!=0))
    {
        t++;
        int sum = 0,cnt = 0;
        int value[20002];
        for( int i = 1 ; i <= 6 ; i++ )
        {
            sum+=a[i]*i;
            for( int j = 1 ; j <= a[i] ; j*=2 )
            {
                value[++cnt] = j*i;
                a[i]-=j;
            }
            if(a[i]>0)
                value[++cnt] = a[i]*i;
        }
        memset(dp,0,sizeof(dp));
        if( sum % 2 )
        {
            printf("Collection #%d:\nCan't be divided.\n\n",t);
            continue;
        }
        else
            sum/=2;
        for( int i = 1 ; i <= cnt ; i++ )
            for( int j = sum ; j >= value[i] ; j-- )
                dp[j] = max(dp[j],dp[j-value[i]]+value[i]);
        if( dp[sum]==sum )
            printf("Collection #%d:\nCan be divided.\n\n",t);
        else
            printf("Collection #%d:\nCan't be divided.\n\n",t);
    }
    return 0;
}
